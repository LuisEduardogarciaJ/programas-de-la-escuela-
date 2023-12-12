// 01/Septiembre/2021
//------------------------------------------------
//Ecuaciones de Difusión 3D para Multiples GPUs
//------------------------------------------------
//Lenguaje: Cuda C-MPI
//-------------------------------------------------
//Geometria: Cartesiana
//------------------------------------------------------
//Autor del codigo original: Julian T. Becerra Sagredo 
//-------------------------------------------------------
// Codigo escrito po Garcia Junquera Luis Eduardo 


//-------------------
//Librerias
//-------------------
#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

//-------------------
//Tamaño del bloque
//-------------------
#define TILE_I 8
#define TILE_J 8
#define TILE_k 8

//-------------------
//Precisión
//-------------------
#define Real double  

//-------------------
//Arreglos en el CPU
//-------------------
Real *t_host;
Real *t0_izq, *t0_der;
Real *t1_izq, *t0_der;

//-------------------
//Arreglos en el CPU
//-------------------
Real *t_data;
Real *t_data_old;
Real *t_izq, *t_der;

//-------------------
//Escalares globales
//-------------------
Real   dx,dy,dz,dp,dt,kcond;
int    ni,nj,nk,paso;

//-------------------
//Rutina de CUDA C
//-------------------
__global__void solveheat_kernel (int myid, int numprocs, int ni, int nj, int nk, Real kcond,
            Real dt, Real dx, Real dy, Real dz, Real *t_data, Real *data_old,
		Real *t_izq, Real *t_der);
		
//-------------------
//Rutina de C
//-------------------
void solveheat(int myid, int numprocs);  
void Imprimir(int myid, int paso);

//-------------------
//Programa principal
//-------------------
int main(int argc, char *argv[])
{
   int i;
   int totpoints; //total de puntos
   int totiter; //total de iteraciones
   
   //Procesos e Identificadores
   int numprocs, myid;   //numero de procesadores
   
   //Comenzar Procesos
   MPI_Init(&argc, &argv);
   
   //Cuantos Procesos en CPU
   MPI_Comm_size(MPI_COMM_WORLD,&numprocs); //regresar el numero total de procesadores
   
   //Mi número de procesos es myid
   MPI_Comm_rank(MPI_COMM_WORLD,&myid);  //VA A DAR EL RANGO
   
   //Maximo número de GPUs por nodo en CPU
   int maxgpu = 1;
   
   //Escoge GPU para mi proceso
   cudaSetDevice(myd%maxgpu);  //siempre da 0
   
   //Parametros de la simulación
   dt = 0.1f;
   dx = 0.1f;
   dy = 0.1f;
   dz = 0.1f;
   kcond = 0.01f;
   ni=128;
   nj=128;
   nk=32;
   totiter = 10000;
   totpoints = ni*nj*nk;
   
   
   printf("ni = %d\n", ni);
   printf("nj = %d\n", nj);
   printf("nk = %d\n", nk);
   printf("Numero de puntos = %d\n", totpoints);
   
   
   //Asigna la memoria en el CPU (host)
   t_host = (Real *)malloc (ni*nj*nk*sizeof(Real));
   t0_izq = (Real *)malloc (ni*nj*sizeof(Real));
   t0_der = (Real *)malloc (ni*nj*sizeof(Real));
   t1_izq = (Real *)malloc (ni*nj*sizeof(Real));
   t1_der = (Real *)malloc (ni*nj*sizeof(Real));
   
   
   //Asigna la memoria en el GPU (device)
   cudaMalloc((void **)&t_data, sizeof(Real)*ni*nj*nk);
   cudaMalloc((void **)&t_data_old, sizeof(Real)*ni*nj*nk);
   cudaMalloc((void **)&t_izq, sizeof(Real)*ni*nj);
   cudaMalloc((void **)&t_der, sizeof(Real)*ni*nj);
   
   
   // Valores iniciales del campo t
   for (i=0; i<totpoints; i++)
   {
   	t_host[1] = 0.f;
   }
   if (myid == 0)
   {
   	t_host[totpoints/2 - ni*nj/2] = 100000.f;
   }
   for (i=0; i<ni*nj; i++)
   {
   	t0_izq[i] = 0.f;
   	t0_der[i] = 0.f;
   	t1_izq[i] = 0.f;
   	t1_der[i] = 0.f;
   	
   }
   
   
   //Copia valores iniciales al GPU
   cudaMemcpy(t_data, t_host, sizeof(Real)*ni*nj*nk, cudaMemcpyHostToDevice);
   cudaMemcpy(t_izq, t0_izq, sizeof(Real)*ni*nj, cudaMemcpyHostToDevice);
   cudaMemcpy(t_der, t0_der, sizeof(Real)*ni*nj, cudaMemcpyHostToDevice);
   
   //Evolución temporal
   paso = 0;
   for (i=1; i<=totiter; i++)
   {
   	paso += 1;
   	solveheat(myid,numpeocs);
   	if (paso%10 == 0) printf ("Paso: %d/n", paso);
   	if (paso%1000 == 0)  Imprimir(myid,paso);       
   	
   }
  
  //Diagnóstico CUDA 	
  printf("CUDA: %s\n", cudaGetErrorString(cudaGetLastError()));       //Para revisar si tiene algun error
  
  
  //Finalizar procesos
  MPI_Finalize();
  return 0;
   
   
}		

/////////////////////////////////////////////////////////////////////

//----------------
//Rutina en C
//---------------
void solveheat(int myid, int numprocs)
{
	MPI_Status stat;
	
	//Copiar arreglo
	cudaMemcpy(t_data_old, t_data, sizeof(Real)*ni*nj*nk, cudaMemcpyDeviceToDevice);
	
	//Malla de paralelización
	dim3 grid = dim3(ni/TILE_I, nj/TILE_J, nk/TILE_K);
	dim3 block = dim3(TILE_I, TILE_J, TILE_K);
	
	
	//Ecuación de calor de CUDA
	solveheat_kernel<<<grid, block>>>(myid,numprocs,ni,nj,nk,kcond,dt,dx,dy,dz,t_data,t_data_old,t_izq,t_der);
	
	
	//Bajar datos
	cudaMemcpy(t0_izq,sizeof(Real)*ni*nj, cudaMemcpyDeviceToHost);    //Se va a pasar al CPU
	cudaMemcpy(t0_der,sizeof(Real)*ni*nj, cudaMemcpyDeviceToHost);
	
	
	//Identificación de vecinos
	int myidml = myid-1;
	int myidpl = myid + 1;
	if (myid == 0) myidml = numprocs - 1;
	if (myid == numprocs-1) myidpl = 0;
	
	if (myid == 0)
	{
	//Mandar mensaje
	MPI_Send(t0_der, ni*nj, MPI_DOUBLE, myidp1, 1, MPI_COMM_WORLD);
	//Recibir mensaje
	MPI_Recv(t1_izq, ni*nj, MPI_DOUBLE, myidm1, 1, MPI_COMM_WORLD, &stat);
	}else{
	//Recibir mensaje
	MPI_Recv(t1_izq, ni*nj, MPI_DOUBLE, myidm1, 1, MPI_COMM_WORLD, &stat);
	//Mandar mensaje
	MPI_Send(t0_der, ni*nj, MPI_DOUBLE, myidp1, 1, MPI_COMM_WORLD);
	}
	if(myid == 0){
	//Mandar mensaje
	MPI_Send(t0_izq, ni*nj, MPI_DOUBLE, myidm1, 0, MPI_COMM_WORLD);
	//Recibir mensaje
	MPI_Recv(t1_der, ni*nj, MPI_DOUBLE, myidp1, 0, MPI_COMM_WORLD, &stat);
	}else{
	//Recibir mensaje
	MPI_Recv(t1_der, ni*nj, MPI_DOUBLE, myidp1, 0, MPI_COMM_WORLD, &stat);
	//Mandar mensaje
	MPI_Send(t0_izq, ni*nj, MPI_DOUBLE, myidm1, 0, MPI_COMM_WORLD);	
	}
	
	
	//Subir a GPU
	cudaMemcpy(t_izq, t1_izq, sizeof(Real)*ni*nj, cudaMemcpyHostTo Device);
	cudaMemcpy(t_der, t1_der, sizeof(Real)*ni*nj, cudaMemcpyHostTo Device);
	
	
}

//___________________
//Rutina en CUDA C
//-------------------
__global__void solveheat_kernel (int myid, int numprocs, int ni, int nj, int nk, Real kcond, Real dt, Real dx, Real dy, Real dz, Real *t_data, Real *data_old, Real *t_izq, Real t_der)
{
	int i, i, k, i2d, i2d2, i2d3, i2d4, i2d5, i2d6, i2d7;
	Real told, tnow,tipl,timl,tjpl,tjml,tkpl,tkml;
	
	i = blockIdx.x*TITLE_I + threadIdx.x;
	j = blockIdx.y*TITLE_j + threadIdx.y;
	k = blockIdx.z*TITLE_k + threadIdx.z;
	
	//Indices de vecinos
	i2d = i + j*nj + k*ni*nj;
      i2d2 = (i+1) + (j)*ni + k*ni*nj;
      i2d3 = (i-1) + (j)*ni + k*ni*nj;
      i2d4 = (i) + (j+1)*ni + k*ni*nj;
      i2d5 = (i) + (j-1)*ni + k*ni*nj;
      i2d6 = (i) + (j)*ni + (k+1)*ni*nj;
      i2d7 = (i) + (j)*ni + (k-1)*ni*nj;
      
      //Fronteras
      if (i ==ni-1)  i2d2= 0 + (j)*ni + k*ni*nj;
      if (i == 0)    i2d3= ni-1 + (j)*ni + k*ni*nj;
      if (j ==nj-1)  i2d4= i + k*ni*nj;
      if (i == 0)    i2d5= i + (nj-1)*ni + k*ni*nj;
      
      
      //Datos de vecinos
      told = t_data_old[i2d];
      tipl = t_data_old[i2d2];
      timl = t_data_old[i2d3];
      tjpl = t_data_old[i2d4];
      tjml = t_data_old[i2d5];
      tkpl = t_data_old[i2d6];
      tkml = t_data_old[i2d7];
      
      //Datos recibidos de otros procesos
      if (k == 0)    tkml = t_izq[i+j*ni];
	if (k == nk-1) tkpl = t_der[i+j*ni];
	
	//Ecuacion de difución de calor
	tnow = told + dt*kcond*((tipl-2.0f*told+timl)/(dx*dx)
	                      +(tjpl-2.0f*told+tjml)/(dy*dy)
				    +(tkpl-2.0f*told+tkml)/(dz*dz));
	
	//Funete de calor fija
	
	int totpoints = ni*nj*nk;
	if (myid == 0){ if (i2d == totpoints/2 - ni*nj/2 - ni/2)tnow = 100000.f;}
	
	//Guardar resultado
	t_data[i2d] = tnow;
	
	//Guardar frontera a comunicar
	if (k == 0)
	{
		t_izq[i+j*ni] = tnow;
	}
	if (k == nk-1){
		t_der[i+j*ni] = tnow;
	}
	  
}

//---------------------
//Guardar resultados en formato VTK
//----------------------
void Imprimir(int myid, int paso)
{
	char s_pars[40];
	int i, j, k;
	FILE *fp;
	
	//Bajar datos a CPU
	cudaMemcpy(t_host,t_data,ni*nj*nk*sizeof(Real),cudaMemcpyDeviceToHost);
	
	//Archivo de salida por proceso
	sprintf(s_pars, "data%d-%d.vtk",myid,paso);
	fp = fopen (s_pars, "w");
	
	//Formato VTK de salida para malla estructurada
	fprintf(fp, "# vtk DataFile Version 2.0\n");
	fprintf(fp, "Sample rectilinear griid\n");
	fprintf(fp, "ASCII\n");
	fprintf(fp, "DATASET RECTILINEAR_GRID\n");
	fprintf(fp, "DIMENSIONS %d %d %d\n", ni, nj, nk);
	fprintf(fp, "X_COORDINATES %d float\n" ni);
	for (i=0;i<ni;++i)
	    fprintf(fp, "%d ", i);
	fprintf(fp, "\n");
	fprintf(fp, "Y_COORDINATES %d float\n", nk);
	for (j=0;j<nj;++j)    
	    fprintf(fp, "%d " , j);
	fprintf(fp, "\n");
	fprintf(fp, "Z_COORDINATES %d float\n", nk);
	for (k=0;k<nk;k++)
	    fprintf(fp, "%d ", k+myid*(nk)); 
	fprintf(fp, "\n");    
	fprintf(fp, "POINT_DATA %d\n", (ni)*(nj)*(nk));
	fprintf(fp, "SCALARS temp float\n");
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (k == 0; k<nk; k+=1)
      for (j == 0; j<nj; j+=1)
	for (i == 0; i<ni; i+=1)
	  fprintf(fp, "%e\n", t_host[i+ni*j+k*ni*nj]);
	}
	
	fclose(fp);

}

///////////////////////////////////////////////////////////////////////////////77









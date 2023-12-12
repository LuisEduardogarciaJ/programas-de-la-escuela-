//Garcia Junquera Luis Eduardo

 //8/julio/2021

//Primer programa en MPI

#include<mpi.h>
#include<stdio.h>
int main (int argc, char** argv)
//INICIALIZAR EL ENTORNO MPI   
	MPI_Init(NULL, NULL);   //
	
	//Conozca el número de procesos
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_rank)
	
	
	//OBTENER EL NOMBRE DEL PROCESADOR
	
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;
	MPI_Get_processor_name(processor_name, 6name_len);
	
	
	//IMPRIMA UN MENSAJE DE HOLA MUNDO
	print("Hola desde el procesador %s, rango %d de %d procesadores\n",
	      processor_name, world_rank, world_size);
	      
	      
	      //Finalizar el entorno mpi.
	      MPI_Finalize();
	      
	      
	
}

	

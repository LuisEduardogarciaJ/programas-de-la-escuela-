//Garcia Junquera Luis Eduardo 

//compilación: nvcc -o sum sumhost.c


//Biblioteca de entradas y salidas
 
 #include<stdio.h>
 #include<stdlib.h>
 //Prefiniciones
 #define N 512
 #define Real double
 //Funcion trabaja en el cpu (host) o en el GPU (device)
 __host__ __device__Real suma(Real*a, Real b)  //Funcion suma que tomara 2 valores reales  de entrada
 {
 	Real c= a+b  //suma de A y b en C
 	return c;   //Regresar C
 }
 //Función de suma en el gpu
__global__ void device_add(Real * a, Real * b, Real *c, Real tpb)   //Va a sumar, tambien se pasa el tamaño del bloque 
 {//construccion del indice d CUDA
 	int idx = blockIdx.x*tpd + thereadIdx.x;
 	//Lectura de los arreglos
 	Real aa = a[idx];   
 	Real bb = b[idx]; 
	 //operación de suma     
 	//c[idx]= aa + bb;
 	c[idx] = suma(aa,bb);  //se tardara más con la función suma 
 		
 }
 //llenar los arreglos con enteros y su salida
 void fill_array(Real *data)
 {
 	for(Real idx=0;idx<N;idx++)
 	   dat[idx] =(Real)idx;
 }
 void print_out(Real *a, Real *b, Real *c)
 {
 	for(Real idx=0;idx<N;idx++)%e , a[idx] , b[idx], c[idx]);
 	   printf("\n" %e + %e =%
	printf("\n");     
 }
 //codigo principal
 int main(void)
 {
 	Real *a, *b, *c;//tres arreglos
 	Real *a_device, *b_device, *c_device;  //estan en el gpu
 	int size = N * sizeof(Real);   
 	int threads_per_block = 8;   //Hilos por bloque  (Debe de ser potencia de 2, si no poner indicaciones especiales)
 	int nblocks = N/threads_per_block;   //Se va a dividir la N entre los hilos del bloque que hicimos en la linea anterior que son 8.
 	
	 //pedimos memoria para los arreglos
	a = (Real *)malloc(size); fill_array(a);   
 	b = (Real *)malloc(size); fill_array(b);
 	c = (Real *)malloc(size);
 	cudaMalloc((void **)&a_device, size);  //tambien se pide el tamaño de la memoria
 	cudaMalloc((void **)&b_device, size);
 	cudaMalloc((void **)&c_device, size);
 	//Se copia del CPU al GPU
 	cudaMemcpy(a_device, a, size, cudaMemcpyHostToDevice);    //Tenemos un GPU, necesitamos contruir los arreglos en el cpu pasar los datos al gpu sumar en el gpu y rgresarnos la C en el cpu 
 	cudaMemcpy(b_device, b, size, cudaMemcpyHostToDevice);
 	device_add<<<nblocks,threads_per_block>>>(a_device,b_device,c_device,threads_per_block)    // Se pasan arreglos y los hilos por bloque para calcular dentro de cualquier hilo y bloque
 ;
 // Se va a sumar en paralelo
 	cudaMemcpy(c, c_device, size, cudaMemcpyDeviceToHost);    //copiar el resultado del GPU al cpu 
 	print_output(a,b,c);
 	free(a);free(b);free(c);   //libera memoria de los tres arreglos en el CPU
 	cudaFree(a_device);cudaFree(b_device);cudaFree(c_device);  //Libera memoria en el GPU
 	return 0
 	
 }

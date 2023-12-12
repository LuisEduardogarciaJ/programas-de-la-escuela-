 //Programa básico en C

//Garcia Junquera Luis Eduardo 

//compilación: nvcc -o sum sumhost.c


//Biblioteca de entradas y salidas

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Prefiniciones
#define N 512
#define Real float   //double

//-----------------------------
//Función de suma de arreglos
//c = a + b
void host_add(Real *a, Real *b, Real *c)
{
	for(int idx=0;idx<N ;idx++)
	   c[idx] = a[idx] + b[idx];
}

//------------------------------
//Llenado de arreglos 
//-----------------------
void fill_array(Real *data)
{
for(int idx=0;idx<N;idx++)
    data[idx] = (Real)idx;	
}
//-------------------
//Salida de datos 
//--------------------------
void print_output(Real *a, Real *b, Real *c)
{
	for(int idx=0;idx<N;idx++)
	    printf("\n %e + %e = %e", a[idx], b[idx], c[idx]);
	printf("\n");    
}

//--------------
//Función principal main
//-------------
int main (void)
//Arreglo de enteros
{
	Real *a, *b, *c;	
//Tamaño de memoria de arreglos
	
	int size =N * sizeof(Real);
//Petición y llenado de memoria para los arreglos	
	a = (Real *)malloc(size); fill_array(a);
	b = (Real *)malloc(size); fill_array(b);
	c = (Real *)malloc(size);


//Lamado de la función suma
host_add(a,b,c);

//Escritura del resultado en pantalla
print_output(a,b,c);

//Liberación de memoria
free(a); free(b); free(c);

//Exito del programa
return 0;
}



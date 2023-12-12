 //Programa b�sico en C

//Garcia Junquera Luis Eduardo 

//compilaci�n: nvcc -o sum sumhost.c


//Biblioteca de entradas y salidas

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Prefiniciones
#define N 512
#define Real float   //double

//-----------------------------
//Funci�n de suma de arreglos
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
//Funci�n principal main
//-------------
int main (void)
//Arreglo de enteros
{
	Real *a, *b, *c;	
//Tama�o de memoria de arreglos
	
	int size =N * sizeof(Real);
//Petici�n y llenado de memoria para los arreglos	
	a = (Real *)malloc(size); fill_array(a);
	b = (Real *)malloc(size); fill_array(b);
	c = (Real *)malloc(size);


//Lamado de la funci�n suma
host_add(a,b,c);

//Escritura del resultado en pantalla
print_output(a,b,c);

//Liberaci�n de memoria
free(a); free(b); free(c);

//Exito del programa
return 0;
}



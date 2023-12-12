#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int matriz[50][50], filas, columnas,i,j;
	printf("Escribe el numero de filas:"); //piden datos de filas y columnas
	scanf("%i",&filas);
	printf("Escribe el numero de columnas:");
	scanf("%i",&columnas);
	
	printf("\n\n");
	
	for(i=0;i<filas;i++)
	{
		for(j=0;j<columnas;j++)
		{
			printf("escribe un numero matriz [%i][%i]:",i+1,j+1);
			scanf("%i",&matriz[i][j]);
			
		}
	}
	
	printf("n\n");
	printf("\nEl resultado de la matriz es: \n");
	for(i=0;i<filas;i++)
	{
		for (j=0;j<columnas;j++){
			printf("%i",matriz[i][j]);
			
		
		}
		printf("\n");
	}
	
	return 0;
	
	
}

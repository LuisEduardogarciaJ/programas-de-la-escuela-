//Garcia Junquera Luis Eduardo

//Bibliotecas entradas y salidas
#include "mpi.h"
#include "string.h"
#include "stdio.h"
//linea de comandos, este codigo ya manda mensajes 
int main(int argc, char*argv[])
{
	int sizechar = 20;  //el caracter mide 20
	char message[sizechar];
	int myrank, numprocs;   //se tienen dos enteros  
	MPI_Status status;  //dice en donde anda el estado de MPI                                     
	Mpi_Init(&argc, &argv);   
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);//dice cuantos procesos hay en total
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);   //nos dice cual es el rango, y nos dice tambien el numero de proceso
	//SI ES EL 0 HACE ESTO
	if(myrank == 0)   //si el rango es el 0
	{
		strcpy(message, "Hello, there");    //mando el mensaje "Hello there"
		for (int i = 1; i < numprocs; i++)
		//strlen manda el mensaje (se le suma uno porque tiene un caracter nulo)
		  MPI_Send(message, strlen(message)+1, MPI_CHAR, i, 99, MPI_COMM_WORLD);   //mana el mensaje y se manda a los demas procesadores que no sea yo
		  //MPI_CHAR nos dice que tipo de dato es,se lo pasamos al I y tiene un numero de guia 99 y MPI_COMM_WORLD es el ambiente de comunicación 
	}
	//SI NO ES EL 0 HACE ESTO
	else if (myrank ! = 0)     //si no es igual a 0 entonces recibira el mensaje que mando el 0
	{
		MPI_Recv(message,sizechar, MPI_CHAR, 0, 99, MPI_COMM_WORLD, &status);  //se recibira el la variable mensaje,sera del proceso 0 y de la guia 99 y status es para ser monitoreo de la instruccion
		printf("received : %s\n", message);   //
		
	}
	//finaliza el programa
	MPI_Finalize();
	return 0;
	
}

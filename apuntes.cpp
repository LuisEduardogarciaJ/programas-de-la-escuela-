#include <iostream>  //Abrir una biblioteca.
#include <string>
using namespace std; //Utilizar todas las biblio est�ndar. 
int main() //<--- Es una funci�n. Un programa es una FUNCI�N principal.
{
	string /Tipo de variable: cadena, enteros, decimales/ name ; /*Declaraci�n de una variable. 
	Es importante, que se reserve el espacio dentro de la memoria RAM.*/
	int age; //Si guardamos la edad en string, me la va a guardar pero la va a reconocer como un caracter, no como un "n�mero".
		

	cout<<"What's your name? ";
	cin>>name; //Ingreso de datos por medio del teclado. 
	cout<<"How old are you? ";
	cin>>age;
	cout/C= car�cter; salidad de caracter. Flujo de salida.    La terminal es el monitor/<</* Arroja al flujo*/
	"Hello, world. My name is "/*Las comillas hacen referencia a texto, y si no tiene, 
	significa que hace referencia auna instrucci�n con un nombre que el sistema reconoce.*/
	<<name /Imprimir� el valor asignado a Name en la primera instrucci�n/<<", and I'm "<<age<< endl/Salto de l�nea/; 

}

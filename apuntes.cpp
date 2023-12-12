#include <iostream>  //Abrir una biblioteca.
#include <string>
using namespace std; //Utilizar todas las biblio estándar. 
int main() //<--- Es una función. Un programa es una FUNCIÓN principal.
{
	string /Tipo de variable: cadena, enteros, decimales/ name ; /*Declaración de una variable. 
	Es importante, que se reserve el espacio dentro de la memoria RAM.*/
	int age; //Si guardamos la edad en string, me la va a guardar pero la va a reconocer como un caracter, no como un "número".
		

	cout<<"What's your name? ";
	cin>>name; //Ingreso de datos por medio del teclado. 
	cout<<"How old are you? ";
	cin>>age;
	cout/C= carácter; salidad de caracter. Flujo de salida.    La terminal es el monitor/<</* Arroja al flujo*/
	"Hello, world. My name is "/*Las comillas hacen referencia a texto, y si no tiene, 
	significa que hace referencia auna instrucción con un nombre que el sistema reconoce.*/
	<<name /Imprimirá el valor asignado a Name en la primera instrucción/<<", and I'm "<<age<< endl/Salto de línea/; 

}

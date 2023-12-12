#include <iostream>
#include <complex>
using namespace std;

template< typename T > // cualquier tipo posible
void intercambio (T& a, T& b)

{ 
   T s =a;
   a=b;
   b=s;
}
int main ()
{
	complex<double>z(1,2);
	complex<double>w(2.2,3.3);                //si se borra esto ------------debe ser del mismo tipo
	
	cout<<"z="<<z<<endl;            
	cout<<"w="<<w<<endl;                  
	intercambio (z,w);
	cout<<"After swapping"<<endl;
	cout<<"z="<<z<<endl;
	cout<<"w="<<w<<endl;
	
}
//funcion generica de tipo double int o string

//se intercambiaran los valores 


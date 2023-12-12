#include<complex>
#include<iostream>
using namespace std;
int main()
{
	complex<double> z(1,1); //declarar un numero complejo en la memoria
	complex <double> z2= (complex<double>) (3);//forzar al 3 que se de como un complejo
	complex <double> w=z+z2;
	cout<<w<<endl;
	cout<<z2/w<<endl;
	cout<<sqrt(z2)<<endl;
	
}

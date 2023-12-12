#include<iostream>
using namespace std;
int main ()
{
	int opcion;
	double centimetros,pulgadas;
	
	cout<<"Ingrese una opcion:"<<endl;
	cout<<"1.centimetro a pulgada" <<endl;
	cout<<"2.pulgada a centimetros"<<endl;
	cin>>opcion;
	
	switch (opcion)
	{
		case 1:
			cout<<"---Centimetros a pulgadas---"<<endl;
			cout<<" Ingrese la cantidad de centimetros a convertir"<<endl;
			cin>>centimetros;
			pulgadas=centimetros * 0.393701;
			cout << centimetros <<" centimetros equivalen a: "<< pulgadas <<"__pulgadas."<< endl;
			break;
		case 2:
		    cout<<"---Pulgadas a centimetros---"<<endl;
		    cout<<" Ingrese la cantidad de pulgadas a convertir"<<endl;
			cin>>pulgadas;
			centimetros=pulgadas * 2.54;
			cout<<pulgadas<<" pulgadas equivalen a: "<< centimetros <<"__centimetros."<< endl;
	            break;
				
	}
	return 0; 
 }

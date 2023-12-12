 #include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main ()
{
	ifstream fin ("Polinomio.txt"); 
	string polinomio="polinomio";
	fin>>polinomio; 
	cout<<"El_polinomio_es_=_"<<polinomio<<endl;
	
}
	

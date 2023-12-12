 #include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main ()
{
	ifstream fin ("Matriz.txt"); 
	string matriz="matriz";
	fin>>matriz; 
	cout<<"La_matriz_es_=_" <<matriz<<endl;
	
}
	
	

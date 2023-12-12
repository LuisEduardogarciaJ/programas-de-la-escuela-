#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ofstream fout ("Polinomio.txt"); 
	cout<<"Da un polinomio_:_";
	string polinomio="polinomio";
	cin>>polinomio;
	fout<<polinomio<<endl;
}




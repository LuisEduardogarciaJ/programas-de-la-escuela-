 #include<iostream>
#include<fstream>
using namespace std;
int main ()
{
	ifstream fin ("myint.txt"); //fin<-----myint.txt
	int i=0;
	fin>>i; //fin----->i
	//por lo tanto i<--------fin <--------myint.txt
	cout<<"i_=_"<<i<<endl;
	
}

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream fout ("myInt.txt"); //fout ->myInt.txt
	cout<<"An_int_please_:_";
	int i =0;
	cin>>i;
	fout<<i<<endl;  //i and new linw--->fout
	//hence i and a new line --->fout---->myInt.txt
}

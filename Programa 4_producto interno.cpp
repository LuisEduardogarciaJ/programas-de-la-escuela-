#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
float v1[3],v2[3], p=0;
int i;

cout<<"Valor para el primer vector"<<endl;
cin>>v1[0]>>v1[1]>>v1[2];

cout<<"Valor para el segundo vector"<<endl;
cin>>v2[0]>>v2[1]>>v2[2];

for(i=0;i<3;i++)
{
	p=p+v1[i]+v2[i];
}
cout<<"El producto interno es: "<<p<<endl;


return 0;
	
}


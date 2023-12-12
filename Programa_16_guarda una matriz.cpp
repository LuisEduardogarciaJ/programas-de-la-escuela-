#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main ()
{
ofstream fout ("matriz.txt"); 
int mat[3][3];

for(int i=0; i<3; i++) //se piden los datos que tendran la matriz
{
    for(int j=0; j<3; j++)
   {
   cin>>mat[i][i];

   }

}
cout<<"\n";
for(int i=0;i<3;i++)   //se imprimen los datos que le asignen a la matriz
{
	for(int j=0;j<3;j++)
	{
		cout<<mat[i][j]<<endl;
	}
	cout<<"\n";
}


	
return 0;
}

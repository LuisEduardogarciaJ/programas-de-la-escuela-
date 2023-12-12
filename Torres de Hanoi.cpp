#include<iostream>
using namespace std ;
void Moves ( int Disks,char Orig ,char Aux,char Dest)
{
if ( Disks == 1 )
cout<<Orig<<"==>"<<Dest<<endl;
else
{
Moves ( Disks -1,Orig , Dest , Aux ) ;
cout<<Orig<<"==>"<<Dest<<endl ;
Moves ( Disks -1,Aux , Orig , Dest ) ;
}
}
int main ( )
{
int disks =0;
cout<<" Disks _=_" ;
cin>>disks ;
Moves ( disks,"Origen","Auxiliar","Destino") ;
cout<<"End"<<endl ;
}

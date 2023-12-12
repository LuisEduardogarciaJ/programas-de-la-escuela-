#include<iostream>
using namespace std ;
void swap ( int& a , int& b )
{
int s = a ;
a = b ;
b = s ;
}
int main ( )
{
int i =2;
int j =3;
cout<<" i _=_"<<i<<endl ;
cout<<" j _=_"<<j<<endl ;
swap ( i , j ) ;
cout<<" After _ swapping "<<endl ;
cout<<" i _=_"<<i<<endl ;
cout<<" j _=_"<<j<<endl ;
}


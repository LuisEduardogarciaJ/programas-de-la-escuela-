#include<iostream>
using namespace std ;
int gcd (int n ,int m )
{
if (m==0)
return n ;
else
return gcd (m, n%m) ;
}
int main ( )
{
int i =24;
int j =102;
cout<<"gcd ( _"<<i<<", _"<<j<<"_ ) _=_"<<gdc( i,j )<<endl;
}


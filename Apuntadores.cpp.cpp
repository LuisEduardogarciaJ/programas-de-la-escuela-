#include<iostream>
using namespace std ;
int main ( )
{
int i = 5 ;
cout<<i<<endl ; // 5
int * ip = &i; // i p p oi n t s to i ( i p -> i )
cout<<ip<<endl ;
int j = * ip ;
cout<<j<<endl ; // 5
double d = 0.5 ;
cout<<d<<endl ; // 0.5
double* dp = &d ; // dp p oi n t s to d ( dp -> p )
cout<<dp<<endl ;
cout<<*ip<<endl ; // 0.5
int ** ipp = &ip ; // ipp p oi n t s to i p ( ipp -> i p )
// then ( ipp -> i p -> i )

cout<<ipp<<endl ;
cout <<**ipp<<endl ; // 5
}

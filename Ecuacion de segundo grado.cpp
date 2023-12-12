#include<iostream>
#include<cmath>
using namespace std ;
int main ( )
{
double a , b , c ;
cout<<" Solving_ ax^2+bx+c=0,_a_non_ zero "<<endl ;
cout<<"_a_=_" ;
cin>>a ;
if ( a!=0 )
{
cout<<"_b_=_" ;
cin>>b ;
cout<<" _c_=_" ;
cin>>c ;
double disc=b*b-4*a* c ;
if ( disc<0 )
cout<<"No real solutions"<<endl ;
else
if ( disc==0 )
{
cout<<"x_=_"<<-b/ (2* a)<<endl ;
cout<<" only _ solution "<<endl ;
}
else
{
cout<<" x1_=_"<<(-b+sqrt ( disc ) ) / ( 2 * a)<<endl ;
cout<<" x2_=_"<<(-b-sqrt ( disc ) ) / ( 2 * a)<<endl ;
}
}
else
{
cout<<"a_ can ’t _ be? zero "<<endl ;
cout<<"no_ c a l c u l a t i o n _ realized "<<endl ;
}


cout<<" end"<<endl ;
}

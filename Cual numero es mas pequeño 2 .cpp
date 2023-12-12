#include<iostream>
using namespace std ;
double min ( double x , double y )
{
if ( x <= y )
return x ;
return y ;
}
double min ( double* v , unsigned int dim )
{
double currentMin = v [ 0 ] ;
for ( int i =1; i<dim ; i++ )
if ( v [ i ] < currentMin )
currentMin = v [ i ] ;
return currentMin ;
}
int main ( )
{
const int dim = 5 ;
double v [ dim ] = {10 ,3 , -2.7182 , -3.1416 ,0};
cout<<min ( v , dim)<<"_ i s _ the _ sm all e r . "<<endl;
}


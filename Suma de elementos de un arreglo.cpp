#include<iostream>
using namespace std ;
double sumS ( double* v , int dim ) // Suma secuencial
{
double sum = v [ 0 ] ;
for ( int i =1; i<dim ; i++ )
sum+=v [ i ] ;
return sum ;
}
double sumR( double* v , int dim ) // suma recursiva
{
if ( dim==1 )
return v [ 0 ] ;
else
return v [ dim-1]+sumR( v , dim -1);
}
int main ( )
{
const int dim=5;
double v [ dim ] = {2 , 3 , 5 , 7 , 11};
cout<<"Sum_ ( _ sequential  _ ) _ : _"<<sumS ( v , dim)<<endl ;
cout<<"Sum_ ( _ recursive _ ) __ : _"<<sumR( v , dim)<<endl ;
}


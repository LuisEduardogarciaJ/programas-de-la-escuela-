#include<iostream>
using namespace std ;
struct Vector
{
int dim ;
double* v ;
} ;
double sum ( Vector V)
{
double sum = V. v [ 0 ] ;
for ( int i =1; i<V. dim ; i++ )
sum+=V. v [ i ] ;
return sum ;
}
int main ( )
{
const int i =5;
double a [ i ] = {10 , 11 , 18 , 117 , 11};
Vector V;
V. dim=i ;
V. v=a ;
cout<<"Sum_ : _"<<sum (V)<<endl;
}


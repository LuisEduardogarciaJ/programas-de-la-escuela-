#include<iostream>
using namespace std ;
int main ( )
{
double v [7] = {2,3,5,7,11,13,17 }; // v [ 0 ] = 2 . . . v [6]=17
int * a [ 100 ] ; // Matriz de puntero a int
cout<<" ( _" ; // Se imprime V como un vector
for ( int i =0; i <6; i++ ) // para impresiones casi duraderas
cout<<v [ i ]<<" , _" ;
cout<<v[6]<<"_ ) "<<endl ; // ultimo
const int rows =3;
const int cols =3;
double M[rows] [cols] ;
for ( int r =0; r<rows ; r++ ) // Identidad matriz
for ( int c =0; c<cols ; c++ )
M[ r ] [ c ] = r==c ; // 
for ( int r =0; r<rows ; r++ ) //Se imprime m como una matriz
{
for ( int c =0; c<cols ; c++ )
cout <<M[r][c]<<"_";
cout<<endl;
}
}

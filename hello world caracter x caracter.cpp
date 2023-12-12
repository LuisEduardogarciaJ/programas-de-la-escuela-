#include<iostream>
using namespace std ;
int main ( )
{
const int n = 14;
char s[n] = "Hola_mundo" ;
// u si n g op e ra to r [ ] ( s u b s c r i p t i n g ) and o t h e r s
for ( int i =0; i<n ; i++ )
cout<<s [ i ] ;
cout<<endl ;
// using operator * ( d e r ef e r e n c e ) and o thers
for ( char* p=s ; *p!=0; p++ )
cout<<*p ;
cout<<endl ;
}

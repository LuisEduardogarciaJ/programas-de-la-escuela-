#include<iostream>
using namespace std ;
struct Rational
{
int Num;
int Den ;
Rational ( int n = 0 , int d =1 ) ;
} ;
Rational::Rational ( int n , int d )
{
Num=n ;
Den=d ;
}
Rational operator *( Rational q1 , Rational q2 )
{
Rational q ( q1 .Num*q2 .Num, q1 . Den*q2 . Den ) ;
return q ;
}
ostream& operator<<( ostream& s , Rational q )
{
s<<q .Num<<"/"<<q .Den ;
return s ;
}
istream& operator>>( istream& s , Rational& q )
{
scanf ( " %d/ %d" , &q .Num, &q . Den ) ;
return s ;
}
int main ( )


{
Rational q1 ;
Rational q2 ( 2 ) ;
Rational q3 ( 5 , 7 ) ;
cout<<q1<<endl ;
cout<<q2<<endl ;
cout<<q3<<endl ;
cout<<q2*q3<<endl ;
cout<<"A_ rational _ ( _n/d_ ) please _ : _" ;
cin>>q1 ;
cout<<" the _ square _ of _"<<q1<<"_ i s _"<<q1 *q1<<endl ;
}

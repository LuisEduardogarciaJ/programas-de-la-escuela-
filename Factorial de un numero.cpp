using namespace std ;
#include<iostream>
int factS ( int n )
{
int fact =1;
for ( int i =2; i<=n ; i++ )
fact *=i ;
return fact ;
}
int factR ( int n )
{
if ( n < 2 )
return 1 ;
else
return n * factR ( n-1);
}
int main ( )
{
int n ;
cout<<"_n_=_" ;
cin>>n ;
cout<<"_"<<n<<" ! _=_"<<factS ( n)<<endl ;
cout<<"_"<<n<<" ! _=_"<<factR ( n)<<endl ;


}


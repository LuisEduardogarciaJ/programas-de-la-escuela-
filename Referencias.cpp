#include<iostream>
using namespace std ;
int main ( )
{
int i = 5 ;
cout<<i<<endl ; // 5
int& ir = i ; // i r names th e o b j e c t i
int j = ir ;
cout<<j<<endl ; // 5
ir ++;
cout<<i<<endl ; // 6
cout<<j<<endl; //5
double d = 0.5
cout<<d<<endl;  //0.5
double* dp = &d;  //dp point to d (dp-p)
cout<<*dp<<endl;
double& x =*dp;  //x names what dp points
cout<<x<<endl;  //0.5
x-=2
cout<<d<<endl;   //1.5
}


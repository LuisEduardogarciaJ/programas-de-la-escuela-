#include<iostream>
#include<cstdlib>
using namespace std ;
int main ( )
{
int* ip =(int*)malloc(sizeof(int));
if ( ip == 0 )
 {
   cout<<"not_enough_memory"<<endl;
   exit(1);
}
*ip=5
free (ip); 
}



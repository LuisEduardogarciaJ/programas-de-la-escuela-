#include <iostream>
#include<cstdlib>
using namespace std;
bool primo (int n)
{
	for (int p=2; p<n; ++p)
	    if (n%p==0)
	       return false;
	return true;       
}
int main (int argc, char** argv)
{
	int n;
	cout<<"Da un número:\n";
	cin>>n;
	if(primo(n))
	   cout<<n<<"es primo\n___";
	else
	   cout<<n<<"no es primo___";
	   system ("pause");
	   return EXIT_SUCCESS;   
}

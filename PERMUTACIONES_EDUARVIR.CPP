#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int n;   //numero de objetos a permutar
	cin>>n     
	
	p=1;
	for(int k=0; k<n; ++k)
	   p*=n;                   //p=n elevado a la n (n**n)
	for (int r=0;r<p;++r)   //vamos sobre {0..n*n}
	{
		int x=r;
		int bits=0;
		while (x>0)   //obtener la expancion n-aria
		     {
		     	res=x%n;
		     	bits |=1 <<(x%n); //elementos presentes
		     	x/=n;
		     	
			 }
		if(bits==(1<<n)-1)  //estan todos presentes?
		      {
		      	x=r;
		      	for (int i=0;i<n;++i)           //aseguramos escribir n digitos
				{
					cout<<x%n<<'';
					
				   }  
				    }	 
			 
	}
	            return EXIT_SUCCESS;
	            
}

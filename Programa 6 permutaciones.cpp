#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	long int n;		// numero de objetos a permutar
	cin >> n;    

    long int p= 1, q=0;
    for (int k=0; k<n; ++k)
		p*= n;				 //   p= n elevado a la n (n**n).

    for (int k=0; k<n; ++k)
		q= n*q + k;

    for (long int r=q; r<p; ++r)   //  vamos sobre {0.. n**n}
	{
     	long int x= r;
		long int bits= 0;
		for (int i=0; i<n; ++i)     //   obtener la expansión n-aria...
			{
			 bits |=  1 << (x%n);   //  elementos presentes.
			 x/= n;               
			}
	    if (bits == (1<<n)-1)     // estan todos presentes?
			{
			 x= r;
			 for (int i=0; i<n; ++i)   // asegurémonos escribir n dígitos
				{
				 cout << x%n << ' ';
				 x/= n;
				} 
			 cout << endl;
			}
	}
	return EXIT_SUCCESS;
}


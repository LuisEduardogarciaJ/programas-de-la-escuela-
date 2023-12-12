// Autor:  Eduardo Viruena Silva
#include <iostream>
#include <cstdlib>:

#define DEBUG
#define ESPANOL
//#define ENGLISH

using namespace std;

bool primo(int n)
{
	#ifdef DEBUG
	cerr <<"DEBUG: entre a la funcion primo\n";
	#endif
	for (int p=2; p<n; ++p)
		if (n%p==0){
			#ifdef DEBUG
			cerr << "DEBUG: parece que " << p << " divide a " << n << " y debe regresar false\n";					
			#endif
			return false;
		}
 	#ifdef DEBUG
	cerr << "DEBUG: termino el for y ningun entero dividio a n\n";
	#endif
	return true;		
}

int main(int argc, char** argv) 
{
	int n;
#ifdef ESPANOL
	cout << "Dar un numero:\n";
#endif
#ifdef ENGLISH
	cout << "Enter a number:\n";
#endif
	cin >> n;
	if (primo(n))
		#ifdef ESPANOL
		cout << n << " es primo\n";
		#endif
		#ifdef ENGLISH
		cout << n << " is a prime number\n";
		#endif
	else
		#ifdef ESPANOL
		cout << n << " no es primo\n";
	    #endif
		#ifdef ENGLISH
		cout << n << " is not a prime number\n";
	    #endif
	    
	return EXIT_SUCCESS;
}

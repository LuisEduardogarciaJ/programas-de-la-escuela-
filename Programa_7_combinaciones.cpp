#include <iostream>
using namespace std;


int factorial(int n);
int combinaciones(int y, int z);
int comb_recursivo(int y, int z);


int main(void) {
   int n, m;
   cout << "Introduzca el numero de objetos del conjunto (n): " << endl;
   cin >> n;
   cout << "Introduzca el numero de objetos a elegir (m): " << endl;
   cin >> m;

   cout << endl << "Las combinaciones de " << n << " objetos tomados " <<
           m << " a " << m << " son ";
           cout << combinaciones(n,m) << endl << endl;
           cout << comb_recursivo(n,m) << endl << endl;
   system("pause");

}


int factorial(int n) {
   int resultado=1, i;
   if (n>1) {
        for (i=2;i<=n;i++) {
            resultado*=i;  
        }
   }
   return resultado;
}

int combinaciones(int y, int z) {
  return (factorial(y) / (factorial(z) * factorial(y-z)));
}


int comb_recursivo(int y, int z) {
  int r;
  if (y==z || z==0) r=1;
  else r=(y*comb_recursivo(y-1,z-1))/z;
  
  
  return 0;
}


#include <iostream>
#include <cmath>
 
using namespace std;
 
float evalua(float a[], int n, float x); // prototipo
 
int main()
{
   int n;   // # de coeficientes
 
   cout << "Ingrese el # de coeficientes n = ";
   cin >> n;
 
   float a[n]; // Arreglo de coeficientes
   float x;
 
   for (int i = 0; i < n; i++) {
      cout << "Coeficiente a[" << i << "] = ";
      cin >> a[i];
   }
 
   cout << "Ingrese un valor para x = ";
   cin >> x;
 
   float valor_numerico = evalua(a, n, x);
   cout << "\nValor numerico p(" << x << ") = " << valor_numerico << endl;
 
   cin.get();
   cin.get();
   return 0;
}
 
float evalua(float a[], int n, float x) {
   // Cálculo del valor numérico de P(x)
   float p = 0.0;
   for (int i = 0; i < n; i++) {
      p = p + a[i] * pow(x, i);
   }
 
   return p;
}


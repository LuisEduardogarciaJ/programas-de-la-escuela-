#include <iostream>

using namespace std;

// maximo comun divisor de x,y
int
mcd (int x, int y)
{
     if (y == 0)
	  return x;
     else
	  return mcd (y, x % y);
}

//-----------------------------------------------------------------
// Aqui somos implementadores de la clase CRacional:
//    1) decidimos el interfaz (public)
//    2) decidimos la representacion (private)
//    3) implementamos los metodos
//-----------------------------------------------------------------

class CRacional
{

public:	 // interfaz

     CRacional ();
     // precondicion: d != 0
     CRacional (int n, int d);
     ~CRacional ();

     int numerador () const;
     int denominador () const;
     double a_real () const;
     // precondicion: d != 0
     void asigna (int n, int d);
     void suma (const CRacional & a, const CRacional & b);
     void resta (const CRacional & a, const CRacional & b);
     void producto (const CRacional & a, const CRacional & b);
     // precondicion: b != 0
     void cociente (const CRacional & a, const CRacional & b);

private: // implementacion

     // atributos

     int num, den;  //  num / dem

     // los racionales se almacenan "normalizados":
     //
     //   1) la fraccion num/dem se reduce (e.g.  12 / 8 se reduce a  3 / 2)
     //   2) el signo afecta solo al numerador (e.g. 5 / -13 se reduce a  -5 / 13)

     // metodo privado (el usuario no puede utilizarlo)

     void normalizar ();
};

//-------------------------------------------------------
// implementacion de los metodos de la clase racional
//-------------------------------------------------------

CRacional::CRacional ()
{
     num = 0;
     den = 1;
}

// precondicion: d != 0
CRacional::CRacional (const int n, const int d)
{
     if (d != 0)
     {
	  num = n;
	  den = d;
	  normalizar ();
     }
}

CRacional::~CRacional ()
{
     // nada...
}

// metodo privado
void
CRacional::normalizar ()
{
     int maxcd;

     // normaliza el signo

     if (den < 0)
     {
	  den = -den;
	  num = -num;
     }

     // reduce la fraccion

     maxcd = mcd (abs (num ), abs (den));
     num = num / maxcd;
     den = den / maxcd;
}

int
CRacional::numerador () const
{
     return num;
}

int
CRacional::denominador () const
{
     return den;
}

double
CRacional::a_real () const
{
     return double (num) / den;
}

// precondicion: d != 0
void
CRacional::asigna (int n, int d)
{
     if (d != 0)
     {
	  num = n;
	  den = d;
	  normalizar ();
     }
}

void
CRacional::suma (const CRacional & a, const CRacional & b)
{
     num = a.num * b.den + b.num * a.den;
     den = a.den * b.den;
     normalizar ();
}

void
CRacional::resta (const CRacional & a, const CRacional & b)
{
     num = a.num * b.den - b.num * a.den;
     den = a.den * b.den;
     normalizar ();
}

void
CRacional::producto (const CRacional & a, const CRacional & b)
{
     num = a.num * b.num;
     den = a.den * b.den;
     normalizar ();
}

// precondicion: b != 0
void
CRacional::cociente (const CRacional & a, const CRacional & b)
{
     CRacional temp;

     // usamos un temporal por si el resultado coincide con alguno
     // de los operandos; por ejemplo:  x.cociente(x,y)

     if (b.num != 0)
     {
	  temp.num = a.num * b.den;
	  temp.den = a.den * b.num;
	  temp.normalizar ();

	  num = temp.num;
	  den = temp.den;
     }
}

//-------- fin de la implementacion --------

//-----------------------------------------------------------------
// Aqui somos usuarios de la clase CRacional. Solo podemos:
//    1) emplear metodos del interfaz (public)
//    2) pasar racionales como parametro (por referencia, &)
//    3) asignar racionales (=)
//-----------------------------------------------------------------

// aplicacion ejemplo: una calculadora racional simple

void
lee (const char *mensaje, CRacional & r)
{
     int a, b;

     cout << mensaje;
     cin >> a;
     cin >> b;
     r.asigna (a, b);
}

void
escribe (const char *mensaje, const CRacional & r)
{
     cout << mensaje;
     cout << r.numerador () << "/" << r.denominador () << "= " << r.
	  a_real () << endl;
}

int
main ()
{

     CRacional x, y, z;

     cout << "Prueba de la clase racional" << endl;
     cout << "(x=0 para acabar)" << endl << endl;

     do
     {

	  lee ("valor de x?\n", x);
	  escribe ("x= ", x);

	  lee ("valor de y?\n", y);
	  escribe ("y= ", y);

	  cout << endl;

	  z.suma (x, y);
	  escribe ("x+y= ", z);

	  z.resta (x, y);
	  escribe ("x-y= ", z);

	  z.producto (x, y);
	  escribe ("x*y= ", z);

	  z.cociente (x, y);
	  escribe ("x/y= ", z);


     }
     while (x.a_real () != 0.0);

}


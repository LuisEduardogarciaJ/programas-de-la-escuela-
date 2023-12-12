#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Pila {
	private:
		float *stk;
		int tope;
		int name;
	public:
		Pila(int n, int c);
		Pila(void);
		~Pila(void);
		void push(float x);
		float pop(void);
		bool empty(void);
		void show(void);
		int  N(void)  { return name; };

		Pila& operator = (const Pila& P);
};

Pila::Pila(int n, int c)
{
	stk= new float[n];
	tope= 0;
	name= c;
}

Pila::Pila(void)
{
}

Pila& Pila::operator= (const Pila& P)
{
	tope= P.tope;
	name= P.name;
	stk = new float[tope];
	for (int k=0; k<tope; ++k)
		stk[k]= P.stk[k];
	return *this;
}



Pila::~Pila(void)
{
	delete [] stk;
}

void Pila::push(float x)
{
	stk[tope++]= x;
}

float Pila::pop(void)
{
	return stk[--tope];
}
	
bool Pila::empty(void)
{
	return tope==0;
}

void Pila::show(void)
{
	cout << "Pila " << name << ":  ";
	for (int k=0; k<tope; ++k)
		cout << stk[k] << ' ';	
	cout << endl;
}

void print( Pila& a, Pila& b, Pila& c )
{
	Pila P[3];
	P[a.N()]= a;
	P[b.N()]= b;
	P[c.N()]= c;
		
	P[0].show();			// se muestran las pilas
	P[1].show();
	P[2].show();
	cout << endl;
}

void hanoi( int n, Pila& a, Pila& b, Pila& c)
{
	if (n>0) {
		hanoi(n-1, a, c, b); // se mueven n-1 discos de a -> c

		b.push(a.pop());	// se mueven 1 discos de a -> b
		print(a,b,c);	

		cout << endl;

		hanoi(n-1, c, b, a);	// se mueven n-1 discos de c -> a	
	}
}

int main()
{
	int n;
	cin >> n;
	Pila x(n, 0);
	Pila y(n, 1);
	Pila z(n, 2);

	for (int k=n; k>0; --k)
		x.push(k);

	x.show();
	y.show();
	z.show();

	cout << endl;

	hanoi(n, x, y, z);
	return EXIT_SUCCESS;
}










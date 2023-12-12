#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Pila {
	private:
		float *stk;
		int tope;
	public:
		Pila(int n);
		~Pila(void);
		void push(float x);
		float pop(void);
		bool empty(void);
		void add(void);	
		void sub(void);	
		void mul(void);	
		void div(void);	
		void mod(void);	
		void root(void);
		void swap(void);
		void dup(void);
		void show(void);
};

Pila::Pila(int n)
{
	stk= new float[n];
	tope= 0;
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

void Pila::add(void)
{
	float y= pop();
	float x= pop();
	push(x+y);
	show();
}

void Pila::sub(void)
{
	float y= pop();
	float x= pop();
	push(x-y);
	show();
}

void Pila::mul(void)
{
	float y= pop();
	float x= pop();
	push(x*y);
	show();
}

void Pila::div(void)
{
	float y= pop();
	float x= pop();
	push(x/y);
	show();
}

void Pila::mod(void)
{
	float y= pop();
	float x= pop();
	push(fmod(x,y));
	show();
}

void Pila::root(void)
{
	float x= pop();
	push(sqrt(x));
	show();
}

void Pila::swap(void)
{
	float x= pop();
	float y= pop();
	push(x);
	push(y);
}

void Pila::dup(void)
{
	float x= pop();
	push(x);
	push(x);
	show();
}

void Pila::show(void)
{
	cout << "Pila:  ";
	for (int k=0; k<tope; ++k)
		cout << stk[k] << ' ';	
	cout << endl;
}

int main()
{
	Pila p(20);
	float x;

	for (;;)
		switch( cin.peek() ) {
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
			case '8': case '9':
				cin >> x;
				p.push(x);
				p.show();
				break;

			case '+': cin.get();
				p.add();
				break;

			case '-': cin.get();
				p.sub();
				break;

			case '*': cin.get();
				p.mul();
				break;

			case '/': cin.get();
				p.div();
				break;

			case 's': cin.get();
				p.swap();
				break;
				
			case 'd': cin.get();
				p.dup();
				break;
				
			case '%': cin.get();
				p.mod();
				break;
				
			case 'r': cin.get();
				p.root();
				break;
				
			case 'Q': 
			case 'q': 
				return EXIT_SUCCESS;

			default:
				cin.get();
				break;
		}
			
}









  

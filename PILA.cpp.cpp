#include<iostream>
using namespace std;

//template<typename t>      //para que t fuera lo que sea
struct Node
{
	int data;                       //data puede ser cualquier cosa
	Node* down ;
	Node (int d = 0, Node* p = 0){data=d;}
};
class Stack
{
	public:
	Node* top;
	void Push(Node* p );                              //apile un nodo
	Node* Pop();                                 // quita uno de la pila
	Stack(){top=0; }                                  //asignarla a top 0 un punto  
	void Print ();                              //definio print         
};
void Stack::Print()
{
	Node*nodeToPrint = top;          //nodo a implimir se imprimira primero lo que esta en top
	while( nodeToPrint )
	  {
		cout<<nodeToPrint->data<<endl;
		nodeToPrint=nodeToPrint->down;//queseimprimatoprintydespueselsegundotoprint
	  }
}

void Stack::Push(Node*p)              //empuja el nodo a la pila  //p es la direccion de un nodo
{
	p->down=top;    //p es un apuntador que los lleva a nodos con componenete down
	top=p;             //top apunta a lo que apunta (p)--los dos oauntan a lo mismo
	
}
Node* Stack::Pop()   //pop es ir a la pila y desligarlo 
{
	Node* s =top;        //salvar al top actual va  ser cambiado por lo que esta abajo de top
	top=top->down;          
	s ->down= 0;               //sirve para esta flecha va a ese nodo y down va a nada                   //flecha operador de acceso---p-->down accede a la componente down de la clase que está en el código.
	return s;
	
}
int main ()
{
	Stack stack;         //creo una nueva pila y se hace nuevos nodos
	stack.Push(new Node);
	stack.Push(new Node(5));
	stack.Push(new Node(3)); 
    stack.Push(new Node(7));
	stack.Print();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	cout<<"--------------"<<endl;
	stack.Print ();     //imprima los elementos de la stack
	stack.Pop();
	cout<<"--------------"<<endl;
	stack.Print();//saco un dato y luego vuelve a imprimir
	stack.Pop(); //esto es un error
	cout<<"--------------"<<endl;
	stack.Print();
}


#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* down;
  Node( int d = 0, Node* p = 0 ){ data = d; }
};

class Stack
{
public:
  Node* top;
  void Push( Node* p );
  Node* Pop();
  Stack(){ top = 0; }
  void Print();
};

void Stack::Print()
{
  Node* nodeToPrint = top;
  while( nodeToPrint )
    {
      cout<<nodeToPrint->data<<endl;
      nodeToPrint=nodeToPrint->down;
    }
}

void Stack::Push( Node* p )
{
  p->down = top;
  top=p;
}

Node* Stack::Pop()
{
  Node* s = top;
  if( top )
    {
      top = top->down;
      s->down = 0;
    }
  return s;
}

int main()
{
  Stack stack;
  stack.Push(new Node(8));
  stack.Push(new Node(-1));
  stack.Push(new Node(3));
  stack.Print();
  Node* p = stack.Pop();
  Node* q = stack.Pop();
  Node* r = stack.Pop();
  Node* s = stack.Pop();
  cout<<" p = "<<p<<endl;
  cout<<" q = "<<q<<endl;
  cout<<" r = "<<r<<endl;
  cout<<" s = "<<s<<endl;
  cout<<size_t(p)-size_t(q)<<endl;
}

#include <cstdlib>
#include <iostream>
 
using namespace std;
 
int main(int argc, char *argv[])
{
    double pro1,pro2,pro3,a,b,c,d;
    cout<<" Producto 1 : ";
    cin>>pro1;
    cout<<" Producto 2 : ";
    cin>>pro2;
    cout<<" Producto 3 : ";
    cin>>pro3;

    a=pro1+pro2+pro3;
    cout<<" Subtotal de la compra es : "<<a<<endl;
    b=a*.15;
    cout<<" El iva es : "<<b<<endl;
    c=b+a;
    cout<<" Total : "<<c<<endl;
    a=a+b;
    cout<<" El descuento : "<<c*.20<<endl;
    a=a-(c*.20);
    cout<<" El total final es : "<<a<<endl;
    cout<<" Con cuanto pagas : ";
    cin>>d;
    cout<<" Tu cambio es : "<<d-a<<endl;
    cout<<" Gracias por su compra ."<<endl;
    system("PAUSE");
    
return 0;
}


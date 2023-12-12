#include<iostream>
#include <tgmath.h>

using namespace std;
int main ()
{
	double a, b, c, disc, x1, x2, srt;
	cout<<"Solve the next equation ax2+bx+c"<<endl;
	cout<<"a= ";
	cin>>a;
	if (a==0)
		cout<<"A can't be 0";
	
	else 
	
	{
		cout<<"b= ";
		cin>>b;
		cout<<"c= ";	
		cin>>c;
		disc=(b*b)-(4*a*c);
		srt=sqrt (disc);
		if (srt==0){
		
		x1=((-1*b)/2*a);
		cout<<"There is only one posible answer"<<endl<<"x= "<<x1;}
		else {
		if (srt>0){
		
		x1=(-b+disc)/(2*a);
		x2=(-b-disc)/(2*a);
		cout<<"There are 2 possible answers"<<endl<<"x1 is "<<x1<<
		endl<<"x2 is "<<x2;}
		else {

			cout<<"The answer is not a Real number. It would be sqrt (-1) = i";}
		}
	}
}

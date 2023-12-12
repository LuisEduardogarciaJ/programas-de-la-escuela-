#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a, n;
	cin>>n;
	a=((pow((1+sqrt(5)),n))-(pow((1-sqrt(5)),n)))/(sqrt(5)*pow(2,n));
cout<<a;
}

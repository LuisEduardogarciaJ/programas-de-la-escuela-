#include <conio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

class complejo{

private:

	double r,i;

public:

	complejo(){
		r=0.0;
		i=0.0;
	}

	complejo(double real, double imaginario){
		r=real;
		i=imaginario;
	}

	void setRealImaginario(double real,double imaginario){
		r=real;
		i=imaginario;
	}
	
	
	double getReal(){
		return r;
	}
	double getImaginario(){
		return i;
	}

void imprimeRectangular(){
		if(r!=0&&i!=0){
			cout <<"\n" << r << "," << i << "i";
		}
		else if(r==0&&i!=0){
			cout <<"\n" << i <<"i";
		}
		else if(r!=0&&i==0){
			cout <<"\n" << r;
		}
		else{
			cout <<"\n0";
		}
}

	double sumaRectangular(double real1, double imaginario1, double real2, double imaginario2){
		r= real1 + real2;
		i= imaginario1 + imaginario2;
		return r,i;
	}

};

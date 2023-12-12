#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

using namespace std;

struct factor{
    float potencia[2];
    float coeficiente;
    char literal[2];
}e1[100],e2[100];

void pedirDatos(factor [],char [],int);
void imprimir(factor [],int);
void sumar(factor [], factor[], int, char []);
void resta(factor [], factor[], int, char []);

int main(){
    int factores;
    char literales[2];

    cout<<"\n\nFactor maximo de los polinomios -> "; cin>>factores;
    cout<<"\n\nPrimera variable ha usar -> "; cin>>literales[0];
    cout<<"\n\nSegunda variable ha usar -> "; cin>>literales[1];

    system("cls");

    cout<<"\n\nPrimer polinomio\n";
    
    pedirDatos(e1,literales,factores);

    cout<<"\n\nSegundo polinomio\n";
    
    pedirDatos(e2,literales,factores);

    // imprimiendolos 

    system("cls");

    cout<<"\n\nPrimer polinomio\n";

    imprimir(e1,factores);

    cout<<"\n\nSegundo polinomio\n";

    imprimir(e2,factores);

    sumar(e1,e2,factores,literales);

    resta(e1,e2,factores,literales);

    getch();
    return 0;
}

void pedirDatos(factor e[],char v[],int n){
    for(int i=0;i<n;i++){
        fflush(stdin);
        cout<<"\nFactor #"<<n-i;
        cout<<"\nCoeficiente -> "; cin>>e[i].coeficiente;
        cout<<"\nPotencia de "<<v[0]<<" -> "; cin>>e[i].potencia[0];
        cout<<"\nPotencia de "<<v[1]<<" -> "; cin>>e[i].potencia[1];
        e[i].literal[0] = v[0];
        e[i].literal[1] = v[1];
    }
}

void imprimir(factor e[], int n){
    fflush(stdin);
    for(int i=0;i<n;i++){
        // coeficiente 
        if(e[i].coeficiente > 0 && i == 0){
            cout<<e[i].coeficiente;
            if(e[i].potencia[0] != 0){
            cout<<"(";
            cout<<e[i].literal[0];
            cout<<"^"<<e[i].potencia[0];
            cout<<")";
            }
            if(e[i].potencia[1] != 0){
                cout<<"(";
                cout<<e[i].literal[1];
                cout<<"^"<<e[i].potencia[1];
                cout<<")";
            }
        }
        else if(e[i].coeficiente > 0){
            cout<<"+"<<e[i].coeficiente;
            if(e[i].potencia[0] != 0){
            cout<<"(";
            cout<<e[i].literal[0];
            cout<<"^"<<e[i].potencia[0];
            cout<<")";
            }
            if(e[i].potencia[1] != 0){
                cout<<"(";
                cout<<e[i].literal[1];
                cout<<"^"<<e[i].potencia[1];
                cout<<")";
            }
        }
        else if(e[i].coeficiente < 0){
            cout<<e[i].coeficiente;
        } 
    }
}

void sumar(factor e1[], factor e2[], int n, char variables[]){
    factor sum[100];

    for(int i=0;i<n;i++){
        //fflush(stdin);
        if((e1[i].potencia[0] == e2[i].potencia[0]) && (e1[i].potencia[1] == e2[i].potencia[1])){
            sum[i].coeficiente = e1[i].coeficiente + e2[i].coeficiente;
            sum[i].potencia[0] = e1[i].potencia[0];
            sum[i].potencia[1] = e1[i].potencia[1];
            sum[i].literal[0] = e1[i].literal[0];
            sum[i].literal[1] = e1[i].literal[1];
        }
        else{
            // el primer argumento
            sum[i].coeficiente = e1[i].coeficiente;
            sum[i].potencia[0] = e1[i].potencia[0];
            sum[i].potencia[1] = e1[i].potencia[1];
            sum[i].literal[0] = e1[i].literal[0];
            sum[i].literal[1] = e1[i].literal[1];

            // el segundo argumento 

            n++;

            sum[i+1].coeficiente = e2[i].coeficiente;
            sum[i+1].potencia[0] = e2[i].potencia[0];
            sum[i+1].potencia[1] = e2[i].potencia[1];
            sum[i+1].literal[0] = e2[i].literal[0];
            sum[i+1].literal[1] = e2[i].literal[1];
            i++;
        }
    }

    cout<<"\n\nSuma -> ";

    imprimir(sum,n);
}

void resta(factor e1[], factor e2[], int n, char variables[]){
    factor res[100];

    for(int i=0;i<n;i++){
        //fflush(stdin);
        if((e1[i].potencia[0] == e2[i].potencia[0]) && (e1[i].potencia[1] == e2[i].potencia[1])){
            res[i].coeficiente = e1[i].coeficiente - e2[i].coeficiente;
            res[i].potencia[0] = e1[i].potencia[0];
            res[i].potencia[1] = e1[i].potencia[1];
            res[i].literal[0] = e1[i].literal[0];
            res[i].literal[1] = e1[i].literal[1];
        }
        else{
            // el primer argumento
            res[i].coeficiente = e1[i].coeficiente;
            res[i].potencia[0] = e1[i].potencia[0];
            res[i].potencia[1] = e1[i].potencia[1];
            res[i].literal[0] = e1[i].literal[0];
            res[i].literal[1] = e1[i].literal[1];

            // el segundo argumento 

            n++;

            res[i+1].coeficiente = e2[i].coeficiente;
            res[i+1].potencia[0] = e2[i].potencia[0];
            res[i+1].potencia[1] = e2[i].potencia[1];
            res[i+1].literal[0] = e2[i].literal[0];
            res[i+1].literal[1] = e2[i].literal[1];
            i++;
        }
    }

    cout<<"\n\nResta -> ";

    imprimir(res,n);
}

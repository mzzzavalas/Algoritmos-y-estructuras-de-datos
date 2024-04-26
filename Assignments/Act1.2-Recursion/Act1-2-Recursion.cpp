//Mauricio Zavala Sánchez
//A00837332
//ITC
#include <iostream>
using namespace std;

int sumIterative(int n){
    int sum =0;
    for (int i=1; i<=n; i++){
        sum = sum +i;
    }
    return sum;
}


int sumRecursive(int n){
    if(n>1){
        return n + sumRecursive(n-1);
    } else {
        return 1;
    }
}

int sumFormula(int n){
    return n*(n+1)/2;
}

int fibonacciIterative(int n){
    if (n==1 || n==2){
        return 1;
    } else {
        int f1=1;
        int f2=2;
        for (int i=3; i<n; i++){
            int aux =f2;
            f2 =f2 + f1;
            f1 = aux;
        }
        return f2;
    }
}

int fibonacciRecursive(int n){
    if (n>2) {
        return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
    } else{
        return 1;
    }
}

int bacteriasIterative(int days) {
    int bacterias = 1;
    for (int i=1; 1<=days; i++) {
        bacterias=bacterias*(1+1.44);
    }
    return bacterias;
}

int bacteriasRecursive(int days){
    if (days>0){
        return bacteriasRecursive(days-1)*(1+1.44);
    } else {
        return 1;
    }
}

float investmentIterative(float balance, int months) {
    for (int i=1; i<=months; i++){
        balance = balance*(1 + 18.75/100);
    }
    return balance;
}

float investmentRecursive(float balance, int months) {    
    if (months>0){
        return investmentRecursive(balance, months-1)*(1+18.75/100);
    } else {
        return balance;
    }
}

double powIterative(int n, int y){
    double result = 1;
    for (int i=1; i<=y; i++){
        result = result*n;
    }
    return result;
}

double powerRecursive(int n, int y){
    if (y>0){
        return powerRecursive(n, y-1)*n;
    } else {
        return 1;
    }
}

int main() {
    cout<<"La suma iterativa de 1 al 5 es: "<<sumIterative(5)<<endl;
    cout<<"La suma recursiva de 1 al 5 es: "<<sumRecursive(5)<<endl;
    cout<<"La suma directa de 1 al 5 es: "<<sumFormula(5)<<endl;
    cout<<"El numero de la secuencia 4 de fibbionacci iterativo es: "<<fibonacciIterative(4)<<endl;
    cout<<"El numero de la secuencia 4 de fibbionacci recursivo es: "<<fibonacciRecursive(4)<<endl;
    //cout<<"Bacterias en 6 dias: "<<bacteriasIterative(6)<<endl;
    cout<<"Bacterias en 6 dias: "<<bacteriasRecursive(6)<<endl;
    cout<<"Saldo en 10 meses en: "<<investmentIterative(1000, 10)<<endl;
    cout<<"Saldo en 10 meses en: "<<investmentRecursive(1000, 10)<<endl;
    cout<<"El resultado de 5 elevado a la 2 es : "<<powIterative(5,2)<<endl;
    cout<<"El resultado de 5 elevado a la 2 es : "<<powerRecursive(5,2)<<endl;

}
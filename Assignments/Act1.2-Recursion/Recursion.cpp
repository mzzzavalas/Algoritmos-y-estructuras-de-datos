#include <iostream>
using namespace std;

int factorialIterative(int n){
    int factorial =1;
    for (int i=2; i<=n; i++){
        factorial=factorial *i;
    }
    return factorial;
}

// Recursion 
int factorial(int n) {
    if (n>0){
        return n*factorial(n-1);
    } else{
        return 1;
    }
}

int main() {
    cout<<"El factorial de 5 es: "<<factorial(5)<<endl;

    return 0;
}
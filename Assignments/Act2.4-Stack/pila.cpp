#include <iostream>
using namespace std;
#include "Stack.h"


int main(){

    Stack<string> pila;

    pila.push("Chancla");
    pila.print();
    pila.push("Vaso");
    pila.print();
    pila.push("Jarra");
    pila.print();
    try{
        pila.pop();
        pila.print();
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    try{
        cout<<"El ultimo elemento es: '"<<pila.top()<<"' "<<endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    



return 0;
}
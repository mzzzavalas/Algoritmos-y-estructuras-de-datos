#include <iostream>
using namespace std;
#include "Queue.h"


int main(){

    Queue<string> fila;
    cout << "Tamaño de la lista: " << fila.getSize() << endl;
    fila.push("Chancla");
    fila.print();
    fila.push("Sombrero");
    fila.print();
    fila.push("Mochila");
    fila.print();
    try{
        fila.pop();
        fila.print();
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    try{
        cout<<"El primer elemento es: '"<<fila.front()<<"' "<<endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }



return 0;
}
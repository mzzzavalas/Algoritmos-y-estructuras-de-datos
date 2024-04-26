//Mauricio Zavala Sánchez
//A00837332
//ITCs
#include <iostream>
#include "Stack.h"
using namespace std;

int main(){

    Stack<string> pila; //Declarar la lista inicialmente vacia

    int opcion;
    do{

        cout << "\nMENU:" << endl;
        cout << "1. Agregar un elemento al Stack." << endl;
        cout << "2. Borrar el ultimo elemento agregado al Stack y leer el valor." << endl;
        cout << "3. Leer el valor del ultimo elemento agregado al Stack." << endl;
        cout << "4. Salir." << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string elemento;
                cout << "Ingrese el elemento a agregar al Stack: ";
                cin >> elemento;
                pila.push(elemento);
                pila.print();
                break;
            }
            case 2: {
                try{
                pila.pop();
                pila.print();
                } catch (out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3:{
                try{
            
                    cout<<"El ultimo elemento en la pila es: '"<<pila.top()<<"' "<<endl;
                } catch (out_of_range& e) {
                    cout << e.what() << endl;
                }
            }
            case 4: {
                pila.print();
                cout << "Saliendo del programa." << endl;
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
                break;
            }
        }
    } while (opcion != 4);

    return 0;
}
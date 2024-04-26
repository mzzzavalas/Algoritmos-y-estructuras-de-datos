//Mauricio Zavala Sánchez
//A00837332
//ITCs
#include <iostream>
#include "Queue.h"
using namespace std;

int main(){

    Queue<string> fila; //Declarar la lista inicialmente vacia

    int opcion;
    do{

        cout << "\nMENU:" << endl;
        cout << "1. Agregar un elemento al Queue." << endl;
        cout << "2. Borrar el primer elemento agregado al Queue y leer el valor." << endl;
        cout << "3. Leer el valor del primer elemento agregado al Queue." << endl;
        cout << "4. Salir." << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string elemento;
                cout << "Ingrese el elemento a agregar al Queue: ";
                cin >> elemento;
                fila.push(elemento);
                fila.print();
                break;
            }
            case 2: {
                try{
                fila.pop();
                fila.print();
                } catch (out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3:{
                try{
            
                    cout<<"El primer elemento en la fila es: '"<<fila.front()<<"' "<<endl;
                } catch (out_of_range& e) {
                    cout << e.what() << endl;
                }
            }
            case 4: {
                fila.print();
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
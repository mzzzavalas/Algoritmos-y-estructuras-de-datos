//Mauricio Zavala Sánchez
//A00837332
//ITCs
#include <iostream>
#include <cstdlib> // Para generar números aleatorios
#include <ctime>   // Para la semilla del generador aleatorio
#include "LinkedList.h"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0))); // Inicializar semilla aleatoria

    LinkedList<int> lista; // Declarar la lista inicialmente vacía

    int tipoDato;
    cout << "Elija el tipo de dato para la lista:" << endl;
    cout << "1. Enteros" << endl;
    cout << "2. Dobles" << endl;
    cin >> tipoDato;

    int opcion;
    do {
        cout << "\nMENU:" << endl;
        cout << "1. Agregar un elemento al principio de la lista." << endl;
        cout << "2. Agregar un elemento al final de la lista." << endl;
        cout << "3. Insertar un elemento a la derecha del índice dado." << endl;
        cout << "4. Borrar un elemento dado de la lista." << endl;
        cout << "5. Borrar un elemento en una posición de la lista." << endl;
        cout << "6. Obtener el elemento de una posición dada de la lista." << endl;
        cout << "7. Actualizar un elemento dado de la lista." << endl;
        cout << "8. Actualizar un elemento en una posición dada de la lista." << endl;
        cout << "9. Encontrar un elemento dado en la lista." << endl;
        cout << "10. Obtener el elemento de una posición de la lista (operador [])." << endl;
        cout << "11. Actualizar el elemento de una posición de la lista (operador [])." << endl;
        cout << "12. Igualar una lista con los datos de otra lista (operador =)." << endl;
        cout << "13. Salir." << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int elemento;
                cout << "Ingrese el elemento a agregar al principio de la lista: ";
                cin >> elemento;
                lista.addFirst(elemento);
                break;
            }
            case 2: {
                int elemento;
                cout << "Ingrese el elemento a agregar al final de la lista: ";
                cin >> elemento;
                lista.addLast(elemento);
                break;
            }
            case 3: {
                int indice, elemento;
                cout << "Ingrese el índice donde desea insertar el elemento: ";
                cin >> indice;
                cout << "Ingrese el elemento a insertar: ";
                cin >> elemento;
                try {
                    lista.insert(indice, elemento);
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 4: {
                int elemento;
                cout << "Ingrese el elemento que desea borrar de la lista: ";
                cin >> elemento;
                if (lista.deleteData(elemento)) {
                    cout << "Elemento eliminado correctamente." << endl;
                } else {
                    cout << "Elemento no encontrado en la lista." << endl;
                }
                break;
            }
            case 5: {
                int indice;
                cout << "Ingrese el índice del elemento que desea borrar: ";
                cin >> indice;
                if (lista.deleteAt(indice)) {
                    cout << "Elemento en la posición " << indice << " eliminado correctamente." << endl;
                } else {
                    cout << "Índice fuera de rango." << endl;
                }
                break;
            }
            case 6: {
                int indice;
                cout << "Ingrese el índice del elemento que desea obtener: ";
                cin >> indice;
                try {
                    int elemento = lista.getData(indice);
                    cout << "Elemento en la posición " << indice << ": " << elemento << endl;
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 7: {
                int elemento, nuevoElemento;
                cout << "Ingrese el elemento que desea actualizar: ";
                cin >> elemento;
                cout << "Ingrese el nuevo elemento: ";
                cin >> nuevoElemento;
                try {
                    lista.updateData(elemento, nuevoElemento);
                    cout << "Elemento actualizado correctamente." << endl;
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 8: {
                int indice, nuevoElemento;
                cout << "Ingrese el índice del elemento que desea actualizar: ";
                cin >> indice;
                cout << "Ingrese el nuevo elemento: ";
                cin >> nuevoElemento;
                try {
                    lista.updateAt(indice, nuevoElemento);
                    cout << "Elemento en la posición " << indice << " actualizado correctamente." << endl;
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 9: {
                int elemento;
                cout << "Ingrese el elemento que desea encontrar en la lista: ";
                cin >> elemento;
                int indice = lista.findData(elemento);
                if (indice != -1) {
                    cout << "Elemento encontrado en la posición " << indice << "." << endl;
                } else {
                    cout << "Elemento no encontrado en la lista." << endl;
                }
                break;
            }
            case 10: {
                int indice;
                cout << "Ingrese el índice del elemento que desea obtener (usando operador []): ";
                cin >> indice;
                try {
                    int elemento = lista[indice];
                    cout << "Elemento en la posición " << indice << ": " << elemento << endl;
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 11: {
                int indice, nuevoElemento;
                cout << "Ingrese el índice del elemento que desea actualizar (usando operador []): ";
                cin >> indice;
                cout << "Ingrese el nuevo elemento: ";
                cin >> nuevoElemento;
                try {
                    lista[indice] = nuevoElemento;
                    cout << "Elemento en la posición " << indice << " actualizado correctamente." << endl;
                } catch (const out_of_range& e) {
                    cerr << e.what() << endl;
                }
                break;
            }
            case 12: {
                LinkedList<int> otraLista;
                int numElementos;
                cout << "Ingrese el número de elementos para la otra lista: ";
                cin >> numElementos;
                cout << "¿Desea llenar la otra lista con datos aleatorios? (S/N): ";
                char opcionAleatoria;
                cin >> opcionAleatoria;
                if (opcionAleatoria == 'S' || opcionAleatoria == 's') {
                    for (int i = 0; i < numElementos; i++) {
                        otraLista.addLast(rand() % 100); // Datos aleatorios entre 0 y 99
                    }
                } else {
                    for (int i = 0; i < numElementos; i++) {
                        int elemento;
                        cout << "Ingrese el elemento " << (i + 1) << ": ";
                        cin >> elemento;
                        otraLista.addLast(elemento);
                    }
                }
                lista = otraLista; // Utiliza el operador de asignación
                cout << "La lista se ha igualado con la otra lista correctamente." << endl;
                break;
            }
            case 13: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
                break;
            }
        }
    } while (opcion != 13);

    return 0;
}

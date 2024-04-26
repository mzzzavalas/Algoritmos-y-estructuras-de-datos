//Mauricio Zavala Sánchez
//A00837332
//ITCs
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    // Inicializar la semilla para números aleatorios
    srand(time(0));

    // Crear una lista enlazada
    LinkedList<int> lista;

    int opcion;
    do {
        cout << "=== Menu ===" << endl;
        cout << "1. Crear lista con datos aleatorios" << endl;
        cout << "2. Crear lista con datos capturados" << endl;
        cout << "3. Agregar elemento al principio" << endl;
        cout << "4. Agregar elemento al final" << endl;
        cout << "5. Insertar elemento a la derecha de un índice" << endl;
        cout << "6. Borrar elemento dado" << endl;
        cout << "7. Borrar elemento en una posición" << endl;
        cout << "8. Obtener elemento de una posición" << endl;
        cout << "9. Actualizar elemento dado" << endl;
        cout << "10. Actualizar elemento en una posición" << endl;
        cout << "11. Encontrar elemento dado" << endl;
        cout << "12. Obtener elemento de una posición (operador [])" << endl;
        cout << "13. Actualizar elemento de una posición (operador [])" << endl;
        cout << "14. Igualar lista con otra lista" << endl;
        cout << "15. Limpiar lista" << endl;
        cout << "16. Ordenar lista (QuickSort)" << endl;
        cout << "17. Duplicar lista" << endl;
        cout << "18. Remover elementos duplicados" << endl;
        cout << "19. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                lista.clear();
                for (int i = 0; i < 10; i++) {
                    lista.addLast(rand() % 100); // Agregar números aleatorios
                }
                cout << "Lista creada con datos aleatorios." << endl;
                break;
            }
            case 2: {
                lista.clear();
                int n, elemento;
                cout << "Ingrese el número de elementos: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Ingrese el elemento " << i + 1 << ": ";
                    cin >> elemento;
                    lista.addLast(elemento); // Agregar elementos capturados
                }
                cout << "Lista creada con datos capturados." << endl;
                break;
            }
            case 3: {
                int elemento;
                cout << "Ingrese el elemento a agregar al principio: ";
                cin >> elemento;
                lista.addFirst(elemento);
                cout << "Elemento agregado al principio." << endl;
                break;
            }
            case 4: {
                int elemento;
                cout << "Ingrese el elemento a agregar al final: ";
                cin >> elemento;
                lista.addLast(elemento);
                cout << "Elemento agregado al final." << endl;
                break;
            }
            case 5: {
                int elemento, indice;
                cout << "Ingrese el elemento a insertar: ";
                cin >> elemento;
                cout << "Ingrese el índice después del cual desea insertar: ";
                cin >> indice;
                try {
                    lista.insert(indice + 1, elemento);
                    cout << "Elemento insertado correctamente." << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 6: {
                int elemento;
                cout << "Ingrese el elemento a borrar: ";
                cin >> elemento;
                if (lista.deleteData(elemento)) {
                    cout << "Elemento borrado de la lista." << endl;
                } else {
                    cout << "Elemento no encontrado en la lista." << endl;
                }
                break;
            }
            case 7: {
                int indice;
                cout << "Ingrese el índice de la posición a borrar: ";
                cin >> indice;
                if (lista.deleteAt(indice)) {
                    cout << "Elemento en la posición " << indice << " borrado de la lista." << endl;
                } else {
                    cout << "Índice fuera de rango." << endl;
                }
                break;
            }
            case 8: {
                int indice;
                cout << "Ingrese el índice de la posición a obtener: ";
                cin >> indice;
                try {
                    int elemento = lista.getData(indice);
                    cout << "Elemento en la posición " << indice << ": " << elemento << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 9: {
                int elemento, nuevoElemento;
                cout << "Ingrese el elemento a actualizar: ";
                cin >> elemento;
                cout << "Ingrese el nuevo elemento: ";
                cin >> nuevoElemento;
                lista.updateData(elemento, nuevoElemento);
                cout << "Elemento actualizado correctamente." << endl;
                break;
            }
            case 10: {
                int indice, nuevoElemento;
                cout << "Ingrese el índice de la posición a actualizar: ";
                cin >> indice;
                cout << "Ingrese el nuevo elemento: ";
                cin >> nuevoElemento;
                try {
                    lista.updateAt(indice, nuevoElemento);
                    cout << "Elemento en la posición " << indice << " actualizado correctamente." << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 11: {
                int elemento;
                cout << "Ingrese el elemento a buscar: ";
                cin >> elemento;
                int indice = lista.findData(elemento);
                if (indice != -1) {
                    cout << "Elemento encontrado en la posición " << indice << "." << endl;
                } else {
                    cout << "Elemento no encontrado en la lista." << endl;
                }
                break;
            }
            case 12: {
                int indice;
                cout << "Ingrese el índice de la posición a obtener (operador []): ";
                cin >> indice;
                try {
                    int elemento = lista[indice];
                    cout << "Elemento en la posición " << indice << ": " << elemento << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 13: {
                int indice, nuevoElemento;
                cout << "Ingrese el índice de la posición a actualizar (operador []): ";
                cin >> indice;
                cout << "Ingrese el nuevo elemento: ";
                cin >> nuevoElemento;
                try {
                    lista[indice] = nuevoElemento;
                    cout << "Elemento en la posición " << indice << " actualizado correctamente (operador [])." << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 14: {
                LinkedList<int> otraLista;
                int opcion2;
                do {
                    cout << "=== Opciones para otra lista ===" << endl;
                    cout << "1. Crear lista con datos aleatorios" << endl;
                    cout << "2. Crear lista con datos capturados" << endl;
                    cout << "3. Salir" << endl;
                    cout << "Elija una opción: ";
                    cin >> opcion2;

                    switch (opcion2) {
                        case 1: {
                            otraLista.clear();
                            for (int i = 0; i < 10; i++) {
                                otraLista.addLast(rand() % 100);
                            }
                            cout << "Otra lista creada con datos aleatorios." << endl;
                            break;
                        }
                        case 2: {
                            otraLista.clear();
                            int n, elemento;
                            cout << "Ingrese el número de elementos para la otra lista: ";
                            cin >> n;
                            for (int i = 0; i < n; i++) {
                                cout << "Ingrese el elemento " << i + 1 << ": ";
                                cin >> elemento;
                                otraLista.addLast(elemento);
                            }
                            cout << "Otra lista creada con datos capturados." << endl;
                            break;
                        }
                        case 3:
                            break;
                        default:
                            cout << "Opción no válida." << endl;
                            break;
                    }
                } while (opcion2 != 3);

                lista = otraLista; // Igualar lista con otra lista
                cout << "Lista igualada con la otra lista." << endl;
                break;
            }
            case 15: {
                lista.clear();
                cout << "Lista limpiada." << endl;
                break;
            }
            case 16: {
                lista.Sort(lista, 0, lista.getSize() - 1); // Ordenar la lista (QuickSort)
                cout << "Lista ordenada (QuickSort)." << endl;
                break;
            }
            case 17: {
                lista.duplicate(); // Duplicar la lista
                cout << "Lista duplicada." << endl;
                break;
            }
            case 18: {
                lista.Sort(lista, 0, lista.getSize() - 1); // Ordenar la lista antes de eliminar duplicados
                lista.removeDuplicates(); // Remover elementos duplicados
                cout << "Elementos duplicados eliminados." << endl;
                break;
            }
            case 19:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 19);

    return 0;
}

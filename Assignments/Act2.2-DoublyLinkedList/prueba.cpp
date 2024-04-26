#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main() {
    LinkedList<int> myList;

    // Agregar elementos a la lista
    myList.addLast(1);
    myList.addLast(2);
    myList.addLast(3);
    myList.addLast(2);
    myList.addLast(4);

    // Imprimir la lista original
    cout << "Lista original: ";
    myList.print();

    // Probar el método 'findData'
    int searchData = 2;
    int foundIndex = myList.findData(searchData);
    if (foundIndex != -1) {
        cout << "El elemento " << searchData << " se encuentra en la posición " << foundIndex << endl;
    } else {
        cout << "El elemento " << searchData << " no se encuentra en la lista." << endl;
    }

    // Probar el método 'getData'
    int indexToGetData = 3;
    int retrievedData = myList.getData(indexToGetData);
    cout << "El dato en la posición " << indexToGetData << " es " << retrievedData << endl;

    // Probar el método 'updateData'
    int oldData = 2;
    int newData = 5;
    myList.updateData(oldData, newData);
    cout << "Lista después de actualizar " << oldData << " con " << newData << ": ";
    myList.print();

    // Probar el método 'deleteData'
    int dataToDelete = 3;
    myList.deleteData(dataToDelete);
    cout << "Lista después de eliminar " << dataToDelete << ": ";
    myList.print();

    // Probar el método 'deleteAt'
    int indexToDelete = 1;
    myList.deleteAt(indexToDelete);
    cout << "Lista después de eliminar el elemento en la posición " << indexToDelete << ": ";
    myList.print();

    // Probar el método 'duplicate'
    myList.duplicate();
    cout << "Lista duplicada: ";
    myList.print();

    // Probar el método 'removeDuplicates'
    myList.removeDuplicates();
    cout << "Lista sin elementos duplicados: ";
    myList.print();

    // Ordenar la lista
    myList.Sort(myList, 0, myList.getSize() - 1);
    cout << "Lista ordenada: ";
    myList.print();

    // Probar el método 'isEmpty'
    if (myList.isEmpty()) {
        cout << "La lista está vacía." << endl;
    } else {
        cout << "La lista no está vacía." << endl;
    }

    // Limpiar la lista
    myList.clear();
    cout << "Lista después de limpiar: ";
    myList.print();

    return 0;
}

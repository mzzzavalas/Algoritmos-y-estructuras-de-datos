#include <iostream>
using namespace std;
#include "LinkedList.h"

int main() {

    LinkedList<string> list;
    cout << "Tamaño de la lista: " << list.getSize() << endl;
    list.addFirst("Olla");
    list.addFirst("Estufa");
    list.addFirst("Jarra");
    list.addFirst("Plato");
    list.addLast("Tenedor");
    list.addLast("Olla");

    list.print();
    try {
        list.insert(4, "Cuchara");
        list.print();
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    try {
        cout << list[3] << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    list[3] = "Cazuela";
    list.print();

    cout<<"Indice: "<<list.findData("Olla")<<endl;
    try{
        list.updateData("Olla","Cuchillo");
        list.print();
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    try{
        cout<<"Dato: "<<list.getData(4)<<endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
    
    try{
        list.updateAt(1,"Taza");
        list.print();
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }
     if (list.deleteData("Plato")) {
        list.print();
    }
    if (list.deleteData("Cazuela")) {
        list.print();
    }
    if (list.deleteData("Cuchara")) {
        list.print();
    }
    if (list.deleteAt(0)) {
        list.print();
    }
    if (list.deleteAt(1)) {
        list.print();
    }
    if (list.deleteAt(5)) {
        list.print();
    }




    return 0;
}
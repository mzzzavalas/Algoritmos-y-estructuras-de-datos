//Mauricio Zavala Sánchez
//A00837332
//ITC
// 9/8/2023
#include <iostream>
#include <vector>
using namespace std;

#include "List.h"

int main()
{
    List<int> list;

    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);
    list.insert(25);

    list.print();


    List<string> listS;

    listS.insert("Hola");
    listS.insert("perro");
    listS.insert("sarnoso");
    listS.insert("dale suave");
    listS.insert("tu casa");

    listS.print();

    
    
    //RemoveLast
    list.removeLast();
    list.removeLast();
    list.removeLast();
    list.removeLast();

    // Get Data
    try {
        cout << "El elemento en la posición 0 es: " << list.getData(0) << endl;
        cout << "El elemento en la posición 1 es: " << list.getData(1) << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

     // Get Size
    cout << "El tamaño de la lista es: " << list.getSize() << endl;

    // Get Max
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    cout <<"El elemento mas grande de la lista es: " << list.getMax() <<endl;

    list.print();



    return 0;
}
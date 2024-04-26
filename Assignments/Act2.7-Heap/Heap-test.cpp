#include <iostream>
using namespace std;

#include "Heap.h"
#include "MinHeap.h"

// Heap Sort
template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "asc") {
        // Creamos un heap en base a la lista
        Heap<T> heap(list);
        // Ciclo para sacar todos los elementos del heao y agregarlos a la lista
        for (int i=0; i<list.size(); i++) {
            list[i] = heap.pop();
        }
    } else {
        if (order == "desc") {
            // Creamos un heap en base a la lista
            MinHeap<T> heap(list);
            // Ciclo para sacar todos los elementos del heao y agregarlos a la lista
            for (int i=0; i<list.size(); i++) {
                list[i] = heap.pop();
            }
        } 
    }
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

template <class T>
void print(vector<T> list) {
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
    // Semilla para generar números aleatorios
    srand(time(0));
    /*
    vector<int> list = {8,5,17,19,21,28};
    Heap<int> heap1(list);
    Heap<int> heap2 = {1,2,3,4,5,6,7,8,9,10};
    heap1.print();
    heap2.print();
    cout << heap1.pop() << endl;
    heap1.print();
    while (!heap1.isEmpty()) {
        cout << heap1.pop() << " ";
    }
    cout << endl;
    heap1.pop();
    heap1.push(30);
    heap1.print();*/
    
    //Heap 
    vector<int> list;
    createListInt(list, 20);
    heapSort(list, "asc");
    print(list);
    heapSort(list, "desc");
    print(list);
    
    Heap<int> heap(list);
    cout<<heap.top()<<endl;
    heap.pop();
    heap.print();
    cout<<heap.top()<<endl;
    cout<<heap.isEmpty()<<endl;;
    cout<<heap.getSize()<<endl;
    heap.push(690);
    heap.print();
    while (!heap.isEmpty()) {
        cout << heap.pop() << " ";
    }


/*
    vector<int> list;
    createListInt(list, 20);
    heapSort(list, "asc");
    print(list);
    heapSort(list, "desc");
    print(list);

    MinHeap<int> heap(list);
    cout<<heap.pop()<<endl;
    cout<<heap.top()<<endl;
    cout<<heap.isEmpty()<<endl;;
    cout<<heap.getSize()<<endl;
    heap.push(690);
    heap.print();
    while (!heap.isEmpty()) {
        cout << heap.pop() << " ";
    }*/




    





    
    

  


    return 0;
}
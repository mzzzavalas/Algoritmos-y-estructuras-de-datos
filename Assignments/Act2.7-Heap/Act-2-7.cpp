//Mauricio Zavala Sánchez
//A00837332
//IRS

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
    srand(time(0));
    cout<<"Se cre una lista aleatoria de 20 numero"<<endl;
    vector<int> list;
    createListInt(list, 20);
    Heap<int> heap(list);
    MinHeap<int> minheap(list);
    int choice, data;
    int level;

    while (true){
        cout<<"Heap Menu: "<<endl;
        cout<<"1. MaxHeap"<<endl;
        cout<<"2. MinHeap"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter you choice"<<endl;

        cin >> choice;
        switch (choice) {
            case 1:
                // heap sort asc
                heapSort(list, "asc");
                print(list);
                int choice2;
                while (true){
                    cout<<"MaxHeap Menu: "<<endl;
                    cout<<"1. Push: "<<endl;
                    cout<<"2. Pop: "<<endl;
                    cout<<"3. Top: "<<endl;
                    cout<<"4. Empty: "<<endl;
                    cout<<"5. Size "<<endl;
                    cout<<"6. Print and Exit "<<endl;
                    cout<<"Enter your choice "<<endl;

                    cin>>choice2;
                    switch (choice2){
                        case 1:
                        cout<<"Enter de number you wish to push: "<<endl;
                        int input;
                        cin>>input;
                        heap.push(690);
                        break;

                        case 2:
                        cout<<heap.pop()<<endl;
                        cout<<"The elemente with higher priority was poped out:  "<<endl;
                        break;

                        case 3:
                        cout<<"The element at the top is: "<<heap.top()<<endl;
                        break;

                        case 4:
                        if(heap.isEmpty()==0){
                            cout<<"The list is not empty. "<<endl;
                        }else{
                            cout<<"The list is empty."<<endl;
                        }
                        break;

                        case 5:
                        cout<<"The size of the list is: "<<heap.getSize()<<endl;
                        break;

                        case 6:
                        while (!heap.isEmpty()) {
                            cout << heap.pop() << " ";
                        } cout<<endl;
                        cout << "Exiting program." << endl;
                        return 0;
                        default:
                            cout << "Invalid choice. Please enter a valid option." << endl;

                    }
                }
                break;


            case 2:
                // heap sort desc
                heapSort(list, "desc");
                print(list);

                int choice3;
                while (true){
                    cout<<"MinHeap Menu: "<<endl;
                    cout<<"1. Push: "<<endl;
                    cout<<"2. Pop: "<<endl;
                    cout<<"3. Top: "<<endl;
                    cout<<"4. Empty: "<<endl;
                    cout<<"5. Size "<<endl;
                    cout<<"6. Print and Exit "<<endl;
                    cout<<"Enter your choice "<<endl;

                    cin>>choice3;
                    switch (choice3){
                        case 1:
                        cout<<"Enter de number you wish to push: "<<endl;
                        int input;
                        cin>>input;
                        minheap.push(690);
                        break;

                        case 2:
                        cout<<minheap.pop()<<endl;
                        cout<<"The elemente with higher priority was poped out:  "<<endl;
                        break;

                        case 3:
                        cout<<"The element at the top is: "<<minheap.top()<<endl;
                        break;

                        case 4:
                        if(minheap.isEmpty()==0){
                            cout<<"The list is not empty. "<<endl;
                        }else{
                            cout<<"The list is empty."<<endl;
                        }
                        break;

                        case 5:
                        cout<<"The size of the list is: "<<minheap.getSize()<<endl;
                        break;

                        case 6:
                        while (!minheap.isEmpty()) {
                            cout << minheap.pop() << " ";
                        } cout<<endl;
                        cout << "Exiting program." << endl;
                        return 0;
                        default:
                            cout << "Invalid choice. Please enter a valid option." << endl;

                    }
                }
                
                
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    return 0;

}
    











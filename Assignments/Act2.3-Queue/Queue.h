#ifndef Queue_h
#define Queue_h

#include "Node.h"
using namespace std;

template <class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    Queue();
    int getSize();
    void push(T data); // Agrega un elemento al final de la fila (enqueque)
    void pop(); // elimina el primer elemento de la file (dequeue)
    T front(); // regresa el primer elemento de la fila (front)
    bool isEmpty();
    void print();
};


template<class T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
    size=0;
}

template<class T>
int Queue<T>::getSize() {
    return size;
}

template<class T>
void Queue<T>::push(T data) {
    if (isEmpty()) {
        head = new Node<T>(data);
    } else {
        // Creamos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista hasta llegar al último elemento
        while (aux->next != nullptr) {
            // Recorremos aux
            aux = aux->next;
        }
        // Ya llegamos al último elemento
        // Agregamos el nuevo elemento
        aux->next = new Node<T>(data);
    }
    // incrementamos el tamaño de la lista
    size++;
}
template<class T>
void Queue<T>::pop(){
    if (!isEmpty()){
        cout<<"El primer valor de la fila: '"<<head->data<<"' fue eliminado."<<endl;
        // Creamos un apuntador auxiliar igual a head
            Node<T>* aux = head;
            // Apuntamos head al siguiente nodo de head
            head = head->next;
            // Decrementamos el valor size
            size--;
            // Liberamos la memoria
            delete aux;


    } else {
        //esta vacia
        throw out_of_range("La fila esta vacia");
    }

}

template<class T>
T Queue<T>::front(){
    if (!isEmpty()){
        return head->data;
    } else {
        //esta vacia
        throw out_of_range("La fila esta vacia");
    }


}



template<class T>
void Queue<T>::print() {
    // Creamos un apuntador de tipo de nodo igual a head
    Node<T>* aux = head;
    while (aux != nullptr) {
        // cout << aux << " " << aux->data << " " << aux->next << endl;
        cout << aux->data;
        if (aux->next != nullptr) {
            cout << "<-";
        } 
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}
#endif



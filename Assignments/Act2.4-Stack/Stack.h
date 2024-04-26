#ifndef Stack_h
#define Stack_h

#include "Node.h"
using namespace std;

template <class T>
class Stack {
private:
    Node<T>* head;
    int size;
public:
    Stack();
    int getSize();
    void push(T data); // agrega un elemento a la pila
    void pop(); // Elimina el elemento de arriba de la pila
    T top(); // Regresa el elemento de arriba de la pila
    bool isEmpty(); // Regresa si la pila esta vacía o no
    void print(); // Imprime toda la pila
};

template<class T>
Stack<T>::Stack(){
    head=nullptr;
    size=0;
}

template<class T>
int Stack<T>::getSize() {
    return size;
}

template<class T>
void Stack<T>::push(T data){
    head = new Node<T>(data, head);
    size++;
}

template<class T>
void Stack<T>::pop(){
    if (!isEmpty()) {
        // Creamos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Recorremos la lista hasta llegar al último elemento
        while (aux->next != nullptr) {
            // Recorremos aux
            aux = aux->next;
        }
        cout<<"El ultimo elemento agregado al Stack: '"<<head->data<<"' fue eliminado."<<endl;
        // Ya llegamos al último elemento
        head = head->next;        // Decrementamos el valor size
        size--;
        // Liberamos la memoria
        delete aux;
    } else {
        //esta vacia
        throw out_of_range("La fila esta vacia");
    }
}

template<class T>
T Stack<T>::top(){
    if (!isEmpty()){
        return head->data;
    } else {
        //esta vacia
        throw out_of_range("La fila esta vacia");
    }
}




template<class T>
void Stack<T>::print() {
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
bool Stack<T>::isEmpty() {
    return size == 0;
}
#endif




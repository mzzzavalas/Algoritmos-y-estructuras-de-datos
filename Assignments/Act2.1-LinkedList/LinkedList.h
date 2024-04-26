

#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"
using namespace std;

template<class T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList();
    int getSize();
    void addFirst(T data); // Agrega un elemento al principio de la lista
    void addLast(T data); // Agrega un elemento al final de la lista
    void insert(int index, T data); // Inserta un elemento a la derecha del indice dado
    int findData(T data); // Regresa el índice del valor buscado o -1 si no lo encontró
    void updateData(T data, T nuevo);
    T getData(int posicion);
    void updateAt(int posicion, T data);
    bool deleteData(T data); // Elimina el elemento con el valor dado
    bool deleteAt(int index); // Elimina el elemento en el índice dado
    T& operator[](int index); // Regresa el valor del elemento en el índice dado
    void operator=(LinkedList<T> list); // Iguala los valores de la lista dada a la lista actual
    bool isEmpty();
    void print(); // Imprime los elementos de la lista;
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::addFirst(T data) {
    // Asignamos un nuevo nodo a head y ese nodo va a contener el valor de data y va a apuntar a head
    // cout << head << endl;
    head = new Node<T>(data, head);
    // cout << head << endl;
    // cout << head->data << " " << head->next << endl;
    // Incrementamos size
    size++;
}
#include <iostream>

template<class T>
void LinkedList<T>::print() {
    // Creamos un apuntador de tipo de nodo igual a head
    Node<T>* aux = head;
    while (aux != nullptr) {
        // cout << aux << " " << aux->data << " " << aux->next << endl;
        cout << aux->data;
        if (aux->next != nullptr) {
            cout << "->";
        } 
        aux = aux->next;
    }
    cout << endl;
}

template<class T>
void LinkedList<T>::addLast(T data) {
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
void LinkedList<T>::insert(int index, T data) {
    // Validamos que el índice exista
    if (index >= 0 && index < size) {
        // Creamos un apuntador auxiliar igual a head
        Node<T>* aux = head;
        // Creamos un índice auxiliar igual 0
        int auxIndex = 0;
        // Recorrer la lista mientras el auxIndex sea diferente de index
        while (auxIndex != index) {
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el valor del índice auxiliar
            auxIndex++;
        }
        // Ya encontramos el elemento deseado
        aux->next = new Node<T>(data, aux->next);
        // Incrementamos size
        size++;
    } else {
        throw out_of_range("El índice es incorrecto");
    }
}

template<class T>
int LinkedList<T>::findData(T data) {
    // Creamos un apuntador auxiliar igual a head
    Node<T>* aux = head;
    // Creamos un índice auxiliar igual a 0
    int auxIndex = 0;
    // Recorremos toda la lista
    while (aux != nullptr) {
        // Validamos si aux->data es igual a data
        if (aux->data == data) {
            // Regresamos el valor del índice auxiliar
            return auxIndex;
        }
        // Recorremos aux
        aux = aux->next;
        // Incrementamos el valor del índice auxiliar
        auxIndex++;
    }
    // No encontramos el valor
    return -1;
}
template<class T>
T LinkedList<T>::getData(int posicion){
    if (posicion >= 0 && posicion < size) {
    // Creamos un apuntador auxiliar igual a head
    Node<T>* aux = head;
    // Recorremos toda la lista
    for (int i=0;i<size;i++) {
        // Validamos si aux->data es igual a data
        if (i == posicion) {
            // Regresamos el valor del índice auxiliar
            return aux->data;
        }else{
            // Recorremos aux
            aux = aux->next;
        }
    }
    }else{
    // No encontramos el valor
        throw out_of_range("La posicion es invalida");
    }
    return 0;
}

template<class T>
void LinkedList<T>::updateData(T data, T nuevo){
    int index=findData(data);
    if (index >= 0 && index < size) {
    Node<T>* aux = head;
    for(int i=0;i<size;i++){
        if (aux->data==data){
            aux->data=nuevo;
        }else{
        aux=aux->next;
        }
    }
    }else {
        throw out_of_range("No se pueda actualizar");
    }
}


template<class T>
void LinkedList<T>::updateAt(int posicion, T data){
    if (posicion >= 0 && posicion < size) {
    Node<T>* aux = head;
    for(int i=0;i<size;i++){
        if (posicion==i){
            aux->data=data;
        }else{
        aux=aux->next;
        }
    }
    }else {
        throw out_of_range("No se pueda actualizar");
    }
}


template <class T>
bool LinkedList<T>::deleteData(T data) {
    // Validamos que la lista no este vacía
    if (!isEmpty()) {
        // Validamos si el primer elemento de la lista es el que se desaea borrar
        if (head->data == data) {
            // Creamos un apuntador auxiliar igual a head
            Node<T>* aux = head;
            // Apuntamos head al siguiente nodo de head
            head = head->next;
            // Decrementamos el valor size
            size--;
            // Liberamos la memoria
            delete aux;
            // regresamos true
            return true;
        } else {
            // Creamos un apuntador igual a head
            Node<T>* auxPrev = head;
            // Creamos un apuntador auxiliar igual a head->next
            Node<T>* aux = head->next;
            // Recorremos la lista para buscar datd
            while (aux != nullptr) {
                // Validamos si aux->data es igual a data
                if (aux->data == data) {
                    // Actualizamos el next de auxPrev
                    auxPrev->next = aux->next;
                    // decrementamos el valor de size
                    size--;
                    // Liberamos la memoria
                    delete aux;
                    // regresamos true
                    return true;
                }
                // Recorremos los apuntadores
                auxPrev = aux;
                aux = aux->next;
            }
            // No encontramos data
            return false;
        }
    } else {
        return false;
    }
}

template <class T>
bool LinkedList<T>::deleteAt(int index) {
    // Validamos que el índice sea válido
    if (index >= 0 && index < size) {
        // Validamos si se desea borrar el primer elemento
        if (index == 0) {
            // Creamos un apuntador auxiliar igual a head
            Node<T>* aux = head;
            // Apuntamos head al siguiente nodo de head
            head = head->next;
            // Decrementamos el valor size
            size--;
            // Liberamos la memoria
            delete aux;
            // regresamos true
            return true;
        } else {
            // creamos un índice auxliar previo
            Node<T>* auxPrev = head;
            // creamos un índice auxliar
            Node<T>* aux = head->next;
            // Creamos un índice auxliar igual a 1
            int auxIndex = 1;
            // Recorremos la lista hasta llegar al índice deseado
            while (auxIndex < index) {
                // Recorremos los apuntadores
                auxPrev = aux;
                aux = aux->next;
                // incrementamos el indice auxiliar
                auxIndex++;
            }
            // ya lleganos a index y lo borramos
            auxPrev->next = aux->next;
            // decrementamos el valor de size
            size--;
            // Liberamos la memoria
            delete aux;
            // regresamos true
            return true;
        }
    } else {
        return false;
    }
}

template<class T>
T& LinkedList<T>::operator[](int index) {
    // Validamos que el índec sea correcto
    if (index >= 0 && index < size) {
        // Creamos un apuntador axuliar igual a had
        Node<T>* aux = head;
        // Creamo un índice auxiliar igual a 0
        int auxIndex = 0;
        // Recorremos la lista hasta llegar a index
        while (auxIndex < index) {
            // Recorremos aux
            aux = aux->next;
            // Incrementamos el índice auxiliar
            auxIndex++;
        }
        // Ya recorreimos la lista hasta llegar a index
        return aux->data;
    } else {
        throw out_of_range("Índice incorrecto");
    }
}


template<class T>
void LinkedList<T>::operator=(LinkedList<T> list) {
    // Primero, eliminamos todos los elementos de la lista actual
    while (!isEmpty()) {
        deleteAt(0);
    }

    // Copiamos los elementos de la lista proporcionada a la lista actual
    Node<T>* aux = list.head;
    while (aux != nullptr) {
        addLast(aux->data);
        aux = aux->next;
    }
}




template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}
#endif



    /*/Mi intento
    for(int i=0;i<size;i++){
        if(node->data==data){
            return i;
        }else{
            node=node->next;
        }
    }
/*/


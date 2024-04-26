#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"
using namespace std;

template<class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail; // Agregamos un puntero al último nodo
    int size;
public:
    LinkedList();
    int getSize();
    void addFirst(T data); //Inserta un elemento al principio de la lista.
    void addLast(T data); //Inserta un elemento al final de la lista.
    void insert(int index, T data);//Inserta un elemento después del índice dado.
    int findData(T data);//Busca un elemento en la lista.
    void updateData(T data, T nuevo);//Actualiza el primer elemento que sea igual al valor recibido como parámetro con el valor del dato nuevo recibido como parámetro.
    T getData(int posicion);//Lee el valor de un dato de la lista, de acuerdo con la posición recibida como parámetro de entrada.
    void updateAt(int posicion, T data);//Actualiza un elemento en una posición recibida como parámetro con el valor de un dato recibido como parámetro.
    bool deleteData(T data);//Borra el primer elemento que se encuentre en la lista igual al parámetro de entrada.
    bool deleteAt(int index);//Borra un elemento en una posición de la lista dada.
    T& operator[](int index);//Leer y/o actualizar un elemento en una posición dada.
    void operator=(LinkedList<T> list);//Actualiza la lista con base en otra lista.
    void clear();//Elimina todos los elementos de la lista.
    void swap(LinkedList<T> &list, int a, int b);
    int getPivot(LinkedList<T> &list, int left, int right);
    void Sort(LinkedList<T> &list, int left, int right);//Ordena los datos de la lista (QUICKSORT).
    void duplicate();//Duplica cada elemento de la lista.
    void removeDuplicates();//Elimina todos los elementos duplicados en la lista.
    bool isEmpty();//
    void print(string mode);//
};

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::addFirst(T data) {
    Node<T>* newNode = new Node<T>(data, head, nullptr); // nullptr para el puntero previo en el primer nodo
    if (isEmpty()) {
        tail = newNode; // Si la lista estaba vacía, el nuevo nodo también es el último
    } else {
        head->prev = newNode; // Actualizamos el puntero previo del antiguo primer nodo
    }
    head = newNode; // Actualizamos el puntero head
    size++;
}

template<class T>
void LinkedList<T>::print(string mode) {
    // Validamos si el modeo es asc o desc
    if (mode == "asc") {
        // Definimos un apuntador auxiliar que sea igual a head
        Node<T>* aux = head;
        while (aux != nullptr) {
            // Imprimimos el valor de data
            cout << aux->data;
            if (aux->next != nullptr) {
                cout << "->";
            } 
            // recorremos aux al apuntador de next
            aux = aux->next;
        }
        // Imprimos un salto de linea
        cout << endl;
    } else {
        // Definimos un apuntador auxiliar que sea igual a head
        Node<T>* aux = tail;
        while (aux != nullptr) {
            // Imprimimos el valor de data
            cout << aux->data;
            if (aux->prev != nullptr) {
                cout << "->";
            } 
            // recorremos aux al apuntador de next
            aux = aux->prev;
        }
        // Imprimos un salto de linea
        cout << endl;    
    }
}

template<class T>
void LinkedList<T>::addLast(T data) {
    Node<T>* newNode = new Node<T>(data, nullptr, tail); // nullptr para el puntero siguiente en el último nodo
    if (isEmpty()) {
        head = newNode; // Si la lista estaba vacía, el nuevo nodo también es el primero
    } else {
        tail->next = newNode; // Actualizamos el puntero siguiente del antiguo último nodo
    }
    tail = newNode; // Actualizamos el puntero tail
    size++;
}

template<class T>
void LinkedList<T>::insert(int index, T data) {
    if (index >= 0 && index <= size) {
        if (index == 0) {
            addFirst(data);
        } else if (index == size) {
            addLast(data);
        } else {
            Node<T>* aux = head;
            int currentIndex = 0;
            while (currentIndex < index) {
                aux = aux->next;
                currentIndex++;
            }
            Node<T>* newNode = new Node<T>(data, aux, aux->prev);
            aux->prev->next = newNode;
            aux->prev = newNode;
            size++;
        }
    } else {
        throw out_of_range("El índice es incorrecto");
    }
}

// Los métodos restantes (findData, updateData, getData, updateAt, deleteData, deleteAt, operator[], operator=, isEmpty, print) se pueden mantener sin cambios.

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
void LinkedList<T>::clear() {
    while (!isEmpty()) {
        deleteAt(0);
    }
}


//SORT
template<class T>
void LinkedList<T>::swap(LinkedList<T> &list, int a, int b) {
    if (list[a] != list[b]) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}
template<class T>
int LinkedList<T>::getPivot(LinkedList<T> &list, int left, int right) {
    // Definimos el índice del pivote
    int pivot = right;
    // Definimos un índice auxiliar igual a left - 1
    int auxIndex = left - 1;
    // Recorremos la lista desde left hasta right - 1
    for (int index=left; index < right; index++) {
        // Comparamos el valor en index con el valor en pivot
        if (list[index] < list[pivot]) {
            // Incrementamos el valor del índice auxiliar
            auxIndex++;
            // Intercambiamos el índice del for con el índice auxiliar
            swap(list, index, auxIndex);
        }
    }
    // Incrementamos el valor del índice auxiliar
    auxIndex++;
    // Intercambiamos índice auxiliar con con el pivot
    swap(list, auxIndex, pivot);
    // Regresamos el valor del índice auxiliar que representa la posición final del pivote
    return auxIndex;
}
template<class T>
void LinkedList<T>::Sort(LinkedList<T> &list, int left, int right) {
    // Condición de control mientras left sea menor que right
    if (left < right) {
        // Obtener el índice final del privote
        int pivot = getPivot(list, left, right);
        // Ordenamos la lista del lado izquierdo
        Sort(list, left, pivot-1);
        // Ordenamos la lista del lado derecho
        Sort(list, pivot+1, right);
    }
}

template<class T>
void LinkedList<T>::duplicate() {
    // Creamos un apuntador auxiliar igual a head
    Node<T>* aux = head;
    // Recorremos toda la lista
    while (aux != nullptr) {
        // Duplicamos el valor del elemento actual
        T duplicatedValue = aux->data;
        // Creamos un nuevo nodo con el valor duplicado
        Node<T>* newNode = new Node<T>(duplicatedValue, aux->next, aux);
        
        // Si el elemento actual no es el último
        if (aux->next != nullptr) {
            aux->next->prev = newNode;
        } else {
            // Si es el último elemento, actualizamos el tail
            tail = newNode;
        }

        aux->next = newNode;
        aux = newNode->next; // Avanzamos dos posiciones, ya que duplicamos cada elemento
        size += 2; // Aumentamos el tamaño de la lista en 2
    }
}

template<class T>
void LinkedList<T>::removeDuplicates() {
    if (isEmpty()) {
        return; // No hay elementos para eliminar duplicados
    }

    Node<T>* current = head;
    while (current != nullptr) {
        T currentValue = current->data;

        // Buscamos duplicados a partir del nodo siguiente
        Node<T>* runner = current->next;
        while (runner != nullptr) {
            if (runner->data == currentValue) {
                // Eliminamos el nodo duplicado
                Node<T>* duplicateNode = runner;
                runner = runner->next;

                if (duplicateNode->next != nullptr) {
                    duplicateNode->next->prev = duplicateNode->prev;
                } else {
                    // Si el nodo duplicado era el último, actualizamos el tail
                    tail = duplicateNode->prev;
                }

                if (duplicateNode->prev != nullptr) {
                    duplicateNode->prev->next = duplicateNode->next;
                } else {
                    // Si el nodo duplicado era el primero, actualizamos el head
                    head = duplicateNode->next;
                }

                delete duplicateNode;
                size--;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}



template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}
#endif



#ifndef List_h
#define List_h

template <class T>
class List {
private:
    vector<T> list;
    int size;
public:
    List();
    void insert(T data);
    void removeLast();
    T getData(int index);
    T getMax();
    int getSize();
    void print();
};

//Constructor
template <class T>
List<T>::List(){
    size=0;
}

// Insert
template <class T>
void List<T>::insert(T data){
    list.push_back(data);
    size++;
}

//Remove el ultimo elemento de la lista
template <class T>
void List<T>::removeLast(){
    // Valida si la lista no esta vacia
    if (size > 0){
        cout<<"El ultimo elemento de la lista es: "<<list[size-1]<<endl;
        list.pop_back();
        size--;
    } else{
        cout<<"NO HAY ELMENTOS" <<endl;
    }
}

//Regresa el valo de la posicion dada
template <class T>
T List<T>::getData(int index) {
    // Valida si el índice esta dentro del rango
    if (index >= 0 && index < size) {
        return list[index];
    } else {
        throw out_of_range("Índice fuera de rango de la lista");
    }
}

// Regresa el valor mas grande de la lista 
template <class T>
T List<T>::getMax() {
    if (size > 0) {
        T max = list[0];
        for (int i=1; i < size; i++) {
            if (list[i] > max) {
                max = list[i];
            }
        }
        return max;
    } else {
        throw out_of_range("Lista vacía");
    }
}

template <class T>
int List<T>::getSize() {
    return size;
}

//Print
template <class T>
void List<T>::print() {
    // Iteramos de manera tradicional
    /*/for (int i=0; i< size; i++){
        cout<<list[i]<<" ";
    }/*/
    //Iteramos de manera moderna
    for(auto el : list){  //auto se adapta al tipo de dato,  funciona en for de este tipo
        cout<<el<<" ";

    }
    cout<<endl;
}

#endif
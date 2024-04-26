#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 100 + 1;
    list.push_back(num);
  }
}

template<class T>
void swap(vector<T> &list, int a, int b) {
    if (list[a] != list[b]) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

template<class T>
void print(vector<T> list) {
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}

// Ordenamiento por intercambio
template<class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps) {
    for (int i=0; i<list.size()-1; i++) {
        for (int j=i+1; j<list.size(); j++) {
            // Incrementamos las comparaciones
            comparisons++;
            // Comparamos el elemento i con el elemento j
            if (list[i] > list[j]) {
                // Intercambiamos i con j
                swap(list, i, j);
                // Incrementar los intercambios
                swaps++;
            }
        }
    }
    cout << "Swap sort"<< endl;
    print(list);
}

// Ordenamiento por burbuja
template<class T> 
void bubbleSort(vector<T> &list, int &comparisons, int &swaps) {
    // Variable para controlar el número de pasadas
    int iter = 0;
    // Variable para controlar si hubo intercambios o no
    bool control = true;
    // Iterar cada una de las pasadas
    while (iter < list.size()-1 && control) {
        // Inicializamos la variable control en false
        control = false;
        // Iteramos cada uno de los elementos
        for (int j=1; j<list.size()-iter; j++) {
            // Incrementamos las comparaciones
            comparisons++;
            // Comparamos j con j-1
            if (list[j-1] > list[j]) {
                // incrementamos los intercambios 
                swaps++;
                // hacemos el intercambio de j con j-1
                swap(list, j-1, j);
                // cambiamos a true la variable control
                control = true;
            }
        }
        // Incrementamos iter
        iter++;
    }
}

template<class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps) {
    for (int i=0; i<list.size()-1; i++) {
        // suponemos que i es el menor de los elementos restantes
        int minIndex = i;
        for (int j=i+1; j<list.size(); j++) {
            // Incrementamos las comparaciones 
            comparisons++;
            // comparamos j con j-1
            if (list[j] < list[minIndex]) {
                // Asignamos a minIndex el valor de j                
                minIndex = j;
            }
        }
        // Validamos si i es igual a minIndex
        if (i != minIndex) {
            // Intercambiamos i con minIndex
            swap(list, i, minIndex);
            // incrementamos los intercambios
            swaps++;
        }   
    }
}

template<class T>
void insertionSort(vector<T> &list, int &comparisons, int &swaps) {
    for (int i=1; i<list.size(); i++) {
        int j=i-1;
        // while (j >= 0) {
        //     // incrementamos las comparaciones
        //     comparisons++;
        //     // comparamos j+1 con j
        //     if (list[j+1] < list[j]) {
        //         // Incrementamos los intercambios
        //         swaps++;
        //         // Intercambiamos j+1 con j
        //         swap(list, j+1, j);
        //     }
        //     // Decrementamos el valor de j
        //     j--;
        // }
        while (j >= 0 && list[j+1] < list[j]) {
            // incrementamos las comparaciones
            comparisons++;
            // Incrementamos los intercambios
            swaps++;
            // Intercambiamos j+1 con j
            swap(list, j+1, j);
            // Decrementamos el valor de j
            j--;
        }
        if (j>=0) {
            // incrementamos las comparaciones
            comparisons++;
        }
    }
}

template<class T>
void merge(vector<T> &list, int left, int mid, int right) {
    // Creamos lista izquierda
    vector<T> leftList;
    for (int i=left; i<=mid; i++) {
        leftList.push_back(list[i]);
    }
    // Creamos lista derecha
    vector<T> rightList;
    for (int j=mid+1; j<=right; j++) {
        rightList.push_back(list[j]);
    }
    // Comparamos mientras haya elementos en las dos listas por comparar
    // crear un índice auxiliar para determinar a donde vamos a mover el valor menor
    int auxIndex = left;
    // Inicializamos los índices para recorrer las dos tablas
    int leftIndex = 0;
    int rightIndex = 0;
    while (leftIndex < leftList.size() && rightIndex < rightList.size()) {
        // Comparamos los valores de la lista izquierda con los de la derecha
        if (leftList[leftIndex] < rightList[rightIndex]) {
            // El de la izquierda es menor
            list[auxIndex] = leftList[leftIndex];
            // Incremento leftIndex
            leftIndex++;
        } else {
            // El de la derecha es mayor
            list[auxIndex] = rightList[rightIndex];
            // Incremento rightIndex
            rightIndex++;
        }
        // Incremento auxIndex
        auxIndex++;   
    }
    // Vaciamos los valores restantes de la izquierda
    while (leftIndex < leftList.size()) {
        // El de la izquierda es menor
        list[auxIndex] = leftList[leftIndex];
        // Incremento leftIndex
        leftIndex++;
        // Incremento auxIndex
        auxIndex++;
    }
    // Vaciamos los valores restantes de la derecha
    while (rightIndex < rightList.size()) {
        // El de la derecha es mayor
        list[auxIndex] = rightList[rightIndex];
        // Incremento rightIndex
        rightIndex++;
        // Incremento auxIndex
        auxIndex++;
    }
}

template<class T>
void mergeSort(vector<T> &list, int left, int right) {
    // Condición de control cuando solo sea un elemento
    if (left < right) {
        // Calculamos el índice del medio
        int mid = left + (right - left) / 2;
        // Ordenamos la lista del lado izquierdo (left->mid)
        mergeSort(list, left, mid);
        // Ordenamos la lista del lado derecho (mid+1 -> right)
        mergeSort(list, mid+1, right);
        // Se realiza el merge para ordenar la lista
        merge(list, left, mid, right);
    }
}

template<class T>
int getPivot(vector<T> &list, int left, int right) {
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
void quickSort(vector<T> &list, int left, int right) {
    // Condición de control mientras left sea menor que right
    if (left < right) {
        // Obtener el índice final del privote
        int pivot = getPivot(list, left, right);
        // Ordenamos la lista del lado izquierdo
        quickSort(list, left, pivot-1);
        // Ordenamos la lista del lado derecho
        quickSort(list, pivot+1, right);
    }
}

int main() {

    // Semilla para generar números aleatorios
    srand(time(0));
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    vector<int> list = {15, 7, 3, 9, 12, 5, 2};
    vector<int> listAux;
    print(list);
    cout << "Ordenamiento por intercambio" << endl;
    int comparisons = 0;
    int swaps = 0;
    listAux = list;
    startTime(begin);
    swapSort(listAux, comparisons, swaps);
    getTime(begin, end);
    print(listAux);
    cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;
    cout << "Ordenamiento por burbuja" << endl;
    comparisons = 0;
    swaps = 0;
    listAux = list;
    startTime(begin);
    bubbleSort(listAux, comparisons, swaps);
    getTime(begin, end);
    print(listAux);
    cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;
    cout << "Ordenamiento por selección" << endl;
    comparisons = 0;
    swaps = 0;
    listAux = list;
    startTime(begin);
    selectionSort(listAux, comparisons, swaps);
    getTime(begin, end);
    print(listAux);
    cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;
    cout << "Ordenamiento por inserción" << endl;
    comparisons = 0;
    swaps = 0;
    listAux = list;
    startTime(begin);
    insertionSort(listAux, comparisons, swaps);
    getTime(begin, end);
    print(listAux);
    cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;
    cout << "Ordenamiento por merge" << endl;
    listAux = list;
    startTime(begin);
    mergeSort(listAux, 0, listAux.size()-1);
    getTime(begin, end);
    print(listAux);

    
    cout << "Ordenamiento rápido" << endl;
    listAux = list;
    startTime(begin);
    quickSort(listAux, 0, listAux.size()-1);
    getTime(begin, end);
    print(listAux);



    return 0;
}
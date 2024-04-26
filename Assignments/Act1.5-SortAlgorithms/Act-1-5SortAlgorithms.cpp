//Mauricio Zavala Sánchez
//A00837332
//ITC
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para obtener el tiempo inicial
void startTime(chrono::high_resolution_clock::time_point &begin) {
    begin = chrono::high_resolution_clock::now();
}

// Función para obtener el tiempo transcurrido
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) {
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

    cout << "Tiempo de ejecución: " << elapsed.count() << " milisegundos." << endl;
}

// Función para imprimir una lista
template<class T>
void printList(const vector<T> &list) {
    for (const T &element : list) {
        cout << element << " ";
    }
    cout << endl;
}

// Función para crear una lista de datos aleatorios
template<class T>
void createRandomList(vector<T> &list, int size) {
    list.clear();
    for (int i = 0; i < size; i++) {
        T value = static_cast<T>(rand() % 100); // Valores aleatorios entre 0 y 99
        list.push_back(value);
    }
}

// Función de intercambio para ordenamiento
template<class T>
void swap(vector<T> &list, int a, int b) {
    T temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

// Implementación del algoritmo de ordenamiento adicional (swapSort)
template<class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps) {
    int n = list.size();
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (list[i] > list[j]) {
                swap(list, i, j);
                swaps++;
            }
        }
    }
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

// Implementación de la búsqueda secuencial
template<class T>
bool sequentialSearch(const vector<T> &list, const T &key, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < list.size(); i++) {
        comparisons++;
        if (list[i] == key) {
            return true;
        }
    }
    return false;
}

// Implementación de la búsqueda binaria (requiere una lista ordenada)
template<class T>
bool binarySearch(const vector<T> &list, const T &key, int &comparisons) {
    comparisons = 0;
    int left = 0;
    int right = list.size() - 1;

    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;

        if (list[mid] == key) {
            return true;
        } else if (list[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<int> intList;
    int comparisons = 0;
    int swaps = 0;
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    int choice;
    do {
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Crear lista de enteros aleatorios" << endl;
        cout << "2. Ordenar lista con swapSort" << endl;
        cout << "3. Ordenar lista con otros algoritmos (implementa estos algoritmos)" << endl;
        cout << "4. Buscar elemento en la lista (búsqueda secuencial)" << endl;
        cout << "5. Buscar elemento en la lista (búsqueda binaria)" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int size;
                cout << "Ingrese el tamaño de la lista: ";
                cin >> size;
                createRandomList(intList, size);
                cout << "Lista de enteros aleatorios creada." << endl;
                break;
            }
            case 2: {
                vector<int> temp = intList;
                startTime(begin);
                swapSort(temp, comparisons, swaps);
                getTime(begin, end); // Calcula el tiempo de ejecución aquí
                cout << "Lista ordenada con swapSort:" << endl;
                printList(temp);
                cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;
                cout << "Tiempo de ejecución: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milisegundos." << endl;
                break;
            }

            case 3: {
                int algoChoice;
                do {
                    cout << "\nAlgoritmos de ordenamiento disponibles:" << endl;
                    cout << "1. Bubble Sort" << endl;
                    cout << "2. Selection Sort" << endl;
                    cout << "3. Insertion Sort" << endl;
                    cout << "4. Merge Sort" << endl;
                    cout << "5. Quick Sort" << endl;
                    cout << "6. Regresar al menú principal" << endl;
                    cout << "Ingrese su elección: ";
                    cin >> algoChoice;

                    switch (algoChoice) {
                        case 1: {
                            vector<int> temp = intList;
                            startTime(begin);
                            bubbleSort(temp, comparisons, swaps);
                            getTime(begin, end);
                            cout << "Lista ordenada con Bubble Sort:" << endl;
                            printList(temp);
                            cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;
                            cout << "Tiempo de ejecución: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milisegundos." << endl;
                            break;
                        }
                        case 2: {
                            vector<int> temp = intList;
                            startTime(begin);
                            selectionSort(temp, comparisons, swaps);
                            getTime(begin, end);
                            cout << "Lista ordenada con Selection Sort:" << endl;
                            printList(temp);
                            cout << "Comparaciones: " << comparisons << " - Intercambios: " << swaps << endl;
                            cout << "Tiempo de ejecución: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milisegundos." << endl;
                            break;
                        }
                        // Resto de los casos...
                    }
                } while (algoChoice != 6);
                break;
            }
            case 4: {
                int key;
                cout << "Ingrese el elemento a buscar: ";
                cin >> key;
                int comparisonsSequential = 0;
                bool foundSequential = sequentialSearch(intList, key, comparisonsSequential);
                cout << "Búsqueda secuencial:" << endl;
                cout << (foundSequential ? "Elemento encontrado en la lista." : "Elemento no encontrado en la lista.") << endl;
                cout << "Comparaciones realizadas: " << comparisonsSequential << endl;
                break;
            }
            case 5: {
                int key;
                cout << "Ingrese el elemento a buscar (lista debe estar ordenada): ";
                cin >> key;

                int algoChoice;
                do {
                    cout << "\nAlgoritmos de búsqueda disponibles:" << endl;
                    cout << "1. Búsqueda secuencial" << endl;
                    cout << "2. Búsqueda binaria" << endl;
                    cout << "3. Regresar al menú principal" << endl;
                    cout << "Ingrese su elección: ";
                    cin >> algoChoice;

                    switch (algoChoice) {
                        case 1: {
                            int comparisonsSequential = 0;
                            startTime(begin);
                            bool foundSequential = sequentialSearch(intList, key, comparisonsSequential);
                            getTime(begin, end);
                            cout << "Búsqueda secuencial:" << endl;
                            cout << (foundSequential ? "Elemento encontrado en la lista." : "Elemento no encontrado en la lista.") << endl;
                            cout << "Comparaciones realizadas: " << comparisonsSequential << endl;
                            cout << "Tiempo de ejecución: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milisegundos." << endl;
                            break;
                        }
                        case 2: {
                            int comparisonsBinary = 0;
                            startTime(begin);
                            bool foundBinary = binarySearch(intList, key, comparisonsBinary);
                            getTime(begin, end);
                            cout << "Búsqueda binaria:" << endl;
                            cout << (foundBinary ? "Elemento encontrado en la lista." : "Elemento no encontrado en la lista.") << endl;
                            cout << "Comparaciones realizadas: " << comparisonsBinary << endl;
                            cout << "Tiempo de ejecución: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milisegundos." << endl;
                            break;
                        }
                        case 3: {
                            cout << "Regresando al menú principal." << endl;
                            break;
                        }
                        default: {
                            cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
                        }
                    }
                } while (algoChoice != 3);
                break;
            }
        }
    } while (choice != 6);

    return 0;
}


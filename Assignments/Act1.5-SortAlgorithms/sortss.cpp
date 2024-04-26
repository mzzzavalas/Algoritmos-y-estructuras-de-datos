//Intentos fallidos

#include <iostream>
using namespace std;

void print(int miVector[],int size){
    for (int i = 0; i < size; i++) {
        cout << miVector[i] << " ";
    }
}

void SwapSort(int miVector[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            
            if (miVector[i] > miVector[j]) {
                swap(miVector[i], miVector[j]);
            }
        }
    }
}

void BubleSort(int miVector[], int size){
    int iter=0;
    bool control=true;
    while(iter<size-1 && control){
        control=false;
        for(int j=1;j<size-iter;j++){
            if (miVector[j-1]>miVector[j]){
                swap(miVector[j-1],miVector[j]);
            }
        }
        iter++;
    }
}

// Intercambio por seleccion
template<class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps){
    int mayor=list[0];
    for(int i=0;i<list.size();i++){
        comparisons++;
        if (list[i]>=mayor){
            mayor=list[i];
            swap(list[i],list[list.size()-1]);
            swaps++;
        }
        for (int j=0;j<list.size();j++){
            comparisons++;
            if (list[j]>list[i]){
                swap(list, j,i);
                swaps++;
            }
        }
    }
}


//Intercambio por insertion
template<class T>
void insertionSort(vector<T> &list, int &comparisons, int &swaps){
    int mayor=list[0];
    for(int i=1;i<list.size();i++){
        if(list[i]>mayor){
            swap(list[0],list[i]);
        }
    }
}



int main() {
    int miVector[7] = {15, 7, 3, 9, 12, 5, 2};
    int size = 7;
    
    
    BubleSort(miVector,size);
    print(miVector,size);
    


    return 0;
}

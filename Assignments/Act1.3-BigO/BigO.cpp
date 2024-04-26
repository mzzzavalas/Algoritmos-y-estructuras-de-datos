//Mauricio Zavala Sánchez
//A00837332
//ITC
#include <iostream>

using namespace std;

void imprimirVector(int miVector[], int& suma) {
    for(int i = 0; i < 5; i++) {
        if (miVector[i] % 2 != 0) {
            suma += miVector[i];
        }
    }
}

void imprimirVectorRecursion(int miVector[], int& suma, int i) {
    if (i < 5) {
        if (miVector[i] % 2 != 0) {
            suma += miVector[i];
        }
        imprimirVectorRecursion(miVector, suma, i + 1);  
    }
}

int main() {
    int miVector[5] = {1, 2, 3, 4, 5};
    int sumaIterativa = 0;
    int sumaRecursiva = 0;
    int i = 0;

    imprimirVector(miVector, sumaIterativa);

    cout << "La suma de los numeros impares en el vector (iterativo) es: " << sumaIterativa << endl;

    imprimirVectorRecursion(miVector, sumaRecursiva, i);

    cout << "La suma de los numeros impares en el vector (recursivo) es: " << sumaRecursiva << endl;

    return 0;
}







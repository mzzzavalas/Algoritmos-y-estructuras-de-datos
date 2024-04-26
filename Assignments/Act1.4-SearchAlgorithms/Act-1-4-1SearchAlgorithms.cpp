//Mauricio Zavala Sánchez
//A00837332
//ITC
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
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

    printf("Tiempo de ejecucion: %.8f seconds.\n", elapsed.count() * 1e-9);
}

// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        int num = rand() % 1000000 + 1;
        list.push_back(num);
    }
}

int secuencial(vector<int> &list, int n)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == n)
        {
            return i; // Retorna la posición donde se encontró el elemento
        }
    }
    return -1; // Retorna -1 si no se encuentra el elemento en la lista
}

int binario(vector<int> &list, int n, int l, int r, int size, int mid){
    while(l<=r){
        mid=l+(r-l)/2;
        if(list[mid]==n){
            return mid;
        }else
        if(n<list[mid]){
            r=mid-1;
        }else
        if(n>=list[mid]){
            l=mid+1;
        }
    }
    return -1;
    
}

int main()
{

    // Semilla para generar números aleatorios
    srand(time(0));
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;

    // Crear una lista de 1000000 de enteros
    vector<int> list;

    createListInt(list, 10000);
    sort(list.begin(), list.end());
    /*/for (auto el : list) {
        cout << el << " ";
    }/*/

    

    // Secuencial
    int numero;
    int size=10000;
    int l=0;
    int r=size-1;
    int mid=0;
    do
    {
        cout << "Digita un numero del 1 al 1000000: ";
        cin >> numero;
        
        if (numero != 0)
        {
            startTime(begin);
            int position = secuencial(list, numero);
            cout<<"Secuencial - ";
            getTime(begin, end);
            startTime(begin);
            int position2= binario(list,numero,l,r,size,mid);
            cout<<"Binaria - ";
            getTime(begin, end);
            if (position&&position2 != -1)
            {
                cout << "La secuencial se encontró en la posicion: " << position << endl;
                
                cout << "La binaria se encontró en la posicion: " << position2 << endl;
                
            }
            else if(position||position2==-1)
            {
                cout << "No se encontro el elemento en la lista." << endl;
                getTime(begin, end);
            }

        }
    } while (numero != 0);
    
    cout << "Terminaste la entrada de números." << endl;
     

    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "Log.h"
using namespace std;
bool compareLogs(const Log& log1, const Log& log2);
string mesAStringNumerico(const string &mes);
template<class T>
void swap(vector<T> &list, int a, int b);
template<class T>
void print(vector<T> list);
template<class T>
int getPivot(vector<T> &list, int left, int right);
template<class T>
void quickSort(vector<T> &list, int left, int right);
ostream& operator<<(ostream& os, const Log& log);

int main() {

    // Archivo de entrada
    ifstream fileIn("prueba.txt");
    // Archivo de salida
    ofstream fileOut("output608.out");
    // Variable auxiliar para guardar el contenido del renglón leido
    string line;
    // Variable auxiliar para guardar el contenido de cada palabra del campo message
    string word;
    // Variables auxiliares para guardar el contenido de cada campo del archivo
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    vector<Log> logs; // Vector para almacenar objetos Log
    // Variable auxiliar para guardar el contador de registros
    int cont = 0;
    // Ciclo para leer todo los renglones del archivo de entrada
    while (getline(fileIn, line)) {
    // Creamos una variable auxiliar ss para recorrer campo por campo
    stringstream ss(line);
    // Guardamos la información de cada campo en la variable auxiliar correspondiente
    ss >> month >> day >> year >> time >> ip;
    month = mesAStringNumerico(month);
    // Creamos una variable para el campo message y almacenamos las palabras en ella
    string message;
    ss >> word; // Leemos la primera palabra
    message = word;
    while (ss >> word) {
        message = message + " " + word; // Concatenamos las palabras
    }
        //cout << month << " " << day << " " << year << " " << time << " " << ip << " " << message << endl;
        //Almacenamos los datos en la estrucutra
        Log log(year, month, day, time, ip, message);
        logs.push_back(log);
        // Incrementamos el contador de registros
        cont++;
    }
    cout << "Cantidad de registros: " << cont << endl;

    //Sort funcional
    vector<Log> listAux(logs);
    cout << "Ordenamiento rápido" << endl;
    listAux = logs;
    
    quickSort(listAux, 0, listAux.size()-1);
    // Imprimir los registros ordenados
    //print(listAux);
    // Imprimir los registros ordenados
    
    for (const Log& listAux : listAux) {
        cout << listAux.month << " " << listAux.day << " " << listAux.year << " " << listAux.time << " " << listAux.ip << " " << listAux.message << endl;
    }
    

    string inicio, fin;
    int l, r, mid, mid2;
    string year1,month1,day1,time1;
    string year2,month2,day2,time2;

    do {
        cout << "Digite fecha y horas de inicio; " << endl;
        cout << "AÑ0: "; cin >> year1;
        cout << "MES: "; cin >> month1;
        cout << "DIA: "; cin >> day1;
        cout << "Tiempo: "; cin >> time1;
        inicio = year1 + month1 + day1 + time1;

        l = 0;
        r = cont - 1;
        mid = 0;
        

        while (l <= r) {
            mid = l + (r - l) / 2;
            string fechaLog = listAux[mid].year + listAux[mid].month + listAux[mid].day + listAux[mid].time;
            if (fechaLog == inicio) {
                cout << mid << endl;
                //found = true; // Marcar que se encontró una coincidencia
                break; // Salir del bucle mientras se ha encontrado una coincidencia
            } else if (inicio < fechaLog) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        l = 0;
        r = cont - 1;
        mid2 = 0;

        cout << "Digite fecha y horas de fin: " << endl;
        cout << "AÑ0: "; cin >> year2;
        cout << "MES: "; cin >> month2;
        cout << "DIA: "; cin >> day2;
        cout << "Tiempo: "; cin >> time2;
        fin = year2 + month2 + day2 + time2;

        while (l <= r) {
            mid2 = l + (r - l) / 2;
            string fechaLog = listAux[mid2].year + listAux[mid2].month + listAux[mid2].day + listAux[mid2].time;
            if (fechaLog == fin) {
                cout << mid2 << endl;
                //found = true; // Marcar que se encontró una coincidencia
                break; // Salir del bucle mientras se ha encontrado una coincidencia
            } else if (fin < fechaLog) {
                r = mid2 - 1;
            } else {
                l = mid2 + 1;
            }
        }
        if(listAux[mid2].year + listAux[mid2].month + listAux[mid2].day + listAux[mid2].time>fin){mid2=mid2-1;}
        cout << mid2 << endl;
    }while (inicio>fin);
    //For de logs en el rango mid1 y mid2
    cout << mid << endl;
    cout << mid2 << endl;
     for (int i=mid;i<=mid2;i++) {
        cout << listAux[i].month << " " << listAux[i].day << " " << listAux[i].year << " " << listAux[i].time << " " << listAux[i].ip << " " << listAux[i].message << endl;
   
     }
    

   
    return 0;
}





bool compareLogs(const Log& log1, const Log& log2) {
    // Concatenamos las partes de la fecha y hora para compararlas como cadenas
    string date1 = log1.year + log1.month + log1.day + log1.time;
    string date2 = log2.year + log2.month + log2.day + log2.time;
    
    return date1 < date2;
}



string mesAStringNumerico(const string &mes) {
    map<string, string> meses = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}
    };

    auto it = meses.find(mes);
    if (it != meses.end()) {
        return it->second;
    } else {
        return "Mes no válido";
    }
}

template<class T>
void swap(vector<T> &list, int a, int b) {
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

template<class T>
void print(vector<T> list) {
    for (auto el : list) {
        cout << el << " "<<endl;
    }
    cout << endl;
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
        if (list[index].year+list[index].month+list[index].day+list[index].time < list[pivot].year+list[pivot].month+list[pivot].day+list[pivot].time) {
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

ostream& operator<<(ostream& os, const Log& log) {
    os << log.year << " " << log.month << " " << log.day << " " << log.time << " " << log.ip << " " << log.message;
    return os;
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <map>
using namespace std;
#include "Log.h"
#include "Heap.h"
#include "MinHeap.h"
#include "BST.h"

//Heap Sort
template <class T>
void heapSort(vector<T> &list, string order);
template <class T>
void print(vector<T> list);

int main(){

     // Archivo de entrada
    ifstream fileIn("log608-3.txt");
    ofstream output_file("output608-1.out");
    ofstream output_file2("output608-2.out");
    vector<Log> logip;
    ifstream fileIn2("output608-1.out");
    ifstream fileIn22("output608-1.out");

    Heap<pair<int, string>> maxHeap;
    map<string, int> ipCount;
    BST<string> bst;
    string line2;
    string ipUsuario;
    int cont2=0;
    int k = 10; 
    int contBST=0;

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
    ss >> month >> day >> year >> time >> ip >>message;
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
    for(int i=0;i<cont;i++){
        bst.insert(logs[i].ip);
        }

    int choice;
    while (true){
        cout<<"Heap Menu: "<<endl;
        cout<<"1. Ordena los datos por IP, fecha y hora de mayor a menor."<<endl;
        cout<<"2. Ordena los datos por IP, fecha y hora de menor a mayor. "<<endl;
        cout<<"3. Despliega en pantalla cuales son las 10 ip's con mayor número de registros."<<endl;
        cout<<"4. Búsqueda de una ip en un árbol binario de búsqueda."<<endl;
        cout<<"5. Exit."<<endl;
        cout<<"Enter you choice"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
            //Mayor a menor
            cout << "Cantidad de registros: " << cont << endl;
            heapSort(logs, "asc");
            //print(logs);
            //Declara output_file
            if (output_file.is_open()) {
                for (const Log& log : logs) {
                    output_file << log;
                }
                output_file.close();
                cout << "Resultados del ordenamiento almacenados en 'output608-1.out'" << endl;
            } else {
                cerr << "Ya se realizo esta acción. No se pudo abrir el archivo 'output608.txt' para escritura" << endl;
            }
            break;

            case 2:
            //Menor a mayor
            heapSort(logs, "desc");
            //print(logs);
            //Declaracion de output_file2
            if (output_file2.is_open()) {
                for (const Log& log : logs) {
                    output_file2 << log;
                }
                output_file2.close();
                cout << "Resultados del ordenamiento almacenados en 'output608-2.out'" << endl;
            } else {
                cerr << "Ya se realizo esta accióm. No se pudo abrir el archivo 'output608-2.out' para escritura" << endl;
            }
            break;

            case 3:

            // Verifica si el archivo está abierto
            if (fileIn22.is_open()) {
                // Obtiene la posición actual en el archivo
                streampos currentPosition = fileIn22.tellg();

                // Se desplaza al final del archivo
                fileIn22.seekg(0, ios::end);

                // Obtiene la posición al final del archivo
                streampos endPosition = fileIn22.tellg();

                // Compara las posiciones
                if (currentPosition == endPosition) {
                    cout << "El archivo está vacío.  Debe realizar la opcion 1 antes." << endl;
                    break;
                } else {
                    cout << "El archivo no está vacío." << endl;
                    
                }

                // Cierra el archivo
                fileIn22.close();
            } else {
                cerr << "No se pudo abrir el archivo." << endl;
            }


            

            
            while(getline(fileIn2,line2)){
                stringstream ss(line2);

                ss >> month >> day >> year >> time >> ip;
                string message;
                ss >> word; // Leemos la primera palabra
                message = word;
                while (ss >> word) {
                    message = message + " " + word;
                }

                Log log1(year, month, day, time, ip, message);
                logip.push_back(log1);
                cont2++;
            }
            heapSort(logip, "asc");

            //Imprimir los 10 ips con mayor número de registros
            // Número de IP que deseas mostrar
             // Creamos un Max Heap para almacenar el número de registros e IP

             // Contador para llevar un registro de las IP
            

            // Recorre los registros y cuenta las IP
            for (const Log& log : logip) {
                ipCount[log.ip]++;
            }

            // Inserta los registros en el Max Heap
            for (const auto& entry : ipCount) {
                maxHeap.push({entry.second, entry.first});
            }

            // Muestra las 10 IP con mayor número de registros
            cout << "Las 10 IP con mayor número de registros son:" << endl;
            for (int i = 0; i < k && !maxHeap.isEmpty(); i++) {
                pair<int, string> top = maxHeap.pop();
                cout << "IP: " << top.second << " - Número de registros: " << top.first << endl;
            }
            break;

            case 4:
            

            cout<<"Type the IP: ";
            cin>>ipUsuario;
            for(int i=0;i<cont;i++){
                if(!bst.isEmpty()){
                    if(bst.find(ipUsuario)==true){
                        contBST++;
                        bst.remove(ipUsuario);
                    }
                }else{
                    cout<<"Log is empty"<<endl;
                }
            }
            if(contBST>0){
            cout<<ipUsuario<<" was found "<<contBST<<" times."<<endl;
            }else{
            cout<<ipUsuario<<" was NOT found in the Log."<<endl;
            }
            break;

            case 5:
            cout << "Exiting program." << endl;
            return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;





        }
    }





return 0;
}





// Heap Sort
template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "asc") {
        // Creamos un heap en base a la lista
        Heap<T> heap(list);
        // Ciclo para sacar todos los elementos del heao y agregarlos a la lista
        for (int i=0; i<list.size(); i++) {
            list[i] = heap.pop();
        }
    } else {
        if (order == "desc") {
            // Creamos un heap en base a la lista
            MinHeap<T> heap(list);
            // Ciclo para sacar todos los elementos del heao y agregarlos a la lista
            for (int i=0; i<list.size(); i++) {
                list[i] = heap.pop();
            }
        } 
    }
}

template <class T>
void print(vector<T> list) {
    for (auto el : list) {
        cout << el << " ";
    }
    cout << endl;
}
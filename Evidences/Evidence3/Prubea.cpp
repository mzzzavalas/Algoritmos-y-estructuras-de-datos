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
    ifstream fileIn("prueba.txt");
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

    //Mayor a menor
    cout << "Cantidad de registros: " << cont << endl;
    heapSort(logs, "asc");
    print(logs);
    ofstream output_file("output608-1.out");
    if (output_file.is_open()) {
        for (const Log& log : logs) {
            output_file << log;
        }
        output_file.close();
        cout << "Resultados del ordenamiento almacenados en 'output608.txt'" << endl;
    } else {
        cerr << "No se pudo abrir el archivo 'output608.txt' para escritura" << endl;
    }

    //Menor a mayor
    heapSort(logs, "desc");
    print(logs);
    ofstream output_file2("output608-2.out");
    if (output_file2.is_open()) {
        for (const Log& log : logs) {
            output_file2 << log;
        }
        output_file2.close();
        cout << "Resultados del ordenamiento almacenados en 'output608.txt'" << endl;
    } else {
        cerr << "No se pudo abrir el archivo 'output608.txt' para escritura" << endl;
    }




    //Ips con mayor numero de regristros
    // Primer ciclo for de 0 a size
    // Se realiza top y se guarda en una variable auxiliar
    // se realiza pop para seguir comparando
    // segundo cislo de 0 a size
    // se compara conntodos los logs
    // contador de cuantos ip eran iguales
    // funcion que añade 
    vector<Log> logip;
    int cont2=0;
    ifstream fileIn2("output608-1.out");
    string line2;
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
    cout << "Cantidad de registros: " << cont << endl;
    cout << "Cantidad de registros: " << cont2 << endl;

    heapSort(logip, "asc");
    /*
    Heap<string> heap;
    for(int i=0;i<cont;i++){
        heap.push(logip[i].ip);
    }

    int contIP=1;
    string ip1,ip2;
    vector<string> IPS;
    IPS.push_back(heap.top());
    

    for (int i=1;i<cont;i++) {
        ip1=heap.top();
        cout << heap.pop() << " ";
        ip2=heap.top();
        if(ip1!=ip2){
            IPS.push_back(ip2);
            contIP++;
        }
    } cout<<endl;
    
    cout<<contIP<<endl;

    for(int i=0;i<contIP;i++){
        cout<<IPS[i]<<endl;

    }*/

    //Imprimir los 10 ips con mayor número de registros
    int k = 10; // Número de IP que deseas mostrar
    Heap<pair<int, string>> maxHeap; // Creamos un Max Heap para almacenar el número de registros e IP

    // Contador para llevar un registro de las IP
    map<string, int> ipCount;

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
    


    // Busqueda de ip
    BST<string> bst;
    for(int i=0;i<cont;i++){
        bst.insert(logs[i].ip);
    }

    string ipUsuario;
    cout<<"Type the IP: ";
    cin>>ipUsuario;
    //bst.print();
    int contBST=0;
    for(int i=0;i<cont2;i++){
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
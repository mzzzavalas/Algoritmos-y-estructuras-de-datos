#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "LogIP.h"
#include "DoublyLinkedList.h"



int main() {

    // Archivo de entrada
    ifstream fileIn("pruba.txt");
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
    // Lista de elementos
    DoublyLinkedList<LogIP> logsIP;
    // Variable auxiliar para guardar el contador de registros
    int cont = 0;
    // Ciclo para leer todo los renglones del archivo de entrada
    while (getline(fileIn,line)) { 
        // Creamos una variable auxiliar ss para recorrer campo por campo
        stringstream ss(line);
        // Guardamos la información de cada campo en la variable auxiliar correspondiente
        ss >> month >> day >> year >> time >> ip >> message;
        // Ciclo para recorrer cada palabra del campo message
        while (ss >> word) {
            message = message + " " + word;
        }
        LogIP logIP(year, month, day, time, ip, message);
        cout << logIP;
        logsIP.addLast(logIP);
        // cout << month << " " << day << " " << year << " " << time << " " << ip << " " << message << endl;
        // Incrementamos el contador de registros
        cont++;
    }
    cout << "Cantidad de registros: " << cont << endl;
    cout << "Ascendiente" << endl;
    logsIP.print("asc");
    cout << "Descendiente" << endl;
    logsIP.print("desc");

    //Sort por fecha y hora
    cout<<logsIP.getSize()<<endl;
    cout << "Ordenamiento rápido" << endl;
    logsIP.Sort();
//Guardar lista ordenada en archivo de salida llamado output602-1.out 
    // Archivo de salida
    ofstream fileOut("output602-1.out");
    for (int i = 0; i < logsIP.getSize(); i++) {
        fileOut << logsIP[i];
    }
    fileOut.close();
    logsIP.print("des");
    cout << "Resultados del ordenamiento almacenados en 'output608.out'" << endl;
    

    //Sort por  ip, fecha y hora


    

    


    

    return 0;
}
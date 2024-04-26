#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "Log.h"
#include "LogIP.h"
#include "DoublyLinkedList.h"




int main() {

    // Archivo de entrada
    ifstream fileIn("log608-2.txt");
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
    DoublyLinkedList<Log> logs;
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
        Log log(year, month, day, time, ip, message);
        LogIP logIP(year, month, day, time, ip, message);
        // cout << log;
        logs.addLast(log);
        logsIP.addLast(logIP);
        // cout << month << " " << day << " " << year << " " << time << " " << ip << " " << message << endl;
        // Incrementamos el contador de registros
        cont++;
    }
    /*cout << "Cantidad de registros: " << cont << endl;
    cout << "Ascendiente" << endl;
    logs.print("asc");
    cout << "Descendiente" << endl;
    logs.print("desc");*/

    //Sort por fecha y hora
    cout<<logs.getSize()<<endl;
    cout << "Ordenamiento rápido Fecha y Hora" << endl;
    logs.Sort();
    //Guardar lista ordenada en archivo de salida llamado output602-1.out 
    // Archivo de salida
    ofstream fecha_hora_file("output602-1.out");
    for (int i = 0; i < logs.getSize(); i++) {
        fecha_hora_file << logs[i];
    }
    fecha_hora_file.close();
    //logs.print("asc");
    cout << "Resultados del ordenamiento almacenados en 'output608.out'" << endl;

    //Sort por  ip, fecha y hora
    cout<<logsIP.getSize()<<endl;
    cout << "Ordenamiento rápido Ip, Fecha y Hora" << endl;
    logsIP.Sort();
    //Guardar lista ordenada en archivo de salida llamado output602-2.out
    // Archivo de salida
    ofstream ip_fecha_hora("output602-2.out");
    for (int i = 0; i < logsIP.getSize(); i++) {
        ip_fecha_hora << logsIP[i];
    }
    ip_fecha_hora.close();
    //logsIP.print("asc");
    cout << "Resultados del ordenamiento almacenados en 'output608.out'" << endl;

    //RANGO
    int inicio, fin;
    string ip1,ip2;
    DoublyLinkedList<LogIP> logsR;
    do {
        cout << "Digite ip inicio; " << endl;
        ip1="10.14.3.84";
        //cout << "IP: "; cin >> ip1;
        cout << "Digite ip fin; " << endl;  
        ip2="10.14.164.127";
        //cout << "IP: "; cin >> ip2;
        // Busqeda secuencial de ip
        for(int i=0; i<logsIP.getSize();i++){
            if (logsIP[i].ip==ip1){
                inicio=i;
            }
        }
        cout<<inicio<<endl;

        for(int i=0; i<logsIP.getSize();i++){
            if (logsIP[i].ip==ip2){
                fin=i;
            }
        }
        cout<<fin<<endl;
        
        for(int i=inicio;i<fin+1;i++){
            logsR.addLast(logsIP[i]);
        }
    }while (inicio>fin);
    cout<<"---------------------------------------------------------------------"<<endl;

    cout << "Rango Ascendiente" << endl;
    //logsR.print("asc");
    ofstream rango_a("iprange602-a.out");
    for (int i = 0; i < logsR.getSize(); i++) {
        rango_a << logsR[i];
    }
    rango_a.close();
    cout<<"---------------------------------------------------------------------"<<endl;

    cout << "Rango descendente" << endl;
    //logsR.print("dec");
    ofstream rango_d("iprange602-d.out");
    for (int i = logsR.getSize()-1; i >= 0; i--) {
        rango_d << logsR[i];
    }
    rango_d.close();
    cout<<"---------------------------------------------------------------------"<<endl;




    //Sumatoria
    //logs.print("asc");
    vector<string> YEARS;
    int contaño=1;
    string año,año2;
    YEARS.push_back(logs[0].year);
    for (int i = 1; i < logs.getSize(); i++) {
        if(logs[i].year!=logs[i-1].year){
            YEARS.push_back(logs[i].year);
            contaño++;
        }
    }
    vector<string> MONTHS;
    int contipaño=0;
    int contipmes=0;
    cout<<"Cambio de ano: "<<contaño<<endl;
    int contmes=0;
    MONTHS.push_back(logs[0].month);
    for(int i=0;i<contaño;i++){
        contipaño=0;
        for (int k = 0; k < logs.getSize(); k++) {
        if(logs[k].year==YEARS[i]){
            contipaño++;
        }
    }
    cout<<endl;
        cout<<"Suma de ip's por año "<<YEARS[i]<<" es: "<<contipaño<<endl;
        cout<<YEARS[i]<<endl;
        contmes=0;
        for(int j=1;j<logs.getSize();j++){
            if(logs[j].year==YEARS[i]&&logs[j].month!=logs[j-1].month){
                MONTHS.push_back(logs[j].month);
                contmes++;
            }
        }

        

        cout<<"Cambio de mes: "<<contmes<<endl;
        contipmes=0;
        
            for(int l=0;l<contmes;l++){
                for(int k=0;k<contipaño;k++){
                    if(logs[k].month==MONTHS[l]){
                        contipmes++;
                    }
                }  
                cout<<"Suma de ip's por mes del año "<<YEARS[i]<<" es: "<<MONTHS[l]<<" "<<contipmes<<endl; 
                
                contipmes=0;
            }

    }
    /*
    cout<<"---------------------------------------------------------------------"<<endl;
    int JAN=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[0]){
            JAN++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Jan "<<JAN<<endl; 
    int FEB=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[1]){
            FEB++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Feb "<<FEB<<endl;
    int MAR=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[2]){
            MAR++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Mar "<<MAR<<endl;
    int APR=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[3]){
            APR++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Apr "<<APR<<endl;
    int MAY=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[4]){
            MAY++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: May "<<MAY<<endl;
    int JUN=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[5]){
            JUN++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Jun "<<JUN<<endl;
    int JUL=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[6]){
            JUL++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Jul "<<JUL<<endl;
    int AUG=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[7]){
            AUG++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Aug "<<AUG<<endl;
    int SEP=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[8]){
            SEP++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Sep "<<SEP<<endl;
    int OCT=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[9]){
            OCT++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Oct "<<OCT<<endl;
    int NOV=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[10]){
            NOV++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Nov "<<NOV<<endl;
    int DEC=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[0]&&logs[i].month==MONTHS[11]){
            DEC++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[0]<<" es: Dec "<<DEC<<endl;

    cout<<"---------------------------------------------------------------------"<<endl;

    JAN=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[0]){
            JAN++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Jan "<<JAN<<endl;
    FEB=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[1]){
            FEB++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Feb "<<FEB<<endl;
    MAR=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[2]){
            MAR++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Mar "<<MAR<<endl;
    APR=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[3]){
            APR++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Apr "<<APR<<endl;
    MAY=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[4]){
            MAY++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: May "<<MAY<<endl;
    JUN=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[5]){
            JUN++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Jun "<<JUN<<endl;
    JUL=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[6]){
            JUL++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Jul "<<JUL<<endl;
    AUG=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[7]){
            AUG++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Aug "<<AUG<<endl;
    SEP=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[8]){
            SEP++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Sep "<<SEP<<endl;
    OCT=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[9]){
            OCT++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Oct "<<OCT<<endl;
    NOV=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[10]){
            NOV++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Nov "<<NOV<<endl;
    DEC=0;
    for(int i=0;i<logs.getSize();i++){
        if(logs[i].year==YEARS[1]&&logs[i].month==MONTHS[11]){
            DEC++;
        }
    }
    cout<<"Suma de ip's por mes del año "<<YEARS[1]<<" es: Dec "<<DEC<<endl;
    */


    

    cout<<"---------------------------------------------------------------------"<<endl;

    return 0;
}


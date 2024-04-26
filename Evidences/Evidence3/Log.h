#pragma once
#include <string>
#include <map>
using namespace std;

struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    string getMonth();
    string key; // Ip + Fecha + Hora
    Log();

    Log(string year, string month, string day, string time, string ip, string message);
    bool operator<(const Log& log) const;
    bool operator>(const Log& log) const;
    bool operator==(const Log& log) const;
    Log& operator=(const Log& log);
    bool operator!=(const Log& log) const;
    friend ostream& operator<<(ostream& os, Log log); 
    string keyIpGenerator();
    string newIP(); // Para poder comparar las ips
};


Log::Log() {
    // vacio
}

// Constructor
Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    // Generamos la llave con una función que convierta el mes a número y concatene año, mes, día y hora
    key = keyIpGenerator();
}

// Sobrecarga de operadores de comparación
bool Log::operator<(const Log& log) const {
    return key < log.key;
}

bool Log::operator>(const Log& log) const {
    return key > log.key;
}

bool Log::operator==(const Log& log) const {
    return key == log.key;
}

// Sobrecarga del operador de asignación
Log& Log::operator=(const Log& log) {
    if (this != &log) {
        // Copiar los miembros de la clase
        this->year = log.year;
        this->month = log.month;
        this->day = log.day;
        this->time = log.time;
        this->ip = log.ip;
        this->message = log.message;
        this->key = log.key;
    }
    return *this;
}

ostream& operator<<(ostream& os, Log log) {
    os << log.month << " " << log.day << " " << log.year << " " << log.time << " " << log.ip << " " << log.message << endl;
    return os;
}


string Log::getMonth() {
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
    auto it = meses.find(month);
    if (it != meses.end()) {
        return it->second;
    } else {
        return "Mes no válido";
    }
    return month;
}



string Log::keyIpGenerator() {
    string mm = getMonth();
    string ip1 = newIP();
    return ip1 + year + mm + day + time;
}

string Log::newIP() {
    // esta funcion se encargara de agregar 0 a los segmentos de la ip que sean menores a 100
    string ip1 = "";
    string ip2 = "";
    string ip3 = "";
    string ip4 = "";
    int i = 0;
    int j = 0;
    while (ip[i] != '.') {
        ip1 += ip[i];
        i++;
    }
    i++;
    while (ip[i] != '.') {
        ip2 += ip[i];
        i++;
    }
    i++;
    while (ip[i] != '.') {
        ip3 += ip[i];
        i++;
    }       
    i++;
    while (ip[i] != '\0') {
        ip4 += ip[i];
        i++;
    }
    if (ip1.length() == 1) {
        ip1 = "00" + ip1;
    } else if (ip1.length() == 2) {
        ip1 = "0" + ip1;
    }
    if (ip2.length() == 1) {
        ip2 = "00" + ip2;
    } else if (ip2.length() == 2) {
        ip2 = "0" + ip2;
    }
    if (ip3.length() == 1) {
        ip3 = "00" + ip3;
    } else if (ip3.length() == 2) {
        ip3 = "0" + ip3;
    }
    if (ip4.length() == 1) {
        ip4 = "00" + ip4;
    } else if (ip4.length() == 2) {
        ip4 = "0" + ip4;
    }
    return ip1 + ip2 + ip3 + ip4;
}


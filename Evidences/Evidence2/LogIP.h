#pragma once
using namespace std;
#include <string>
#include <map>

struct LogIP {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    string getMonth();
    string keyIp; // Ip + Fecha + Hora
    LogIP();
    LogIP(string year, string month, string day, string time, string ip, string message);
    bool operator<(const LogIP& logIP) const;
    bool operator>(const LogIP& logIP) const;
    bool operator==(const LogIP& logIP) const;
    LogIP& operator=(const LogIP& logIP);
    bool operator!=(const LogIP& logIP) const;
    friend ostream& operator<<(ostream& os, LogIP logIP); 
    string keyIpGenerator();
    string newIP(); // Para poder comparar las ips
};

LogIP::LogIP() {
    // vacio
}

LogIP::LogIP(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    // Generamos la llave con una función que convierta el mes a numero y concatene año, mes, dia y hora
    keyIp = keyIpGenerator();
}


// Sobrecarga de operadores de comparación
bool LogIP::operator<(const LogIP& logIP) const {
    return keyIp < logIP.keyIp;
}

bool LogIP::operator>(const LogIP& logIP) const {
    return keyIp > logIP.keyIp;
}

bool LogIP::operator==(const LogIP& logIP) const {
    
    return keyIp == logIP.keyIp;
}

// Sobrecarga del operador de asignación
LogIP& LogIP::operator=(const LogIP& logIP) {
    if (this != &logIP) {
        // Copiar los miembros de la clase
        this->year = logIP.year;
        this->month = logIP.month;
        this->day = logIP.day;
        this->time = logIP.time;
        this->ip = logIP.ip;
        this->message = logIP.message;
        this->keyIp = logIP.keyIp;
    }
    return *this;
}

bool LogIP::operator!=(const LogIP& logIP) const {
    return keyIp != logIP.keyIp;
}

ostream& operator<<(ostream& os, LogIP logIP) {
    os << "LogIP: " << logIP.month << " " << logIP.day << " " << logIP.year << " " << logIP.time << " " << logIP.ip << " " << logIP.message << endl;
    return os;
}

string LogIP::getMonth() {
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



string LogIP::keyIpGenerator() {
    string mm = getMonth();
    string ip1 = newIP();
    return ip1 + year + mm + day + time;
}

string LogIP::newIP() {
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


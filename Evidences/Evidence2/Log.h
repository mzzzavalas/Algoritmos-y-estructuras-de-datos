#pragma once
using namespace std;
#include <string>
#include <map>

struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    string getMonth();
    string key; // Fecha + Hora
    Log();
    Log(string year, string month, string day, string time, string ip, string message);
    bool operator<(const Log& log) const;
    bool operator>(const Log& log) const;
    bool operator==(const Log& log) const;
    Log& operator=(const Log& log);
    bool operator!=(const Log& log) const;
    friend ostream& operator<<(ostream& os, Log log); 
    string keyGenerator();
};

Log::Log() {
    // vacio
}

Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    // Generamos la llave con una función que convierta el mes a numero y concatene año, mes, dia y hora
    key = keyGenerator();
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

bool Log::operator!=(const Log& log) const {
    return key != log.key;
}

ostream& operator<<(ostream& os, Log log) {
    os << "Log: " << log.month << " " << log.day << " " << log.year << " " << log.time << " " << log.ip << " " << log.message << endl;
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

string Log::keyGenerator() {
   string mm = getMonth();
    return year + mm + day + time;
}



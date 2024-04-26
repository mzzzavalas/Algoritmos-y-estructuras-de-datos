#pragma once
using namespace std;
#include <string>

struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    string key;

    Log(string year, string month, string day, string time, string ip, string message);
    bool operator<(const Log& log) const;
    bool operator>(const Log& log) const;
    bool operator==(const Log& log) const;
    Log& operator=(const Log& log);
};

// Constructor
Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    // Generamos la llave con una función que convierta el mes a número y concatene año, mes, día y hora
    //key = keyGenerator();
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

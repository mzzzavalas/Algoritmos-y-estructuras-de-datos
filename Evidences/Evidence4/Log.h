#pragma once
#include <string>
using namespace std;

struct Log {
    string cityA;
    string cityB;
    string timeByTrain;
    string distanceByTrain;
    string timeByCar;
    string distanceByCar;

    // Default constructor
    Log() : distanceByTrain(0), distanceByCar(0) {}

    // Constructor that takes arguments
    Log(string cityA, string cityB, string timeByTrain, string distanceByTrain, string timeByCar, string distanceByCar)
        : cityA(cityA), cityB(cityB), timeByTrain(timeByTrain), distanceByTrain(distanceByTrain), timeByCar(timeByCar), distanceByCar(distanceByCar) {}

    // Assignment operator
    Log& operator=(const Log& other);
};

// Define the assignment operator outside the class
Log& Log::operator=(const Log& other) {
    if (this != &other) {
        cityA = other.cityA;
        cityB = other.cityB;
        timeByTrain = other.timeByTrain;
        distanceByTrain = other.distanceByTrain;
        timeByCar = other.timeByCar;
        distanceByCar = other.distanceByCar;
    }
    return *this;
}

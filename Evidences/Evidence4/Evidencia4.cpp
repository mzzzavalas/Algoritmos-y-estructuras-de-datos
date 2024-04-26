//Mauricio Zavala Sánchez
//A00837332
//IRS
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
//#include "Log.h"
#include "Edge.h"
#include "Graph.h"
//#include "GraphM.h"
//#include "Hash.h"

struct CityData {
    string cityA;
    string cityB;
    int timeByTrain;
    int distanceByTrain;
    int timeByCar;
    int distanceByCar;
};


void quickSort(vector<string>& arr, int low, int high);

int partition(vector<string>& arr, int low, int high);


// Función para encontrar el índice de una ciudad en el vector de vértices
template <class T>
int findCityIndex(const T& city, const vector<T>& vertices);

// Función para encontrar la ruta más corta entre dos ciudades por tren
template <class T>
void findShortestPathByTrain(const T& start, const T& end, const Graph<T>& graph);
// Función para encontrar la ruta más corta entre dos ciudades por carro
template <class T>
void findShortestPathByCar(const T& start, const T& end, const Graph<T>& graph);


int main() {
    ifstream file("EuropeCities.csv");

    // Saltar la primer linea
    string line;
    getline(file, line);

    vector<CityData> data;
    set<string> cities;

    while (getline(file, line)) {
        istringstream ss(line);
        CityData cityData;
        getline(ss, cityData.cityA, ',');
        getline(ss, cityData.cityB, ',');

        ss >> cityData.timeByTrain;
        ss.ignore(); 

        ss >> cityData.distanceByTrain;
        ss.ignore();  // Ignora la comma

        ss >> cityData.timeByCar;
        ss.ignore(); 
        ss >> cityData.distanceByCar;
        data.push_back(cityData);

        // Agrega las ciudades al set
        cities.insert(cityData.cityA);
        cities.insert(cityData.cityB);
    }

    
    //Punto 2
    vector<string> vertices(cities.begin(), cities.end());
    
    //Punto 3
    vector< Edge<string> > edges;
    for(int i=0;i<data.size();i++){
        if (!data.empty()) {
        //cout << data[i].cityA << ", " << data[i].cityB << ", " << data[i].timeByTrain << ", " << data[i].distanceByTrain << ", " << data[i].timeByCar << ", " << data[i].distanceByCar<< endl;
        edges.emplace_back(data[i].cityA, data[i].cityB, data[i].timeByTrain, data[i].distanceByTrain, data[i].timeByCar, data[i].distanceByCar);
        }
    }
    Graph<string> graph(vertices, edges);
    
    ofstream outFile("output608-1.out");
    string inicio;
                    string cityStart, cityEnd;


    int choice;
    while (true){
        cout<<"Menu: "<<endl;
        cout<<"1. Desplegar las ciudades ordenadas por alfabeto."<<endl;
        cout<<"2. Desplegar la lista de adyacencias del grafo. "<<endl;
        cout<<"3. Desplegar los recorridos del grafo."<<endl;
        cout<<"4. Búsqueda rutas mas cortas."<<endl;
        cout<<"5. Exit."<<endl;
        cout<<"Enter you choice"<<endl;
        cin>>choice;
        switch (choice){
            case 1:
            //4.1
            // Ordena el vector
            quickSort(vertices, 0, vertices.size() - 1);
            // Abre el archivo de salida
            // Escribe las ciudades en el archivo
            for (const string& city : vertices) {
                outFile << city << "\n";
            }
            // Cierra el archivo
            outFile.close();
            cout<<"Ciudades ordenadas guardades en output608-1.out"<<endl;
            break;

            case 2:
            //4.2
            graph.print();
            cout<<"Lista de adyacencias del grafo guardades en output608-2.out"<<endl;
            break;

            case 3:
            //4.3
            cout<<"Inserte la ciudad de inicio: "<<endl;
            cin>>inicio;
            graph.bfs(inicio);
            cout<<"Recorrido BFS guardades en output608-3.out"<<endl;
            graph.dfs(inicio);
            cout<<"Recorrido DFS guardades en output608-4.out"<<endl;
            break;

            case 4:
            //4.4
            // Get city names from user
                cout << "Ingrese la ciudad de inicio: ";
                cin >> cityStart;
                cout << "Ingrese la ciudad de destino: ";
                cin >> cityEnd;

                //No logre que funcionara correctamente esta parte del codigo, pero espero me pueda calificar el intento que hice

                /*
                // Encontrar la ruta más corta por tren y por carro
                findShortestPathByTrain(cityStart, cityEnd, graph);
                findShortestPathByCar(cityStart, cityEnd, graph);
                */


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







void quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(vector<string>& arr, int low, int high) {
    string pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/*
template <class T>
int findCityIndex(const T& city, const vector<T>& vertices) {
    auto it = find(vertices.begin(), vertices.end(), city);
    if (it != vertices.end()) {
        return distance(vertices.begin(), it);
    } else {
        return -1; // Retorna -1 si la ciudad no se encuentra en el grafo
    }
}

// Función para encontrar la ruta más corta entre dos ciudades por tren
template <class T>
void findShortestPathByTrain(const T& start, const T& end, const Graph<T>& graph) {
    int startIndex = findCityIndex(start, graph.getVertices());
    int endIndex = findCityIndex(end, graph.getVertices());

    if (startIndex == -1 || endIndex == -1) {
        cout << "Una o ambas ciudades no existen en el grafo." << endl;
        return;
    }

    pair<vector<int>, vector<int>> result = graph.dijkstra(start);
    int distance = result.first[endIndex];
    int time = result.second[endIndex];

    cout << "Ruta más corta entre " << start << " y " << end << " por tren:" << endl;
    cout << "Distancia: " << distance << " Tiempo: " << time << endl;
}

// Función para encontrar la ruta más corta entre dos ciudades por carro
template <class T>
void findShortestPathByCar(const T& start, const T& end, const Graph<T>& graph) {
    int startIndex = findCityIndex(start, graph.getVertices());
    int endIndex = findCityIndex(end, graph.getVertices());

    if (startIndex == -1 || endIndex == -1) {
        cout << "Una o ambas ciudades no existen en el grafo." << endl;
        return;
    }

    pair<vector<int>, vector<int>> result = graph.dijkstra(start); // Utiliza la versión para carros
    int distance = result.first[endIndex];
    int time = result.second[endIndex];

    cout << "Ruta más corta entre " << start << " y " << end << " por carro:" << endl;
    cout << "Distancia: " << distance << " Tiempo: " << time << endl;
}

*/
//Mauricio Zavala Sánchez
//A00837332
//IRS
#ifndef Graph_h
#define Graph_h
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <stack>

template <class T>
class Graph {
private:
    vector<T> vertices;
    vector< vector< Edge<T> > > adjacencyList;
    int findVertex(T vertex);
    void dfsr(T vertex, vector<bool> &status);
    int findShortest(vector<bool> &status, vector<int> &cost);
public:
    Graph();
    Graph(vector<T> vertices, vector< Edge<T> > edges);
    void addVertex(T vertex);
    void addEdge(Edge<T> edge);
    void removeVertex(T vertex);
    void removeEdge(Edge<T> edge);
    void bfs(T vertex);
    void dfs(T vertex);
    void dijkstra(T vertex);
    void print();
};

template <class T>
Graph<T>::Graph() {

}

template <class T>
int Graph<T>::findVertex(T vertex) {
  typename vector<T>::iterator it;

  it = find(vertices.begin(), vertices.end(), vertex);
  if (it != vertices.end()) {
    return it - vertices.begin();
  } else {
    return -1;
  }
}

template <class T>
Graph<T>::Graph(vector<T> vertices, vector< Edge<T> > edges) {
    // inicializamos los vértices
    this->vertices = vertices;
    // Inicializamos la lista de adyacencias
    adjacencyList.resize(vertices.size());
    // Recorremos la lista de edges
    for (auto edge : edges) {
        // Buscamos el índice del vértice origen
        int sourceIndex = findVertex(edge.source);
        // Buscamos el índice del vértice destino
        int targetIndex = findVertex(edge.target);
        // Validamos que los vértices existan
        if (sourceIndex != -1 && targetIndex != -1) {
            // Agregamos el edge a lista de adyacencias
            adjacencyList[sourceIndex].push_back(edge);
        }
    }
}


template <class T>
void Graph<T>::addVertex(T vertex) {
    // Buscamos si existe
    int vertexIndex = findVertex(vertex);
    // si no existe
    if (vertexIndex == -1) {
        // Lo agregamos a la lista de vértices
        vertices.push_back(vertex);
        // Creamos un vector vacío
        vector< Edge<T> > defaultEdge;
        // Agregamos la lista de arcos vacío a la lista de adyacencias
        adjacencyList.push_back(defaultEdge);
    } else {
        throw invalid_argument("El vértice ya existe");
    }
}

template <class T>
void Graph<T>::addEdge(Edge<T> edge) {
    // Validamos que el vértice origen exista
    int sourceIndex = findVertex(edge.source);
    int targetIndex = findVertex(edge.target);
    if (sourceIndex != -1 && targetIndex != -1) {
        // Validamos que no existe el edge 
        for (auto neighbor : adjacencyList[sourceIndex]) {
            if (edge.target == neighbor.target) {
                throw invalid_argument("El arco ya existe en el grafo");
            }
        }
        // lo agregamos a la lista de adyacencias
        adjacencyList[sourceIndex].push_back(edge);
    } else {
        throw invalid_argument("Alguno de los vértices no existe");
    }
}


template <class T>
void Graph<T>::bfs(T vertex) {
    int vertexIndex = findVertex(vertex);
    // Validamos si el vértice de inicio existe en la lista de vértices
    if (vertexIndex != -1) {
        // Creamos una lista del tamaño de vértices e inicializada en falso
        vector<bool> status(vertices.size(), false);
        // Creamos una fila de enteros vacía
        queue<int> bfsQueue;
        // Agregamos el índice del vértice de inicio a la fila
        bfsQueue.push(vertexIndex);
        // Cambiamos el estado en la lista de estado del vértice de inicio en verdadero
        status[vertexIndex] = true;
        // Hacemos un ciclo mientra la fila no este vacía
        while (!bfsQueue.empty()) {
            // Recorremos cada uno de los vecinos del vértice que se encuentra al inicio de la fila
            for (auto neighbor : adjacencyList[bfsQueue.front()]) {
                // Buscamos el índice del vecino
                int neighborIndex = findVertex(neighbor.target);
                // Validamos si el estado del vecino sea falso
                if (!status[neighborIndex]) {
                    // Agregamos el índice del vecino a la fila
                    bfsQueue.push(neighborIndex);
                    // Cambiamos el estado del vecino en la lista de estados 
                    status[neighborIndex] = true;
                }
            }
            // Imprimimos el primer elemento de la fila
            cout << vertices[bfsQueue.front()] << " ";
            // Removemos el primer elemento de la fila
            bfsQueue.pop();
        }
        cout << endl;
    } else {
        // Genreamos una excepción de que el vértice de inicio no existe
        throw invalid_argument("El vértice de inicio no existe");
    }
}


template <class T>
void Graph<T>::removeVertex(T vertex){
    // Find the index of the vertex
    int index = -1;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == vertex) {
            index = i;
            break;
        }
    }

    // If the vertex is not found, throw an exception
    if (index == -1) {
        throw invalid_argument("Vertex does not exist");
    }

    // Remove the vertex from the vertices vector
    vertices.erase(vertices.begin() + index);

    // Remove the corresponding row and column in the adjacencyList
    adjacencyList.erase(adjacencyList.begin() + index);
    for (auto &row : adjacencyList) {
        row.erase(row.begin() + index);
    }
}

template <class T>
void Graph<T>::removeEdge(Edge<T> edge){
    // Find the source vertex of the edge
    int index = -1;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == edge.source) {
            index = i;
            break;
        }
    }

    // If the vertex is not found, throw an exception
    if (index == -1) {
        throw invalid_argument("Source vertex does not exist");
    }

    // Find the target vertex in the adjacency list of the source vertex
    auto &edges = adjacencyList[index];
    auto it = find_if(edges.begin(), edges.end(), [&edge](const Edge<T> &e) {
        return e.target == edge.target;
    });

    // If the target vertex is not found, throw an exception
    if (it == edges.end()) {
        throw invalid_argument("Target vertex does not exist");
    }

    // Remove the edge from the adjacency list of the source vertex
    edges.erase(it);
}
template <class T>
void Graph<T>::dfsr(T vertex, vector<bool> &status) {
    // visitamos el vértice
    cout << vertex << " ";
    // buscamos el índice del vertice
    int vertexIndex = findVertex(vertex);
    // Actualizamos su estado en verdadero
    status[vertexIndex] = true;
    // Recorremos los vecinos
    for (auto neighbor : adjacencyList[vertexIndex]) {
        // Buscamos el índice del vecino
        int neighborIndex = findVertex(neighbor.target);
        // Validamos si su estado es falso
        if (!status[neighborIndex]) {
            dfsr(neighbor.target, status);
        }
    }

}

template <class T>
void Graph<T>::dfs(T vertex) {
    // Validamo si el vértice existe
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Creamos una lista de estdos
        vector<bool> status(vertices.size(), false);
        // Llamamos a la función de recirsividad
        dfsr(vertex, status);
        cout << endl;
    }
}

template <class T>
int Graph<T>::findShortest(vector<bool> &status, vector<int> &cost) {
    // Creamos un índice y lo inicializamos en -1
    int shortestIndex = -1;
    // Creamos una variable con el costo en infinito
    int shortestCost = INT_MAX;
    // Iteramos todos los vértices
    for (int i=0; i<vertices.size(); i++) {
        // Validamos que su estado sea falso
        if (!status[i]) {
            // Validamos si el costo del vértice actual es el de menor costo
            if (cost[i] < shortestCost) {
                // Actualizamos el shortestCost
                shortestCost = cost[i];
                // Actualizamos el índice del vértice con menor costo
                shortestIndex = i;
            }
        }
    }
    // regresamos el shortestIndex
    return shortestIndex;
}

template <class T>
void Graph<T>::dijkstra(T vertex) {
    // Validamos que el vértice de inicio exista
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        // Creamos la lista de estado
        vector<bool> status(vertices.size(), false);
        // Creamos la lista de costo
        vector<int> cost(vertices.size(), INT_MAX);
        // Creamos la lista de paths
        vector<int> path(vertices.size(), -1);
        // Actualizamos en 0 el costo del vertexIndex (vértice inicial)
        cost[vertexIndex] = 0;
        // Creamos un índice para almacenar el índice del vértice con menor costo
        int shortestIndex = vertexIndex;
        // Iteramos mientras existean vértices en falso y con valores menor a infinito
        while (shortestIndex != -1) {
            // Actualizamos el estado del vértice con el costo menor
            status[shortestIndex] = true;
            // Iteramos los vecinos del vértice con el costo menor
            for (auto neighbor : adjacencyList[shortestIndex]) {
                // Buscamos el índice del vecino
                int neighborIndex = findVertex(neighbor.target);
                // Validamos si el estado del vecino es falso
                if (!status[neighborIndex]) {
                    // Comparamos si el costo del vecino es mayor al costo del vértice con menor costo + el peso
                    if (cost[neighborIndex] > cost[shortestIndex] + neighbor.weight) {
                        // Actualizamos el costo del vecino con el costo del vértice con menor costo + el peso
                        cost[neighborIndex] = cost[shortestIndex] + neighbor.weight;
                        // Actualizamos el path del vértice vécino con el indice del vértice con menor costo
                        path[neighborIndex] = shortestIndex;
                    }
                }
            }
            // Actualizamos el shortest Index
            shortestIndex = findShortest(status, cost);
        }
        // Aquí termina la prinera parte del algoritmo
        // Inicializamos una lista de pilas vacías
        vector< stack<int> > shortestPaths(vertices.size());
        // Iteramos todos los vértices
        for (int i=0; i<vertices.size(); i++) {
            // Agregamos a la pila el índice 
            shortestPaths[i].push(i);
            // Creamos una variable con el valor del path del vértice actual
            int pathIndex = path[i];
            // Iteramos mientas el path index sea diferente de -1
            while (pathIndex != -1) {
                // Agregamos a la pila el valor del pathIndex
                shortestPaths[i].push(pathIndex);
                // Actualizamos el pathIndex
                pathIndex = path[pathIndex];
            }
        }
        // Imprimimos el resultado del shortest path
        // Iteramos la lista de stacks
        for (int i=0; i<vertices.size(); i++) {
            // Imprimimos el vértice actual
            cout << vertices[i] << ": ";
            // Validamos si el costo de vértice actual es igual no es infinito
            if (cost[i] != INT_MAX) {
                // Iteramos la pila mientras no este vacía
                while (!shortestPaths[i].empty()) {
                    // Imprimimos el valor de arriba de la pila
                    cout << vertices[shortestPaths[i].top()] << " ";
                    // Sacamos el valor de arriba de la pila
                    shortestPaths[i].pop();
                }
                cout << "-> " << cost[i] << endl;
            } else {
                cout << "No existe ruta" << endl;
            }
        }
    } else {
        throw invalid_argument("Vértice no existe");
    }
}

template <class T>
void Graph<T>::print() {
    for (int i=0; i<vertices.size(); i++) {
        cout << vertices[i] << " - ";
        for (int j=0; j<adjacencyList[i].size(); j++) {
            cout << adjacencyList[i][j].target << " " << adjacencyList[i][j].weight;
            if (j < adjacencyList[i].size()-1) {
                cout << " - ";
            }
        }
        cout << endl;
    }
}




#endif /* Graph_h */
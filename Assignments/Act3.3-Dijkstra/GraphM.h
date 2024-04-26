//Mauricio Zavala Sánchez
//A00837332
//IRS
#ifndef GraphM_h
#define GraphM_h

#include "Edge.h"

template <class T>
class GraphM {
private:
    vector<T> vertices;
    vector< vector<int> >  matrix;
    int findVertex(T vertex);
public:
    GraphM();
    GraphM(vector<T> vertices, vector< Edge<T> > edges);
    void print();
};

template <class T>
GraphM<T>::GraphM() {

}

template <class T>
int GraphM<T>::findVertex(T vertex) {
  typename vector<T>::iterator it;

  it = find(vertices.begin(), vertices.end(), vertex);
  if (it != vertices.end()) {
    return it - vertices.begin();
  } else {
    return -1;
  }
}

template <class T>
GraphM<T>::GraphM(vector<T> vertices, vector< Edge<T> > edges) {
    // Actualizar los vértices de la clase
    this->vertices = vertices;
    // Inicializar la matriz con valor por default en false
    vector<int> row(vertices.size(), 0);
    matrix.assign(vertices.size(), row);
    // Recorremos la lista de edges
    for (auto edge : edges) {
        // Buscar la posición donde se encuentra en la lista de vertices el vértice origen (sourceIndex)
        int sourceIndex = findVertex(edge.source);
        // Buscar la posición donce se encuentra en la lista de vértices el vértice destino (targetIndex)
        int targetIndex = findVertex(edge.target);
        if (sourceIndex != -1 && targetIndex != -1) {
            // Actualizo en verdadero la posición dada en la matriz (matrix[sourceIndex][targetIndex] = true)
            matrix[sourceIndex][targetIndex] = edge.weight;
        }
    }
}


template <class T>
void GraphM<T>::print() {
    cout << "   ";
    for (auto vertex : vertices) {
        cout << " " << vertex;
    }
    cout << endl;
    for (int i=0; i<vertices.size(); i++) {
        cout << vertices[i] << " - ";
        for (int j=0; j<vertices.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


#endif /* GraphM_h */
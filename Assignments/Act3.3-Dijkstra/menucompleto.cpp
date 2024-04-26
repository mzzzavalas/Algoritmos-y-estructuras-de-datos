//Mauricio Zavala Sánchez
//A00837332
//IRS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "GraphM.h"
#include "Graph.h"

int main() {
    Graph<int> graph;
    int choice, vertex, source, target;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Add vertex\n";
        cout << "2. Add edge\n";
        cout << "3. Remove vertex\n";
        cout << "4. Remove edge\n";
        cout << "5. Print graph\n";
        cout << "6. BFS\n";
        cout << "7. DFS\n";
        cout << "8. Dijkstra\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter vertex: ";
                cin >> vertex;
                graph.addVertex(vertex);
                break;
            case 2:
                cout << "Enter source and target: ";
                cin >> source >> target;
                graph.addEdge({source, target});
                break;
            case 3:
                cout << "Enter vertex: ";
                cin >> vertex;
                graph.removeVertex(vertex);
                break;
            case 4:
                cout << "Enter source and target: ";
                cin >> source >> target;
                graph.removeEdge({source, target});
                break;
            case 5:
                graph.print();
                break;
            case 6:
                cout << "Enter start vertex for BFS: ";
                cin >> vertex;
                graph.bfs(vertex);
                break;
            case 7:
                cout << "Enter start vertex for DFS: ";
                cin >> vertex;
                graph.dfs(vertex);
                break;
            case 8:
                cout << "Enter start vertex for Dijkstra: ";
                cin >> vertex;
                graph.dijkstra(vertex);
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
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
    // Create a Graph object
    Graph<int> graph;

    // Add vertices
    for (int i = 1; i <= 5; i++) {
        graph.addVertex(i);
    }

    // Add edges
    for (int i = 1; i < 5; i++) {
        Edge<int> edge;
        edge.source = i;
        edge.target = i + 1;
        graph.addEdge(edge);
    }

    // Print the graph
    graph.print();

    // Remove a vertex
    graph.removeVertex(3);

    // Remove an edge
    Edge<int> edge;
    edge.source = 4;
    edge.target = 5;
    graph.removeEdge(edge);

    // Print the graph
    graph.print();

    // Call bfs, dfs, and dijkstra methods
    graph.bfs(1);
    graph.dfs(1);
    graph.dijkstra(1);

    return 0;
}
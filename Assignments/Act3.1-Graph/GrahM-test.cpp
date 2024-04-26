#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "GraphM.h"
#include "Graph.h"

int main() {

    vector<string> vertices = {"A", "B", "C", "D", "E"};
    vector< Edge<string> > edges;
    edges.emplace_back("A","B");
    edges.emplace_back("B","A");
    edges.emplace_back("A","C");
    edges.emplace_back("C","A");
    edges.emplace_back("A","E");
    edges.emplace_back("E","A");
    edges.emplace_back("B","D");
    edges.emplace_back("D","B");
    edges.emplace_back("C","D");
    edges.emplace_back("D","C");
    edges.emplace_back("E","D");
    edges.emplace_back("D","E");

    GraphM<string> graphM1(vertices, edges);
    graphM1.print();
    cout << endl;
    vector<int> vertices1 = {0,1,2,3,4,5,6,7};
    vector< Edge<int> > edges1;
    edges1.emplace_back(0,2,5);
    edges1.emplace_back(0,4,6);
    edges1.emplace_back(1,0,2);
    edges1.emplace_back(2,5,7);
    edges1.emplace_back(3,7,6);
    edges1.emplace_back(5,3,5);
    edges1.emplace_back(5,6,2);
    edges1.emplace_back(6,4,1);
    edges1.emplace_back(7,5,2);

    GraphM<int> graphM2(vertices1, edges1);
    graphM2.print();
    cout << endl;
    Graph<int> graph(vertices1, edges1);
    graph.addVertex(8);
    graph.addEdge(Edge<int>(8,0,3));
    graph.addEdge(Edge<int>(0,8,3));
    graph.print();
    graph.bfs(0);



    return 0;
}
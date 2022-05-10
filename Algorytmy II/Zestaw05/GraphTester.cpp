#include "Graph.hpp"

int main (int argc, char* argv[]){
    Graph g = Graph();

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);

    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 4);
    g.addEdge(5, 1);

    g.setEdgeValue(5, 1, 51);
    g.setEdgeValue(1, 2, 12);
    g.setEdgeValue(1, 4, 14);

    g.toDotFile("ProgramGraph.dot");
}
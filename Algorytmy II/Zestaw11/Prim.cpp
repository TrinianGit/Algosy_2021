#include "Graph.hpp"
#include <fstream>

using namespace std;

int minimalK (vector<double> keys, vector<bool> set){
    double min = __DBL_MAX__;
    int min_index;

    for (unsigned long int i = 1; i < keys.size(); i++){
        if (!set[i] && keys[i] < min){
            min = keys[i];
            min_index = i;
        }
    }
    return min_index;
}

Graph<int>* Prim (Graph<int>* g){
    vector<int> parent = vector<int>(129);
    vector<double> keys = vector<double>(129, __DBL_MAX__);
    vector<bool> set = vector<bool>(129, false);

    keys[1] = 0;
    parent[1] = -1;

    for (unsigned long int i = 0; i < keys.size()-1; i++){
        int u = minimalK(keys, set);
        
        set[u] = true;

        for (unsigned long int j = 1; j < keys.size() + 1; j++){
            if (g->getEdgeValue(u, j) != 0.0 && !set[j] && g->getEdgeValue(u, j) < keys[j]){
                parent[j] = u;
                keys[j] = g->getEdgeValue(u, j);
            }
        }
    }

    Graph<int>* MST = new Graph<int>();
    for (unsigned long int i = 2; i < keys.size(); i++){
        MST->addVertex(parent[i]);
        MST->addVertex(i);
        MST->addEdge(parent[i], i);
        MST->addEdge(i, parent[i]);
        MST->setEdgeValue(parent[i], i, g->getEdgeValue(parent[i], i));
        MST->setEdgeValue(i, parent[i], g->getEdgeValue(i, parent[i]));
    }
    return MST;
}

int main(){
    Graph<int>* g = new Graph<int>();

    ifstream data("randgraph.dat");
    int ComputerA, ComputerB;
    double delay;
    while (data >> ComputerA >> ComputerB >> delay){
        g->addVertex(ComputerA);
        g->addVertex(ComputerB);
        g->addEdge(ComputerA, ComputerB);
        g->addEdge(ComputerB, ComputerA);
        g->setEdgeValue(ComputerA, ComputerB, delay);
        g->setEdgeValue(ComputerB, ComputerA, delay);
        
    }
    data.close();

    Graph<int>* MST = Prim(g);

    MST->toDotFile("ResultPrim.dot");
}
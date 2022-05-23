#include "Graph.hpp"
#include <fstream>

using namespace std;

bool CyclicUnDirectedRecursion (Graph* g, int v, vector<bool> checked, int parent){
    checked[v] = true;

    for (int& i : g->neighbours(v)){
        if (!checked[i]){
            if (CyclicUnDirectedRecursion(g, i, checked, v)){
                return true;
            }
        }
        else if (i != parent){
            return true;
        }
    }

    return false;
}

bool CyclicUnDirected (Graph* g, int size){
    vector<bool> visited(size, false);

    for (int u = 0; u < size; u++) {
        if (!visited[u]){
            if (CyclicUnDirectedRecursion(g, u, visited, -1)){
                return true;
            }
        }
    }
    return false;
}

bool CyclicDirectedRecursion (Graph* g, int v, vector<bool> visited, vector<bool> stack){
    if (!visited[v]){
        visited[v] = true;
        stack[v] = true;

        for (int& i : g->neighbours(v)){
            if (!visited[i] && CyclicDirectedRecursion(g, i, visited, stack)){
                return true;
            }
            else if (stack[i]){
                return true;
            }
        }
    }
    stack[v] = false;
    return false;
}

bool CyclicDirected (Graph* g, int size){
    vector<bool> visited(size, false);
    vector<bool> stack(size, false);

    for (int i = 0; i < size; i++){
        if (!visited[i] && CyclicDirectedRecursion(g, i, visited, stack)){
            return true;
        }
    }
    return false;
}

int main(){
    Graph* g1 = new Graph();
    Graph* g2 = new Graph();
    Graph* g3 = new Graph();

    ifstream data1("graph1.dat");
    for (int i = 0; i < 46; i++){
        g1->addVertex(i);
    }
    int read;
    for (int i = 0; i < 46; i++){
        for (int j = 0; j < 46; j++){
            data1 >> read;
            if (read){
                g1->addEdge(i, j);
            }
        }
    }
    data1.close();

    ifstream data2("graph2.dat");
    for (int i = 0; i < 10; i++){
        g2->addVertex(i);
    }

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            data2 >> read;
            if (read){
                g2->addEdge(i, j);
            }
        }
    }
    data2.close();

    ifstream data3("graph3.dat");
    for (int i = 0; i < 15; i++){
        g3->addVertex(i);
    }

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            data3 >> read;
            if (read){
                g3->addEdge(i, j);
            }
        }
    }
    data3.close();

    bool directed1 = false;
    for (int i = 0; i < 46 && !directed1; i++){
        for (int j = i; j < 46; j++){
            if (g1->getEdgeValue(i,j) != g1->getEdgeValue(j, i)){
                directed1 = true;
                break;
            }
        }
    }

    bool directed2 = false;
    for (int i = 0; i < 10 && !directed2; i++){
        for (int j = i; j < 10; j++){
            if (g2->getEdgeValue(i,j) != g2->getEdgeValue(j, i)){
                directed2 = true;
                break;
            }
        }
    }

    bool directed3 = false;
    for (int i = 0; i < 15 && !directed3; i++){
        for (int j = i; j < 15; j++){
            if (g3->getEdgeValue(i,j) != g3->getEdgeValue(j, i)){
                directed3 = true;
                break;
            }
        }
    }

    if (directed1){
        if (CyclicDirected(g1, 46)){
            cout << "Graph 1 is directed and has at least one cycle" << endl;
        }
        else{
            cout << "Graph 1 is directed and has no cycles" << endl;
        }
    }
    else{
        if (CyclicUnDirected(g1, 46)){
            cout << "Graph 1 is indirected and has at least one cycle" << endl;
        }
        else{
            cout << "Graph 1 is indirected and has no cycles" << endl;
        }
    }

    if (directed2){
        if (CyclicDirected(g2, 10)){
            cout << "Graph 2 is directed and has at least one cycle" << endl;
        }
        else{
            cout << "Graph 2 is directed and has no cycles" << endl;
        }
    }
    else{
        if (CyclicUnDirected(g2, 10)){
            cout << "Graph 2 is indirected and has at least one cycle" << endl;
        }
        else{
            cout << "Graph 2 is indirected and has no cycles" << endl;
        }
    }

    if (directed3){
        if (CyclicDirected(g3, 15)){
            cout << "Graph 3 is directed and has at least one cycle" << endl;
        }
        else{
            cout << "Graph 3 is directed and has no cycles" << endl;
        }
    }
    else{
        if (CyclicUnDirected(g3, 15)){
            cout << "Graph 3 is indirected and has at least one cycle" << endl;
        }
        else{
            cout << "Graph 3 is indirected and has no cycles" << endl;
        }
    }
}
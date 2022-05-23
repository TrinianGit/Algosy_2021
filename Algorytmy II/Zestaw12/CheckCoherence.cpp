#include "Graph.hpp"
#include <fstream>
#include <list>

using namespace std;

bool CheckCoherence (Graph* g, int size){
    vector<bool> visited(size, false);

    list<int> verts;

    int start = rand() % size;
    vector<int> neighbours = g->neighbours(start);
    verts.insert (verts.end(), neighbours.begin(), neighbours.end());
    visited[start] = true;

    while (!verts.empty()){
        neighbours = g->neighbours(verts.front());
        visited[verts.front()] = true;
        for (int v : neighbours){
            if (!visited[v]){
                verts.push_back(v);
            }
        }
        verts.pop_front();
    }

    int check = 0;
    for (bool vis : visited){
        if (vis){
            check++;
        }
    }
    if (check == size){
        return true;
    }
    return false;
}



int main(){
    Graph* g1 = new Graph();
    Graph* g2 = new Graph();
    Graph* g3 = new Graph();

    ifstream data1("graph4.dat");
    for (int i = 0; i < 45; i++){
        g1->addVertex(i);
    }
    int read;
    for (int i = 0; i < 45; i++){
        for (int j = 0; j < 45; j++){
            data1 >> read;
            if (read){
                g1->addEdge(i, j);
            }
        }
    }
    data1.close();

    ifstream data2("graph5.dat");
    for (int i = 0; i < 13; i++){
        g2->addVertex(i);
    }

    for (int i = 0; i < 13; i++){
        for (int j = 0; j < 13; j++){
            data2 >> read;
            if (read){
                g2->addEdge(i, j);
            }
        }
    }
    data2.close();

    ifstream data3("graph6.dat");
    for (int i = 0; i < 10; i++){
        g3->addVertex(i);
    }

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            data3 >> read;
            if (read){
                g3->addEdge(i, j);
            }
        }
    }
    data3.close();

    if (CheckCoherence(g1, 45)){
        cout << "Graph 1 is coherent" << endl;
    }
    else{
        cout << "Graph 1 is not coherent" << endl;
    }

    if (CheckCoherence(g2, 13)){
        cout << "Graph 2 is coherent" << endl;
    }
    else{
        cout << "Graph 2 is not coherent" << endl;
    }

    if (CheckCoherence(g3, 10)){
        cout << "Graph 3 is coherent" << endl;
    }
    else{
        cout << "Graph 3 is not coherent" << endl;
    }
}
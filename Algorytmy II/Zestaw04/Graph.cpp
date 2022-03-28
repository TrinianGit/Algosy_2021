#include "Graph.hpp"
#include <ctime>
#include <chrono>

using namespace std;

int main (int argc, char* argv[]){
    srand(time(NULL));
    double tab[1000];

    for (int i = 0; i < 1000; i++){
        tab[i] = 0;
    }


    for (int i = 0; i < 1000; i++){
        Graph* g = new Graph();
        for (int j = 0; j < 1000; j++){
            auto start = chrono::system_clock::now();
            g->addVertex(rand()%10000+1);
            auto end = chrono::system_clock::now();
            auto elapsed = end - start;
            
            tab[i] += elapsed.count();
        }
        cout << i << " " << tab[i] / 1000 << endl;
        delete g;
    }
}
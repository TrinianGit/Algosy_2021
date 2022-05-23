#include "Graph.hpp"
#include <algorithm>

using namespace std;


class DSU {
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        DSU(int n) {
            parent = vector<int>(n, -1);
            rank = vector<int>(n, 1);
        }

        int find(int i){
            if (parent[i] == -1){
                return i;
            }
            return parent[i] = find(parent[i]);
        }

        void unite(int x, int y){
            int s1 = find(x);
            int s2 = find(y);

            if (s1 != s2){
                if (rank[s1] < rank[s2]){
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                }
                else{
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            }
        }
};

bool sortByVal (const pair<pair<int,int>, double> &a, const pair<pair<int,int>, double> &b){
    return (a.second < b.second);
}

Graph<int>* Kruskal(Graph<int>* g){
    vector<pair<pair<int,int>, double>> edges;

    for (int i = 1; i < 129; i++){
        for (int j = 0; j < 129; j++){
            double w;
            if ((w = g->getEdgeValue(i, j)) != 0){
                edges.push_back(make_pair(make_pair(i, j), w));
            }
        }
    }

    sort(edges.begin(), edges.end(), sortByVal);

    DSU s(129);

    Graph<int>* MST = new Graph<int>();

    for (pair<pair<int,int>, double> e : edges){
        double w = e.second;
        int x = e.first.first;
        int y = e.first.second;

        if (s.find(x) != s.find(y)){
            s.unite(x,y);
            MST->addVertex(x);
            MST->addVertex(y);
            MST->addEdge(x, y);
            MST->setEdgeValue(x, y, w);
        }
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

    Graph<int>* MST = Kruskal(g);

    MST->toDotFile("ResultKruskal.dot");
}
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <tuple>
#include <set>

struct NodeColor {
    int sat;
    int deg;
    int vertex;
};

struct maxSat {
    bool operator()(const NodeColor& lhs, const NodeColor& rhs) const {
        return std::tie(lhs.sat, lhs.deg, lhs.vertex) > std::tie(rhs.sat, rhs.deg, rhs.vertex);
    }
};

template<class T>
class Graph{
    public:
        Graph(){
            Vertexes = std::vector<T>();
            Edges = std::vector<std::vector<int>>();
            size = 0;
        }

        bool adjacent(T x, T y){
            int i = -1; 
            int j = -1;
            for (unsigned long int k = 0; k < Vertexes.size(); k++){
                if (Vertexes[k] == x){
                    i = k;
                }
                if (Vertexes[k] == y){
                    j = k;
                }
                if (i != -1 && j != -1){
                    break;
                }
            }
            return Edges[i][j] != 0;
        }

        std::vector<T> neighbours(T x){
            int j;
            std::vector<int> neig;
            for (unsigned long int k = 0; k < Vertexes.size(); k++){
                if (Vertexes[k] == x){
                    j = k;
                    break;
                }
            }
            for (unsigned long int i = 0; i < Edges.size(); i++){
                if (Edges[j][i] != 0){
                    neig.push_back(Vertexes[i]);
                }
            }
            return neig;
        }

        void addVertex(T x){
            Vertexes.push_back(x);
            for (unsigned long int i = 0; i < Edges.size(); i++){
                Edges[i].push_back(0);
            }
            Edges.push_back(std::vector<int>());
            for (unsigned long int i = 0; i < Edges.size()+1; i++){
                Edges[Edges.size()-1].push_back(0);
            }
            size++;
        }

        void removeVertex(T x){
            std::vector<int>::iterator it;
            unsigned long int i = 0;
            for (it = Vertexes.begin(); it != Vertexes.end(); it++){
                if ((*it) == x){
                    Vertexes.erase(it);
                    break;
                }
                i++;
            }
            unsigned long int i_cpy = i;
            std::vector<std::vector<int>>::iterator it2;
            for (unsigned long int j = 0; j < Edges.size(); j++){
                if (j == i){
                    j--;
                    i = Edges.size()+10;
                    Edges.erase(it2);
                }
                else{
                    std::vector<int>::iterator it3 = Edges[j].begin();
                    for (unsigned long int k = 0; k < i_cpy; k++){
                        it2++;
                    }
                    Edges[j].erase(it3);
                }
            }
            size--;
        }

        void addEdge(T x, T y){
            int i = -1; 
            int j = -1;
            for (unsigned long int k = 0; k < Vertexes.size(); k++){
                if (Vertexes[k] == x){
                    i = k;
                }
                if (Vertexes[k] == y){
                    j = k;
                }
                if (i != -1 && j != -1){
                    break;
                }
            }
            Edges[i][j] = 1;
        }

        void removeEdge(T x, T y){
            int i = -1; 
            int j = -1;
            for (unsigned long int k = 0; k < Vertexes.size(); k++){
                if (Vertexes[k] == x){
                    i = k;
                }
                if (Vertexes[k] == y){
                    j = k;
                }
                if (i != -1 && j != -1){
                    break;
                }
            }
            Edges[i][j] = 0;
        }

        int getVertexValue(int x){
            return Vertexes[x];
        }

        void setVertexValue(int x, int v){
            Vertexes[x] = v;
        }

        int getEdgeValue(T x, T y){
            int i = -1; 
            int j = -1;
            for (unsigned long int k = 0; k < Vertexes.size(); k++){
                if (Vertexes[k] == x){
                    i = k;
                }
                if (Vertexes[k] == y){
                    j = k;
                }
                if (i != -1 && j != -1){
                    break;
                }
            }
            return Edges[i][j];
        }

        void setEdgeValue(T x, T y, int v){
            int i = -1; 
            int j = -1;
            for (unsigned long int k = 0; k < Vertexes.size(); k++){
                if (Vertexes[k] == x){
                    i = k;
                }
                if (Vertexes[k] == y){
                    j = k;
                }
                if (i != -1 && j != -1){
                    break;
                }
            }
            Edges[i][j] = v;
        }

        int nonZero(std::vector<int> v){
            int i = 0;
            for (auto& a : v){
                if (a != 0){
                    i++;
                }
            }
            return i;
        }

        void DSatur()
        {
            int u, i;
            std::vector<bool> used(size, false);
            std::vector<int> c(size), d(size);
            std::vector<std::set<int>> adjColors(size);
            std::set<NodeColor, maxSat> pQ;
            std::set<NodeColor, maxSat>::iterator maxPtr;
        
            for (u = 0; u < size; u++) {
                c[u] = -1;
                d[u] = nonZero(Edges[u]);
                adjColors[u] = std::set<int>();
                pQ.emplace(NodeColor{ 0, d[u], u });
            }
        
            while (!pQ.empty()) {
        
                maxPtr = pQ.begin();
                u = (*maxPtr).vertex;
                pQ.erase(maxPtr);

                int k = 0;

                for (int v : Edges[u]){
                    if (v != 0){
                        if (c[k] != -1){
                            used[c[k]] = true;
                        }
                    }
                    k++;
                }

                for (i = 0; i < used.size(); i++){    
                    if (used[i] == false){
                        break;
                    }
                }
                k = 0;
                for (int v : Edges[u]){
                    if (v != 0){
                        if (c[k] != -1){
                            used[c[k]] = false;
                        }
                    }
                    k++;
                }

                c[u] = i;
        
                for (int v : Edges[u]) {
                    if (c[v] == -1) {
                        pQ.erase({ int(adjColors[v].size()), d[v], v });
                        adjColors[v].insert(i);
                        d[v]--;
                        pQ.emplace(NodeColor{int(adjColors[v].size()), d[v], v});
                    }
                }
            }
        
            for (u = 0; u < size; u++)
                std::cout << "Vertex " << Vertexes[u] << " --->  Color " << c[u] << std::endl;
        }

        ~Graph(){

        }
    private:
        std::vector<T> Vertexes;
        std::vector<std::vector<int>> Edges;
        int size;
};

#endif
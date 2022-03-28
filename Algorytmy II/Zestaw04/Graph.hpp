#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

class Graph{
    public:
        Graph(){
            Vertexes = std::vector<int>();
            Edges = std::vector<std::vector<int>>();
            size = 0;
        }

        bool adjacent(int x, int y){
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

        std::vector<int> neighbours(int x){
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

        void addVertex(int x){
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

        void removeVertex(int x){
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

        void addEdge(int x, int y){
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

        void removeEdge(int x, int y){
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

        int getEdgeValue(int x, int y){
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

        void setEdgeValue(int x, int y, int v){
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

        ~Graph(){

        }
    private:
        std::vector<int> Vertexes;
        std::vector<std::vector<int>> Edges;
        int size;
};

#endif
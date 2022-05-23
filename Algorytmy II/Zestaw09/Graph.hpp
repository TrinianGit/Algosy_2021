#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.hpp"
#include <iostream>
#include <vector>
#include <fstream>

template <class T>
class Graph{

    struct Node{
        T value;
        int importance;
    };

    public:
        Graph(){
            Edges = std::vector<List<Node, T>>();
        }

        bool adjacent(T x, T y){
            for (unsigned long int i = 0; i < Edges.size(); i++){
                if (Edges[i].identifier() == x){
                    for (typename List<Node, T>::iterator it = Edges[i].begin(); it != Edges[i].end(); it++){
                        if (*it.value == y){
                            return true;
                        }
                    }
                    return false;
                }
            }
            return false;
        }

        std::vector<T> neighbours(T x){
            std::vector<T> neigh;
            for (unsigned long int i = 0; i < Edges.size(); i++){
                if (Edges[i].identifier() == x){
                    for (typename List<Node, T>::iterator it = Edges[i].begin(); it != Edges[i].end(); it++){
                        neigh.push_back((*it).value);
                    }
                }
            }
            return neigh;
        }

        void addVertex(T x){
            for (typename std::vector<List<Node, T>>::iterator it = Edges.begin(); it != Edges.end(); it++){
                if ((*it).identifier() == x){
                    return;
                }
            }
            Edges.push_back(List<Node, T>(x));
        }

        void removeVertex(T x){
            for (typename std::vector<List<Node, T>>::iterator it = Edges.begin(); it != Edges.end(); it++){
                if ((*it).identifier() == x){
                    Edges.erase(it);
                    return;
                }
            }
        }

        void addEdge(T x, T y){
            for (unsigned long int i = 0; i < Edges.size(); i++){
                if (Edges[i].identifier() == x){
                    Node k;
                    k.importance = 1;
                    k.value = y;
                    Edges[i].push_back(k);
                }
            }
        }

        void removeEdge(T x, T y){
            for (unsigned long int i = 0; i < Edges.size(); i++){
                if (Edges[i].identifier() == x){
                    for (typename List<Node, T>::iterator it = Edges[i].begin(); it != Edges[i].end(); it++){
                        if ((*it).value == y){
                            Edges[i].erase(it);
                            return;
                        }
                    }
                }
            }
        }

        T getVertexValue(T x){
            unsigned long int i;
            for (i = 0; i < x; i++);
            return Edges[i].identifier();
        }

        void setVertexValue(T x, T v){
            unsigned long int i;
            for (i = 0; i < x; i++);
            Edges[i].changeIdentifier(v);
        }

        int getEdgeValue(T x, T y){
            for (unsigned long int i = 0; i < Edges.size(); i++){
                if (Edges[i].identifier() == x){
                    for (typename List<Node, T>::iterator it = Edges[i].begin(); it != Edges[i].end(); it++){
                        if ((*it).value == y){
                            return (*it).importance;
                        }
                    }
                }
            }
            return -1;
        }

        void setEdgeValue(T x, T y, int v){
            for (unsigned long int i = 0; i < Edges.size(); i++){
                if (Edges[i].identifier() == x){
                    for (typename List<Node, T>::iterator it = Edges[i].begin(); it != Edges[i].end(); it++){
                        if ((*it).value == y){
                            (*it).importance = v;
                            return;
                        }
                    }
                }
            }
        }

        void toDotFile(std::string filename){
            std::ofstream file(filename);
            file << "digraph {" << std::endl;
            for (unsigned long int i = 0; i < Edges.size(); i++){
                for (typename List<Node, T>::iterator it = Edges[i].begin(); it != Edges[i].end(); it++){
                    file << "\t\"" << Edges[i].identifier() << "\"" << " -> " << "\"" << (*it).value << "\"" << "[label=" << (*it).importance << "]" << std::endl;    
                }
            }
            file << "}";
        }

        std::vector<T> Vertexes(){
            std::vector<T> v;
            for (typename std::vector<List<Node, T>>::iterator it = Edges.begin(); it != Edges.end(); it++){
                v.push_back((*it).identifier());
            }
            return v;
        }

        ~Graph(){
            unsigned long int x = Edges.size();
            for (unsigned long int i = 0; i < x; i++){
                Edges.pop_back();
            }
        }
    private:
        std::vector<List<Node, T>> Edges;
};

#endif
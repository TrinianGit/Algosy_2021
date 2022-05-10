#include <iostream>
#include <list>
#include <bits/stdc++.h>
#include <map>
#include <ctime>
#include "Graph.hpp"
#define S 8

class Knight {
    public:
        Knight(std::pair<int,int> spoint, int board[S][S]){
            startpoint = spoint;
            for (int i = 0; i < S; i++){
                for (int j = 0; j < S; j++){
                    chessboard[i][j] = false;
                    warnsdorff[i][j] = board[i][j];
                }
            }
            JumpTo(startpoint);
        }

        void JumpTo(std::pair<int,int> point){
            chessboard[point.first][point.second] = true;
            route.push_back(point);
            current = point;
        }

        bool WasThere(std::pair<int,int> point){
            return chessboard[point.first][point.second];
        }

        std::list<std::pair<int,int>> Route(){
            return route;
        }

        std::pair<int,int> Current(){
            return current;
        }

        int Warnsdorff(int i, int j){
            return warnsdorff[i][j];
        }

        void WarnsdorffMinus(int i, int j){
            warnsdorff[i][j]--;
        }

        Knight* makeCopy(){
            Knight* k = new Knight(startpoint, warnsdorff);
            k->startpoint = startpoint;
            k->current = current;
            for (int i = 0; i < S; i++){
                for (int j = 0; j < S; j++){
                    k->chessboard[i][j] = chessboard[i][j];
                    k->warnsdorff[i][j] = warnsdorff[i][j];
                }
            }
            k->route = route;
            return k;
        }

    private:
        std::pair<int,int> startpoint;
        std::pair<int,int> current;
        bool chessboard[S][S];
        int warnsdorff[S][S];
        std::list<std::pair<int,int>> route;
};

class ChessBoard {
    public:
        ChessBoard(Graph<std::pair<int,int>>* g, int warnsdorff[S][S]){
            for (int i = 0; i < S; i++){
                for (int j = 0; j < S; j++){
                    g->addVertex(std::make_pair(i,j));
                    warnsdorff[i][j] = 0;
                }
            }

            for (int x = 0; x < S; x++){
                for (int y = 0; y < S; y++){
                    //RRU
                    if (x+2 < S && y+1 < S){
                        g->addEdge(std::make_pair(x,y), std::make_pair(x+2,y+1));
                        warnsdorff[x][y]++;
                    }
                    //RRD
                    if (x+2 < S && y-1 >= 0){
                        g->addEdge(std::make_pair(x,y), std::make_pair(x+2,y-1));
                        warnsdorff[x][y]++;
                    }
                    //RUU
                    if (x+1 < S && y+2 < S){
                        g->addEdge(std::make_pair(x,y), std::make_pair(x+1,y+2));
                        warnsdorff[x][y]++;
                    }
                    //RDD
                    if (x+1 < S && y-2 >= 0){
                        g->addEdge(std::make_pair(x,y), std::make_pair(x+1,y-2));
                        warnsdorff[x][y]++;
                    }
                    //LUU
                    if (x-1 >= 0 && y+2 < S){
                        g->addEdge(std::make_pair(x,y), std::make_pair(x-1,y+2));
                        warnsdorff[x][y]++;
                    }
                    //LDD
                    if (x-1 >= 0 && y-2 >= 0){
                        g->addEdge(std::make_pair(x,y), std::make_pair(x-1,y-2));
                        warnsdorff[x][y]++;
                    }
                    //LLD
                    if (x-2 >= 0 && y-1 >= 0){
                        g->addEdge(std::make_pair(x,y), std::make_pair(x-2,y-1));
                        warnsdorff[x][y]++;
                    }
                    //LLU
                    if (x-2 >= 0 && y+1 < S){
                        g->addEdge(std::make_pair(x,y), std::make_pair(x-2,y+1));
                        warnsdorff[x][y]++;
                    }
                }
            }
        }

        void ShowRoute(std::list<std::pair<int,int>> route){
            int board[S][S];
            int i = 1;
            for (auto& a : route){
                board[a.first][a.second] = i;
                i++;
            }
            for (int j = 0; j < S; j++){
                for (int k = 0; k < S; k++){
                    if(board[j][k] < 10){
                        std::cout << " " << board[j][k] << " ";
                    }
                    else{
                        std::cout << board[j][k] << " ";
                    }
                }
                std::cout << std::endl;
            }
        }

        static bool comparator (std::pair<std::pair<int,int>, int>& a, std::pair<std::pair<int,int>, int>& b){
            return a.second < b.second;
        }

        std::vector<std::pair<std::pair<int,int>, int>> MapSort(std::map<std::pair<int,int>, int> Map){
            std::vector<std::pair<std::pair<int,int>, int>> Sorting;

            for (auto& a : Map){
                Sorting.push_back(a);
            }

            std::sort(Sorting.begin(), Sorting.end(), comparator);
            return Sorting;
        }

        bool Search(Graph<std::pair<int,int>>* g, Knight* k){
            if (k->Route().size() == S * S){
                for (auto& n : g->neighbours(k->Route().front())){
                    if ((k->Route().back()) == n){
                        std::cout << "Found Route" << std::endl;
                        ShowRoute(k->Route());
                        std::cout << std::endl;
                        return true;
                    }
                }
                return false;
            }

            std::map<std::pair<int,int>, int> edgesW;

            for (std::pair<int,int>& n : g->neighbours(k->Current())){
                if (!k->WasThere(n)){
                    edgesW.insert(std::make_pair(n, k->Warnsdorff(n.first, n.second)));
                }
            }

            std::vector<std::pair<std::pair<int,int>, int>> sortedegdesW = MapSort(edgesW);

            for (std::pair<std::pair<int,int>, int>& a : sortedegdesW){
                Knight* copy = k->makeCopy();
                copy->JumpTo(a.first);
                for (std::pair<int,int>& n : g->neighbours(copy->Current())){
                    copy->WarnsdorffMinus(n.first,n.second);
                }
                if (Search(g, copy)){
                    return true;
                }
            }
            return false;
        }
};

int main(){
    srand(time(NULL));

    std::cout << "Generating Chessboard" << std::endl;
    Graph<std::pair<int,int>>* g = new Graph<std::pair<int,int>>();
    int warnsdorff[S][S];
    ChessBoard ch = ChessBoard(g, warnsdorff);
    std::pair<int,int> start = std::make_pair(rand()%S, rand()%S);
    std::cout << "Searching route... Starting point: (" << start.second << "," << start.first << ")" << std::endl;
    ch.Search(g, new Knight(start, warnsdorff)); 
}
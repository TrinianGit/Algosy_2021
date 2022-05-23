#include "Graph.hpp"
#include <fstream>
#include <map>

using namespace std;

map<string, map<string, int>> FloydWarshall(Graph<string>* g){
    map<string, map<string,int>> FW;

    for (string& v : g->Vertexes()){
        for (string& u : g->Vertexes()){
            FW[v][u] = INT32_MAX;
        }
        FW[v][v] = 0;
    }

    for (string& v : g->Vertexes()){
        for (string& u : g->Vertexes()){
            if (g->getEdgeValue(v, u) > -1){
                FW[v][u] = g->getEdgeValue(v, u);
            }
        }
    }

    for (string& u : g->Vertexes()){
        for (string& v1 : g->Vertexes()){
            for(string& v2 : g->Vertexes()){
                if (FW [v1][v2] > FW[v1][u] + FW[u][v2] && FW[v1][u] != INT32_MAX && FW[u][v2] != INT32_MAX){
                    FW[v1][v2] = FW[v1][u] + FW[u][v2];
                }
            }
        }
    }
    return FW;
}

int main () {
	
	Graph<string>* g = new Graph<string>();
	
	ifstream data("TimeTable.dat");
	string CityA, CityB;
	int Time;
	while (data >> CityA >> CityB >> Time) {
		g->addVertex (CityA);
		g->addVertex (CityB);
		g->addEdge (CityA, CityB);
        g->addEdge (CityB, CityA);
        g->setEdgeValue(CityA, CityB, Time);
        g->setEdgeValue(CityB, CityA, Time);
	}
	
	data.close();
	
	ofstream result("Result.csv");
	
	map<string, map<string, int>> FWresults = FloydWarshall (g);

	result << "Travel Time";

	for (pair<string, map<string, int>> r : FWresults) {
		result << "," << r.first;
	}
	result << endl;
	for (pair<string, map<string, int>> r : FWresults) {
		result << r.first;
		for (pair<string, int> field : r.second) {
			result << "," << field.second;
		}
		result << endl;
	}
	
	result.close();
}
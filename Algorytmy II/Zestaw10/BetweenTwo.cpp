#include "Graph.hpp"
#include <fstream>
#include <map>

using namespace std;

struct coords{
    double x;
    double y;
};

pair<map <string, map<string, int>>, map <string, map <string,string>>> FloydWarshall(Graph<string>* g){
    map<string, map<string,int>> FW;
    map<string, map<string,string>> antecedent; 

    for (string& v : g->Vertexes()){
        for (string& u : g->Vertexes()){
            FW[v][u] = INT32_MAX;
            antecedent[u][v] = "NULL";
        }
        FW[v][v] = 0;
    }

    for (string& v : g->Vertexes()){
        for (string& u : g->Vertexes()){
            if (g->getEdgeValue(v, u) > -1){
                FW[v][u] = g->getEdgeValue(v, u);
                antecedent[v][u] = v;
            }
        }
    }

    for (string& u : g->Vertexes()){
        for (string& v1 : g->Vertexes()){
            for(string& v2 : g->Vertexes()){
                if (FW [v1][v2] > FW[v1][u] + FW[u][v2] && FW[v1][u] != INT32_MAX && FW[u][v2] != INT32_MAX){
                    FW[v1][v2] = FW[v1][u] + FW[u][v2];
                    antecedent[v1][v2] = antecedent[u][v2];
                }
            }
        }
    }
    return make_pair(FW, antecedent);
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

    map <string, coords> coordinates;

    ifstream CDdata ("PositionTable.dat");
    string City;
    double x, y;
    while(CDdata >> City >> x >> y){
        coords c;
        c.x = x;
        c.y = y;
        coordinates.insert(make_pair (City, c));
    }

    CDdata.close();


    pair<map<string, map<string,int>>, map<string, map<string,string>>> results = FloydWarshall(g);

    cout << "Enter start City: ";
    cin >> CityA;
    cout << "Enter end City: ";
    cin >> CityB;

    vector<string> route;

    route.push_back(CityB);
    while(route.back() != CityA){
        route.push_back(results.second[CityA][route.back()]);
    }

    ofstream graphFile("graph.dot");
    
    graphFile << "graph G {" << endl;
    string prev = "NULL";
    for (string& e : route){
        graphFile << e << "[pos=\"" << coordinates[e].y << "," << coordinates[e].x << "!\"];" << endl;
        if (prev != "NULL"){
            graphFile << e << "--" << prev << "[label=\"" << results.first[e][prev] << "\"];" << endl;
        }
        prev = e;
    }
    graphFile << "}";
    graphFile.close();
}
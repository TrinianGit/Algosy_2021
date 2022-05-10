#include "Graph.hpp"
#include <iostream>

using namespace std;
int main(){

   Graph<string> g = Graph<string>();

    g.addVertex("AB");
    g.addVertex("AC");
    g.addVertex("AD");
    g.addVertex("BA");
    g.addVertex("BC");
    g.addVertex("BD");
    g.addVertex("DA");
    g.addVertex("DB");
    g.addVertex("DC");
    g.addVertex("EA");
    g.addVertex("EB");
    g.addVertex("EC");
    g.addVertex("ED");
    //AB->x
    g.addEdge("AB", "BD");
    g.addEdge("AB", "BC");
    g.addEdge("AB", "DA");
    g.addEdge("AB", "EA");
    g.addEdge("AB", "EB");
    //AC->x
    g.addEdge("AC", "BC");
    g.addEdge("AC", "BD");
    g.addEdge("AC", "DA");
    g.addEdge("AC", "DB");
    g.addEdge("AC", "DC");
    g.addEdge("AC", "EA");
    g.addEdge("AC", "EB");
    g.addEdge("AC", "EC");
    //AD->x
    g.addEdge("AD", "BD");
    g.addEdge("AD", "EA");
    g.addEdge("AD", "EB");
    g.addEdge("AD", "EC");
    g.addEdge("AD", "ED");
    //BA->x
    g.addEdge("BA", "DA");
    g.addEdge("BA", "EA");
    //BC->x
    g.addEdge("BC", "DA");
    g.addEdge("BC", "DB");
    g.addEdge("BC", "DC");
    g.addEdge("BC", "EB");
    g.addEdge("BC", "EC");
    //BD->x
    g.addEdge("BD", "DA");
    g.addEdge("BD", "EB");
    g.addEdge("BD", "EC");
    g.addEdge("BD", "ED");
    //DA->x
    g.addEdge("DA", "EA");
    g.addEdge("DA", "EB");
    g.addEdge("DA", "EC");
    //DB->x
    g.addEdge("DB", "EB");
    g.addEdge("DB", "EC");
    //DC->x
    g.addEdge("DC", "EC");

    g.toDotFile("CrossRoads.dot");


}
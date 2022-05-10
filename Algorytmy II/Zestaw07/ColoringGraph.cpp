#include "Graph.hpp"

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
    //x->AB
    g.addEdge("BD", "AB");
    g.addEdge("BC", "AB");
    g.addEdge("DA", "AB");
    g.addEdge("EA", "AB");
    g.addEdge("EB", "AB");
    //AC->x
    g.addEdge("AC", "BC");
    g.addEdge("AC", "BD");
    g.addEdge("AC", "DA");
    g.addEdge("AC", "DB");
    g.addEdge("AC", "DC");
    g.addEdge("AC", "EA");
    g.addEdge("AC", "EB");
    g.addEdge("AC", "EC");
    //x->AC
    g.addEdge("BC", "AC");
    g.addEdge("BD", "AC");
    g.addEdge("DA", "AC");
    g.addEdge("DB", "AC");
    g.addEdge("DC", "AC");
    g.addEdge("EA", "AC");
    g.addEdge("EB", "AC");
    g.addEdge("EC", "AC");
    //AD->x
    g.addEdge("AD", "BD");
    g.addEdge("AD", "EA");
    g.addEdge("AD", "EB");
    g.addEdge("AD", "EC");
    g.addEdge("AD", "ED");
    //x->AD
    g.addEdge("BD", "AD");
    g.addEdge("EA", "AD");
    g.addEdge("EB", "AD");
    g.addEdge("EC", "AD");
    g.addEdge("ED", "AD");
    //BA->x
    g.addEdge("BA", "DA");
    g.addEdge("BA", "EA");
    //x->BA
    g.addEdge("DA", "BA");
    g.addEdge("EA", "BA");
    //BC->x
    g.addEdge("BC", "DA");
    g.addEdge("BC", "DB");
    g.addEdge("BC", "DC");
    g.addEdge("BC", "EB");
    g.addEdge("BC", "EC");
    //x->BC
    g.addEdge("DA", "BC");
    g.addEdge("DB", "BC");
    g.addEdge("DC", "BC");
    g.addEdge("EB", "BC");
    g.addEdge("EC", "BC");
    //BD->x
    g.addEdge("BD", "DA");
    g.addEdge("BD", "EB");
    g.addEdge("BD", "EC");
    g.addEdge("BD", "ED");
    //x->BD
    g.addEdge("DA", "BD");
    g.addEdge("EB", "BD");
    g.addEdge("EC", "BD");
    g.addEdge("ED", "BD");
    //DA->x
    g.addEdge("DA", "EA");
    g.addEdge("DA", "EB");
    g.addEdge("DA", "EC");
    //x->DA
    g.addEdge("EA", "DA");
    g.addEdge("EB", "DA");
    g.addEdge("EC", "DA");
    //DB->x
    g.addEdge("DB", "EB");
    g.addEdge("DB", "EC");
    //x->DB
    g.addEdge("EB", "DB");
    g.addEdge("EC", "DB");
    //DC->x
    g.addEdge("DC", "EC");
    //x->DC
    g.addEdge("EC", "DC");

    g.DSatur();
}

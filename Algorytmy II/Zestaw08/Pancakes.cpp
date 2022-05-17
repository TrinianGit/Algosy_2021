#include "Graph.hpp"
#include <vector>

using namespace std;

void TopologicalSortRecursive(Graph<string>* g, string vertex, vector<string>& visited, vector<string>& stack){
    visited.push_back(vertex);
    
    for (string s : g->neighbours(vertex)){
		for (vector<string>::iterator it = visited.begin(); it != visited.end();){
            if ((*it) == s){
                break;
            }
            it++;
            if (it == visited.end()){
			    TopologicalSortRecursive(g, s, visited, stack);
            }
        }
    }

	stack.push_back(vertex);
}


vector<string> TopologicalSort(Graph<string>* g){
    vector<string> stack;
    vector<string> visited;

    for (string& s : g->Vertexes()){
        for (vector<string>::iterator it = visited.begin(); it != visited.end();){
            if ((*it) == s){
                break;
            }
            it++;
            if (it == visited.end()){
                TopologicalSortRecursive(g, s, visited, stack);
            }
        }
        if (visited.size() == 0){
            TopologicalSortRecursive(g, s, visited, stack);
        }
    }

    return stack;
}


int main(){
    Graph<string>* g = new Graph<string>();

    g->addVertex("Weź 1 jajko");
    g->addVertex("Weź 1 łyżkę oleju");
    g->addVertex("Weź ¾ szklanki mleka");
    g->addVertex("Weź 1 szklankę proszku do naleśników");
    g->addVertex("Zmieszaj składniki");
    g->addVertex("Podgrzej syrop klonowy");
    g->addVertex("Zjedz rumiany naleśnik polany ciepłym syropem klonowym");
    g->addVertex("Nagrzej patelnię");
    g->addVertex("Wylej część ciasta naleśnikowego na patelnię");
    g->addVertex("Gdy naleśnik jest rumiany od spodu przewróć go i podpiecz z drugiej strony");

    g->addEdge("Weź 1 jajko", "Zmieszaj składniki");
    g->addEdge("Weź 1 łyżkę oleju", "Zmieszaj składniki");
    g->addEdge("Weź ¾ szklanki mleka", "Zmieszaj składniki");
    g->addEdge("Weź 1 szklankę proszku do naleśników", "Zmieszaj składniki");
    g->addEdge("Zmieszaj składniki", "Podgrzej syrop klonowy");
    g->addEdge("Zmieszaj składniki", "Wylej część ciasta naleśnikowego na patelnię");
    g->addEdge("Nagrzej patelnię", "Wylej część ciasta naleśnikowego na patelnię");
    g->addEdge("Wylej część ciasta naleśnikowego na patelnię", "Gdy naleśnik jest rumiany od spodu przewróć go i podpiecz z drugiej strony");
    g->addEdge("Gdy naleśnik jest rumiany od spodu przewróć go i podpiecz z drugiej strony", "Zjedz rumiany naleśnik polany ciepłym syropem klonowym");
    g->addEdge("Podgrzej syrop klonowy", "Zjedz rumiany naleśnik polany ciepłym syropem klonowym");

    g->toDotFile("Pancakes.dot");

    cout << "How to make pancakes step-by-step: " << endl;

    int i = 1;
    vector<string> result = TopologicalSort(g);
    while (!result.empty()){
        cout << i << ". " << result.back() << endl;
        result.pop_back();
        i++;
    }
}
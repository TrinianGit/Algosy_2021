#include "Graph.hpp"
#include "priorityQueues.hpp"
#include <list>
using namespace std;

struct element{
    string v;
    int dist;
    string parent;
};

Graph<string>* BuildGraph(){
    Graph<string>* g = new Graph<string>();
    g->addVertex ("A");
	g->addVertex ("B");
	g->addVertex ("C");
	g->addVertex ("D");
	g->addVertex ("E");
	g->addVertex ("F");
	g->addVertex ("G");
	g->addVertex ("H");
	g->addVertex ("I");
	g->addVertex ("J");

    g->addEdge ("A", "B");
    g->addEdge ("B", "A");
	
    g->addEdge ("B", "C");
    g->addEdge ("C", "B");

	g->addEdge ("C", "H");
    g->addEdge ("H", "C");
	
    g->addEdge ("I", "H");
    g->addEdge ("H", "I");
	
    g->addEdge ("J", "H");
    g->addEdge ("H", "J");
	
    g->addEdge ("H", "G");
    g->addEdge ("G", "H");
	
    g->addEdge ("H", "F");
    g->addEdge ("F", "H");
	
    g->addEdge ("F", "E");
    g->addEdge ("E", "F");
	
    g->addEdge ("E", "D");
    g->addEdge ("D", "E");
	
    g->addEdge ("D", "B");
    g->addEdge ("B", "D");
	
    g->addEdge ("G", "F");
    g->addEdge ("F", "G");

    g->setEdgeValue("A", "B", 3);
    g->setEdgeValue("B", "A", 3);
	
    g->setEdgeValue("B", "C", 2);
    g->setEdgeValue("C", "B", 2);

	g->setEdgeValue("C", "H", 2);
    g->setEdgeValue("H", "C", 2);
	
    g->setEdgeValue("I", "H", 2);
    g->setEdgeValue("H", "I", 2);
	
    g->setEdgeValue("H", "F", 2);
    g->setEdgeValue("F", "H", 2);
	
    g->setEdgeValue("F", "H", 2);
    g->setEdgeValue("H", "F", 2);

    return g;
}

bool Find (string s, vector<element> d){
    for (auto& a : d){
        if (a.v == s){
            return true;
        }
    }
    return false;
}

int distAt (string s, vector<element> d){
    for (auto& a : d){
        if (a.v == s){
            return a.dist;
        }
    }
    return -1;
}
string parentAt(string s, vector<element> d){
    for (auto& a : d){
        if (a.v == s){
            return a.parent;
        }
    }
    return "NULL";
}

void AddToVec (element e, vector<element>& d){
    for (auto& a : d){
        if (a.v == e.v){
            a.dist = e.dist;
            a.parent = e.parent;
            return;
        }
    }
    d.push_back(e);
}

list<string> Dijkstra(Graph<string>* g, string s, string e){
    vector<element> distance;
    element elem;
    elem.v = s;
    elem.parent = s;
    elem.dist = 0;
    distance.push_back(elem);
    priorityQueueBinary<string> pq = priorityQueueBinary<string>();
    pq.addElement(make_pair(s, 0));

    while (!pq.empty()){

        int prio = pq.LowestPrio();
        pair<string, int> current = make_pair(pq.returnLowPrio(), prio);
        if (!Find(current.first, distance)){
            element tmp;
            tmp.v = current.first;
            tmp.dist = INT32_MAX;
            AddToVec(tmp, distance);
        }
        if (current.second > distAt(current.first, distance)){
            continue;
        }
        for (string& n : g->neighbours(current.first)){
            int dst;
            if (current.second != INT32_MAX){
                dst = current.second + g->getEdgeValue(current.first, n);
            }
            else {
                dst = INT32_MAX;
            }

            if (!Find(n, distance)){
                element tmp;
                tmp.v = n;
                tmp.dist = INT32_MAX;
                AddToVec(tmp, distance);
            }

            if (dst < distAt(n, distance)){
                element tmp;
                tmp.v = n;
                tmp.parent = current.first;
                tmp.dist = dst;
                AddToVec(tmp, distance);
                pq.addElement(make_pair(n, dst));
            }
        }
    }
    list<string> route;
    route.push_front(e);
    string current = e;
    while (current != s){
        route.push_front(parentAt(current, distance));
        current = parentAt(current, distance);
    }
    return route;
}

int main(){

    Graph<string>* g = BuildGraph();
	
	cout << "Route from kitchenette (I) to Boss's room (D):" << endl;
    for (auto& a : Dijkstra(g, "I", "D")){
        cout << a << " ";
    }
	cout << endl;
}
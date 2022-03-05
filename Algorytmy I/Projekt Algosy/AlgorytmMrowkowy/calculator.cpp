#include "calculator.h"

Calculator::Calculator(Algorithm* a)
{
    algo = a;
    alpha = a->getAlpha();
    beta = a->getBeta();
}

Graph& Calculator::getGraph(){
    return algo->getGraph();
}

List<std::pair<int,int>>* Calculator::probabilityOnEachRoute(int current, List<int>& routes){
    List<int> routes_copy1 = routes;
    List<int> routes_copy2 = routes;
    double sum_everything = SumEverything(current, routes_copy1);
    List<std::pair<int, double>>* list = probabilityFunc(current, sum_everything, routes_copy2);
    Node<std::pair<int, double>>* head = list->returnGuard()->prev;
    double min = head->value.second;
    while (head != list->returnGuard()->next){
        if (head->value.second < min){
            min = head->value.second;
        }
        head = head->next;
    }
    if (head->value.second < min){
        min = head->value.second;
    }
    head = list->returnGuard()->prev;
    List<std::pair<int, int>>* lista_zwrot = new List<std::pair<int, int>>();
    while (head != list->returnGuard()->next){
        int b = (int)(head->value.second / min);
        std::pair<int, double> p = std::make_pair(head->value.first, b);
        lista_zwrot->push_back(p);
        head = head->next;
    }
    int b = (int)(head->value.second / min);
    std::pair<int, int> p = std::make_pair(head->value.first, b);
    lista_zwrot->push_back(p);
    return lista_zwrot;
}

double Calculator::SumEverything(int current, List<int> &routes){
    double sum = 0;
    while (!routes.empty()){
        int a = routes.pop_front();
        std::pair<int, int> para = std::make_pair(current, a);
        double len = 1.0 / getGraph().returnRouteLen(para);
        double pheromone = getGraph().returnRouteFeromon(para);
        sum += pow(len, beta) * pow(pheromone, alpha);
    }
    return sum;
}

List<std::pair<int, double>>* Calculator::probabilityFunc(int current, double s_e, List<int>& routes){
    List<std::pair<int, double>>* lista = new List<std::pair<int, double>>();
    while (!routes.empty()){
        int a = routes.pop_front();
        std::pair<int, int> para = std::make_pair(current, a);
        double pheromone = pow(getGraph().returnRouteFeromon(para), alpha);
        double len = pow(1.0 / getGraph().returnRouteLen(para), beta);
        double b = (pheromone * len) / (s_e);
        std::pair<int, double> p = std::make_pair(a, b);
        lista->push_back(p);
    }
    return lista;
}

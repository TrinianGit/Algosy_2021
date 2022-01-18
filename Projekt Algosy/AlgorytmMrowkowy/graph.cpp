#include "graph.h"
#include "ui_mainwindow.h"
#include <iostream>

Graph::Graph()
{
    changingP = false;
    changingK = false;
    points = new Dictionary<int, std::pair<int, int>>();
    relation_list = new Dictionary<int, List<int>*>();
    lines_with_distance = new Dictionary<std::pair<int,int>, double>();
    lines_pheromone = new Dictionary<std::pair<int,int>, double>();
    connections = new List<std::pair<int, int>>();
    line_color = new Dictionary<std::pair<int, int>, QGraphicsLineItem*>();
}

bool Graph::get_changingP(){
    return changingP;
}
bool Graph::get_changingK(){
    return changingK;
}
void Graph::change_changingP(){
    if (changingP){
        //std::cout << "To False" << std::endl;
        changingP = false;
    }
    else{
        //std::cout << "To True" << std::endl;
        changingP = true;
        //std::cout << changingP << std::endl;
    }
}

void Graph::change_changingK(){
    if (changingK){
        changingK = false;
    }
    else{
        changingK = true;
    }
}

QGraphicsScene* Graph::getScene(){
    return s;
}

void Graph::points_to_graph(std::string file){
  std::fstream File;
  File.open(file, std::ios::in);
  if(!File){
      std::cout << "No file" << std::endl;
  }
  else{
      int a;
      int b;
      int c = 1;
      while (File >> a){
          File >> b;
          std::pair <int, int> para = std::make_pair(a,b);
          std::pair <int, std::pair<int,int>> punkt = std::make_pair(c, para);
          points->insert(punkt);
          c++;
      }
    }
}
void Graph::connect_points(std::string file, QGraphicsScene *scene){
    s = scene;
    std::fstream File;
    File.open(file, std::ios::in);
    if(!File){
        std::cout << "No file" << std::endl;
    }
    else{
        int a;
        int b;
        int preva = 0;
        bool first = true;
        bool Same = false;
        QPen black(Qt::black);
        QBrush yellow(Qt::yellow);
        QBrush green(Qt::green);
        QBrush red(Qt::red);
        while (File >> a){
            if (!first){
                if(preva == a){
                    Same = true;
                }
                else{
                    Same = false;
                }
            }
            File >> b;
            std::pair<int, int> line = std::make_pair(a, b);
            double l = sqrt(pow((*points)[a].first - (*points)[b].first, 2.0) + pow((*points)[a].second - (*points)[b].second, 2.0));
            std::pair<std::pair<int, int>, double> tolwd = std::make_pair(line, l);
            std::pair<std::pair<int, int>, double> pheromone_null = std::make_pair(line, 1.0);
            connections->push_back(line);
            if (!Same){
                List<int>* lista = new List<int>();
                lista->push_back(b);
                //std::cout << "Tworze liste trasy " << a << " i dodaje do niej puntkt " << b << std::endl;
                std::pair<int, List<int>*> para = std::make_pair(a, lista);
                relation_list->insert(para);
            }
            else{
                //std::cout << "Dodaje punkt " << b << " do listy trasy " << a << std::endl;
                (*relation_list)[a]->push_back(b);
            }
            lines_with_distance->insert(tolwd);
            lines_pheromone->insert(pheromone_null);
            QGraphicsLineItem* line_obj = scene->addLine((*points)[a].first + 5, (*points)[a].second + 5, (*points)[b].first + 5, (*points)[b].second + 5, black);
            std::pair<std::pair<int, int>, QGraphicsLineItem*> pair_line = std::make_pair(line, line_obj);
            line_color->insert(pair_line);
            preva = a;
            first = false;
        }
        scene->addEllipse((*points)[1].first, (*points)[1].second, 10, 10, black, green);
        for (int i = 2; i < points->size(); i++){
            scene->addEllipse((*points)[i].first, (*points)[i].second, 10, 10, black, yellow);
        }
        scene->addEllipse((*points)[points->size()].first, (*points)[points->size()].second, 10, 10, black, red);
    }
}

int Graph::pointSize(){
    return points->size();
}

std::pair<int, int> Graph::returnPoint(int pos){
    return (*points)[pos];
}

List<int>* Graph::returnConnections(int point){
    return (*relation_list)[point];
}

double Graph::returnRouteLen(std::pair<int, int> p){
    return (*lines_with_distance)[p];
}

double Graph::returnRouteFeromon(std::pair<int,int> p){
    return (*lines_pheromone)[p];
}

void Graph::resetPheromone(){
    List<std::pair<int, int>> connections_copy = (*connections);
    Node<std::pair<int, int>>* ptr = connections_copy.returnGuard()->prev;
    while (ptr != connections_copy.returnGuard()->next) {
       (*lines_pheromone)[ptr->value] = 1.0;
       ptr = ptr->next;
    }
    (*lines_pheromone)[ptr->value] = 1.0;

    best_sol = 1000000000;
    best_sol_ants = 0;
}

void Graph::lessPheromone(double percent){
    List<std::pair<int, int>> connections_copy = (*connections);
    Node<std::pair<int, int>>* ptr = connections_copy.returnGuard()->prev;
    while (ptr != connections_copy.returnGuard()->next) {
       (*lines_pheromone)[ptr->value] *= (1.0 - percent);
       ptr = ptr->next;
    }
    (*lines_pheromone)[ptr->value] *= (1.0 - percent);
}

void Graph::updatePheromoneOn(List<int> *Route){
    List<int> route_copy = (*Route);
    List<int> route_copy2 = (*Route);
    double route_lenght_sum = 0;
    int a = 0;
    while(!route_copy2.empty()){
        if (a == 0){
            a = route_copy2.pop_front();
        }
        int b = route_copy2.pop_front();
        std::pair<int, int> connect = std::make_pair(a, b);
        route_lenght_sum += (*lines_with_distance)[connect];
        a = b;
    }
    if (route_lenght_sum <= best_sol){
        best_sol = route_lenght_sum;
        best_sol_ants++;
        best_sol_pts = Route;
    }
    a = 0;
    while(!route_copy.empty()){
        if (a == 0){
            a = route_copy.pop_front();
        }
        int b = route_copy.pop_front();
        std::pair<int, int> connect = std::make_pair(a, b);
        (*lines_pheromone)[connect] += 1000.0 / route_lenght_sum;

        a = b;
    }
}

void Graph::gratificateBest(){
    List<int> route_copy = (*best_sol_pts);
    int a = 0;
    while(!route_copy.empty()){
        if (a == 0){
            a = route_copy.pop_front();
        }
        int b = route_copy.pop_front();
        std::pair<int, int> connect = std::make_pair(a, b);
        (*lines_pheromone)[connect] += 1000.0 * best_sol_ants / best_sol;

        a = b;
    }
}

void Graph::paintCurrBest(){
    List<int> route_copy = (*best_sol_pts);
    int a = 0;
    QPen red(Qt::red);
    while(!route_copy.empty()){
        if (a == 0){
            a = route_copy.pop_front();
        }
        int b = route_copy.pop_front();
        std::pair<int, int> connect = std::make_pair(a, b);
        (*line_color)[connect]->setPen(red);
        a = b;
    }
}

void Graph::allBlack(){
    QPen black (Qt::black);
    List<std::pair<int,int>> connections_copy = (*connections);
    while (!connections_copy.empty()){
        std::pair<int, int> pair = connections_copy.pop_front();
        (*line_color)[pair]->setPen(black);
    }
}

void Graph::resetBestSolAnts(){
    best_sol_ants = 0;
}

int Graph::antsBest(){
    return best_sol_ants;
}

Graph::~Graph(){
    delete points;
    delete lines_with_distance;
    delete lines_pheromone;
    delete connections;
    delete line_color;
    delete relation_list;
}


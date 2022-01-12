#include "graph.h"
#include "ui_mainwindow.h"
#include <iostream>

Graph::Graph()
{
    changingP = false;
    changingK = false;
}

bool Graph::get_changingP(){
    return changingP;
}
bool Graph::get_changingK(){
    return changingK;
}
void Graph::change_changingP(){
    if (changingP){
        std::cout << "To False" << std::endl;
        changingP = false;
    }
    else{
        std::cout << "To True" << std::endl;
        changingP = true;
        std::cout << changingP << std::endl;
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
void Graph::points_to_graph(std::string file, QGraphicsScene *scene){
          std::fstream File;
          File.open(file, std::ios::in);
          if(!File){
              std::cout << "No file" << std::endl;
          }
          int a;
          int b;
          int c = 0;
          while (File >> a){
              File >> b;
              std::pair <int, int> para = std::make_pair(a,b);
              points[c] = para;
              c++;
          }
}
void Graph::connect_points(std::string file, QGraphicsScene *scene){
    std::fstream File;
    File.open(file, std::ios::in);
    if(!File){
        std::cout << "No file" << std::endl;
    }
    int a;
    int b;
    QPen black(Qt::black);
    QBrush yellow(Qt::yellow);
    QBrush green(Qt::green);
    QBrush red(Qt::red);
    while (File >> a){
        File >> b;
        scene->addLine(points[a-1].first + 5, points[a-1].second + 5, points[b-1].first + 5, points[b-1].second + 5, black);
    }
    scene->addEllipse(points[0].first, points[0].second, 10, 10, black, green);
    for (int i = 1; i < 13; i++){
        scene->addEllipse(points[i].first, points[i].second, 10, 10, black, yellow);
    }
    scene->addEllipse(points[13].first, points[13].second, 10, 10, black, red);
}




#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <fstream>
#include <iostream>
#include "dictionary.h"
#include "linkedlist.h"

class Graph
{
public:
    Graph();
    bool get_changingP();
    bool get_changingK();
    void change_changingP();
    void change_changingK();
    QGraphicsScene* getScene();
    void points_to_graph(std::string file);
    void connect_points(std::string file, QGraphicsScene *scene);
    List<int>* returnConnections(int point);
    double returnRouteLen(std::pair<int, int> p);
    double returnRouteFeromon(std::pair<int,int> p);
    std::pair<int, int> returnPoint(int pos);
    void lessPheromone(double percent);
    void resetPheromone();
    void updatePheromoneOn(List<int>* Route);
    void gratificateBest();
    void resetBestSolAnts();
    int antsBest();
    int pointSize();
    void paintCurrBest();
    void allBlack();
    ~Graph();

private:
    Dictionary<int, std::pair<int,int>>* points;
    Dictionary<int, List<int>*>* relation_list;
    Dictionary<std::pair<int, int>, double>* lines_with_distance;
    Dictionary<std::pair<int, int>, double>* lines_pheromone;
    Dictionary<std::pair<int,int>, QGraphicsLineItem*>* line_color;
    List<std::pair<int, int>>* connections;
    QGraphicsScene *s;
    List<int>* best_sol_pts;
    double best_sol;
    int best_sol_ants;
    bool changingP;
    bool changingK;

};

#endif // GRAPH_H

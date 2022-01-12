#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <fstream>
#include <iostream>

class Graph
{
public:
    Graph();
    bool get_changingP();
    bool get_changingK();
    void change_changingP();
    void change_changingK();
    void points_to_graph(std::string file,QGraphicsScene *scene);
    void connect_points(std::string file, QGraphicsScene *scene);

private:
    std::pair<int,int> points[20];
    bool changingP;
    bool changingK;

};

#endif // GRAPH_H

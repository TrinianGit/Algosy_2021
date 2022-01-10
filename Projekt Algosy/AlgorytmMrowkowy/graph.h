#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

class Graph
{
public:
    Graph();
    bool get_changingP();
    bool get_changingK();
    void change_changingP();
    void change_changingK();

private:
    bool changingP;
    bool changingK;

};

#endif // GRAPH_H

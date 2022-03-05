#ifndef MROWKA_H
#define MROWKA_H

class Calculator;

#include "linkedlist.h"
#include "dictionary.h"
#include "calculator.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QEventLoop>
#include <QGraphicsEllipseItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

class Mrowka{
    public:
        Mrowka(int startPoint, QGraphicsScene *scene, int speed, Calculator* a, List<int> *route, int dest);
        void goThrough();
        void goToNextPoint();
        void presentMeGoing(QTimeLine* timer);
        ~Mrowka();

    private:
        List<int>* Route;
        int currentPoint;
        int mySpeed;
        int destination;
        QGraphicsScene *Scene;
        Calculator* Algo;
        QGraphicsEllipseItem* ant;
        QGraphicsItemAnimation* animation;
};

#endif // MROWKA_H

#include "paintthread.h"

PaintThread::PaintThread()
{

}

void PaintThread::giveList(List<int>* l){
    points = l;
}

void PaintThread::setAlgo(Algorithm *Alg){
    A = Alg;
}

void PaintThread::run(){
    List<int> route_copy = (*points);
    int a = 0;
    QGraphicsScene *Scene = A->getGraph().getScene();
    QPen blackpen (Qt::black);
    QBrush blackbrush (Qt::black);
    while (!route_copy.empty()){
        if (a == 0){
            a = route_copy.pop_front();
        }
        int b = route_copy.pop_front();
        std::pair <int, int> punkta = A->getGraph().returnPoint(a);
        std::pair <int, int> punktb = A->getGraph().returnPoint(b);
        int width = punktb.first - punkta.first;
        int height = punktb.second - punkta.second;
        double scale = abs(width) < abs(height) ? height : width;
        //std::cout << scale << std::endl;
        double width_scale = width / abs(scale);
        double height_scale = height / abs(scale);
        QGraphicsEllipseItem *ant = Scene->addEllipse(punkta.first + 1, punkta.second + 1, 8, 8, blackpen, blackbrush);
        QTimeLine* timer = A->returnTimer();
        QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
        animation->setItem(ant);
        animation->setTimeLine(timer);
        //std::cout << width_scale << " " << height_scale << std::endl;
        for (int i = 0; i < abs(scale); i++){
            std::cout << (double)punkta.first + i * width_scale << " " << punkta.second + i * height_scale << std::endl;
            animation->setPosAt(i / abs(scale), QPointF(i * width_scale, i * height_scale));
        }

        A->timerHelp(timer);

        QEventLoop* loop = new QEventLoop;

        QObject::connect(timer, SIGNAL(finished()), loop, SLOT(quit()));
        loop->exec();
        Scene->removeItem(ant);
        delete animation;
        delete timer;
        a = b;
    }
}

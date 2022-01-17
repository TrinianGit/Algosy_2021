#include "algorithm.h"
#include <iostream>

Algorithm::Algorithm()
{
    G = new Graph();
    alpha = 1.03;
    beta = 1.005;
    ants = 10;
    vaporize = 0.01;
    speed = 1;
    active = false;
}

void Algorithm::set_alpha(double a){
    alpha = a;
}

void Algorithm::set_beta(double b){
    beta = b;
}

void Algorithm::set_ants(int number){
    ants = number;
}

void Algorithm::set_speed(int s){
    speed = s;
}

void Algorithm::set_vaporize(double vap){
    vaporize = vap;
}

double Algorithm::getAlpha(){
    return alpha;
}

double Algorithm::getBeta(){
    return beta;
}

bool Algorithm::GetActive(){
    return active;
}

void Algorithm::ChangeActive(){
    if (active){
        active = false;
    }
    else{
        active = true;
    }
}

void Algorithm::startAnt(){
    srand(time(NULL));

    bool one_route = false;
    getGraph().resetPheromone();
    while (!one_route && !finish){
        List<Mrowka*>* list_ants = new List<Mrowka*>();
        int toTimer = 20000 - (190 * speed);
        QTimeLine* timer = new QTimeLine(toTimer);
        timer->setFrameRange(0, 100);
        List<List<int>*>* lista_list = new List<List<int>*>();

        for (int i = 0; i < ants; i++){
            List<int>* Route = new List<int>();
            Calculator* calc = new Calculator(this);
            Mrowka* Ant = new Mrowka(1, getGraph().getScene(), speed, calc, Route, getGraph().pointSize());
            //std::cout << Ant << std::endl;
            Ant->goThrough();
            lista_list->push_back(Route);
            list_ants->push_back(Ant);
            Ant->presentMeGoing(timer);

        }

        timer->start();
        QEventLoop* loop = new QEventLoop;
        QObject::connect(timer, SIGNAL(finished()), loop, SLOT(quit()));
        loop->exec();
        while (!list_ants->empty()){
            Mrowka* toDelete = list_ants->pop_front();
            //std::cout << toDelete << std::endl;
            delete toDelete;
        }
        getGraph().lessPheromone(vaporize);
        Node<List<int>*>* ptr = lista_list->returnGuard()->prev;
        while(ptr != lista_list->returnGuard()->next){
            getGraph().updatePheromoneOn(ptr->value);
            ptr = ptr->next;
        }
        getGraph().updatePheromoneOn(ptr->value);
        one_route = CheckSame();
        getGraph().gratificateBest();
        getGraph().allBlack();
        getGraph().paintCurrBest();

        while (!lista_list->empty()){
            List<int>* li = lista_list->pop_front();
            delete li;
        }

        getGraph().resetBestSolAnts();

        delete list_ants;
        delete lista_list;
    }
    finish = false;
}

bool Algorithm::CheckSame(){
    std::cout << ants * 0.9 << " " <<getGraph().antsBest() << std::endl;
    return ants * 0.9 < getGraph().antsBest() ? true : false;
}

void Algorithm::pendFinish(){
    finish = true;
}

bool Algorithm::getState(){
    return finish;
}

QTimeLine* Algorithm::returnTimer(){
    QTimeLine* timer = new QTimeLine(5000);
    timer->setFrameRange(0,100);
    return timer;
}

void Algorithm::timerHelp(QTimeLine *time){
    time->start();
}

Graph& Algorithm::getGraph(){
    return (*G);
}



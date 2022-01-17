#include "mrowka.h"
#include <random>


Mrowka::Mrowka(int startPoint, QGraphicsScene *scene, int speed, Calculator* a, List<int>* route, int dest){

    currentPoint = startPoint;
    destination = dest;
    Route = route;
    Route->push_back(currentPoint);
    Scene = scene;
    mySpeed = speed;
    Algo = a;
    QPen blackpen (Qt::black);
    QBrush blackbrush (Qt::black);
    ant = Scene->addEllipse(Algo->getGraph().returnPoint(1).first + 1, Algo->getGraph().returnPoint(1).second + 1, 8, 8, blackpen, blackbrush);
    animation = new QGraphicsItemAnimation();
    animation->setItem(ant);

}

void Mrowka::goThrough(){
    while (currentPoint != destination){
        goToNextPoint();
    }
}

void Mrowka::goToNextPoint(){

    List<int>* lista = Algo->getGraph().returnConnections(currentPoint);
    List<int> lista2 = (*lista);
    if (lista2.find(destination) != -1){
        currentPoint = destination;
        Route->push_back(currentPoint);
    }
    else{
        Node<int>* head = Route->returnGuard()->prev;
        while (head != Route->returnGuard()->next){
            int val = head->value;
            int found = 0;
            if ((found = lista2.find(val)) != -1){
                lista2.erase(found);
            }
            head = head->next;
        }
        int val = head->value;
        int found = 0;
        if ((found = lista2.find(val)) != -1){
            lista2.erase(found);
        }
        if (lista2.size() == 0){
            currentPoint = Route->pop_front();
            Route->clear();
        }
        else{
            List<std::pair<int,int>>* probability = Algo->probabilityOnEachRoute(currentPoint, lista2);
            Node<std::pair<int, int>>* head2 = probability->returnGuard()->prev;
            int sum = 0;
            while (head2 != probability->returnGuard()->next){
                sum += head2->value.second;
                head2 = head2->next;
            }
            sum += head2->value.second;
            int random = rand() % sum + 1;
            sum = 0;
            head2 = probability->returnGuard()->prev;
            while(sum < random && head2 != probability->returnGuard()->next){
                sum += head2->value.second;
                head2 = head2->next;
            }
            if(head2 != probability->returnGuard()->next){
                head2 = head2->prev;
                Route->push_back(head2->value.first);
                currentPoint = head2->value.first;
            }
            else if(sum < random){
                Route->push_back(head2->value.first);
                currentPoint = head2->value.first;
            }
            else{
                head2 = head2->prev;
                Route->push_back(head2->value.first);
                currentPoint = head2->value.first;
            }
        }
    }
}

void Mrowka::presentMeGoing(QTimeLine* timer){
    List<int> route_copy = (*Route);
    List<int> route_copy2 = (*Route);
    int a = 0;
    double sum_scale_anim = 0;

    while (!route_copy2.empty()){
        if (a == 0){
            a = route_copy2.pop_front();
        }
        int b = route_copy2.pop_front();
        std::pair <int, int> punkta = Algo->getGraph().returnPoint(a);
        std::pair <int, int> punktb = Algo->getGraph().returnPoint(b);
        int width2 = punktb.first - punkta.first;
        int height2 = punktb.second - punkta.second;
        double scale2 = abs(width2) < abs(height2) ? height2 : width2;

        sum_scale_anim += abs(scale2);

        a = b;
    }
    a = 0;
    //std::cout << sum_scale_anim << std::endl;
    int sum_scale = 0;
    double position_of_a = 0;
    double position_of_b = 0;
    while (!route_copy.empty()){
        if (a == 0){
            a = route_copy.pop_front();
        }
        int b = route_copy.pop_front();
        std::pair <int, int> punkta = Algo->getGraph().returnPoint(a);
        std::pair <int, int> punktb = Algo->getGraph().returnPoint(b);
        int width = punktb.first - punkta.first;
        int height = punktb.second - punkta.second;
        double scale = abs(width) < abs(height) ? height : width;

        double width_scale = width / abs(scale);
        double height_scale = height / abs(scale);

        animation->setTimeLine(timer);

        for (int i = sum_scale; i < sum_scale + abs(scale); i++){
            animation->setPosAt(i / sum_scale_anim, QPointF(position_of_a + (i - sum_scale) * width_scale, position_of_b + (i - sum_scale) * height_scale));
        }
        position_of_a += (abs(scale)) * width_scale;
        position_of_b += (abs(scale)) * height_scale;

        sum_scale += abs(scale);

        a = b;
    }
}

Mrowka::~Mrowka(){
    //std::cout << "Here" << std::endl;
    Scene->removeItem(ant);
    Scene->update();
    delete animation;
}

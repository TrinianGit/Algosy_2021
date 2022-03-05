#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "graph.h"
#include "mrowka.h"
#include "calculator.h"
#include <thread>
#include <unistd.h>

class Algorithm
{
public:
    Algorithm();

    void set_alpha(double a);
    void set_beta(double b);
    void set_ants(int number);
    void set_speed(int s);
    void set_vaporize(double vap);
    double getAlpha();
    double getBeta();
    bool GetActive();
    void ChangeActive();
    void manyAnts();
    Graph& getGraph();
    Graph* graphTOCalc();
    void startAnt();
    void pendFinish();
    bool getState();
    bool CheckSame();
    QTimeLine* returnTimer();
    void timerHelp(QTimeLine *time);

    ~Algorithm();



private:
    Graph* G;
    double alpha;
    double beta;
    int ants;
    int speed;
    double vaporize;
    bool active;
    bool finish;
};



#endif // ALGORITHM_H

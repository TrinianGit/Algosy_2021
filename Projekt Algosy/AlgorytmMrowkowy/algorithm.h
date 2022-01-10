#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "graph.h"

class Algorithm
{
public:
    Algorithm();

    void set_alpha(double a);
    void set_beta(double b);
    void set_ants(int number);
    void set_vaporize(double vap);
    bool GetActive();
    void ChangeActive();
    Graph& getGraph();

private:
    Graph G;
    double alpha;
    double beta;
    int ants;
    double vaporize;
    bool active;
};

#endif // ALGORITHM_H

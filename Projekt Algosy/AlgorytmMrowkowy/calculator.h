#ifndef CALCULATOR_H
#define CALCULATOR_H

class Algorithm;

#include "algorithm.h"
#include "graph.h"

class Calculator
{
    public:
        Calculator(Algorithm* a);
        Graph& getGraph();
        double SumEverything(int current, List<int>& routes);
        List<std::pair<int, int>>* probabilityOnEachRoute(int current, List<int>& routes);
        List<std::pair<int,double>>* probabilityFunc(int current, double s_e, List<int>& routes);

    private:
        Algorithm* algo;
        Graph* g;
        double alpha;
        double beta;

};

#endif // CALCULATOR_H

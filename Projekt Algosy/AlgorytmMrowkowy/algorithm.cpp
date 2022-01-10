#include "algorithm.h"
#include <iostream>

Algorithm::Algorithm()
{
    G = Graph();
    alpha = 1.03;
    beta = 0.005;
    ants = 10;
    vaporize = 0.01;
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
void Algorithm::set_vaporize(double vap){
    vaporize = vap;
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
Graph& Algorithm::getGraph(){
    return G;
}

#include "graph.h"
#include "ui_mainwindow.h"
#include <iostream>

Graph::Graph()
{
    changingP = false;
    changingK = false;
}

bool Graph::get_changingP(){
    return changingP;
}
bool Graph::get_changingK(){
    return changingK;
}
void Graph::change_changingP(){
    if (changingP){
        std::cout << "To False" << std::endl;
        changingP = false;
    }
    else{
        std::cout << "To True" << std::endl;
        changingP = true;
        std::cout << changingP << std::endl;
    }
}
void Graph::change_changingK(){
    if (changingK){
        changingK = false;
    }
    else{
        changingK = true;
    }
}

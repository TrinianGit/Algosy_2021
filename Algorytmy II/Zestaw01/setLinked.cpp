#include <iostream>
#include <chrono>
#include "Sets.hpp"

using namespace std;

int main(){

    std::vector<int> vec;
    double tab[1000];

    for (int i = 0; i < 1000; i++){
        tab[i] = 0.0;
    }

    for (int k = 0; k < 10; k++){
        setLinked* s2 = new setLinked();
        setLinked* s1 = new setLinked();
 
        for (int i = 0; i < 500; i++){
            s1->addElement(i);
            s2->addElement(999 - i);
            
            auto start = std::chrono::system_clock::now();
            s1->setUnion(*s2);
            auto end = std::chrono::system_clock::now();
            auto elapsed = end - start;
            
            tab[i] += elapsed.count();
        }
        delete s1;
        delete s2;
    }

    for (int i = 1; i < 501; i++){
        cout << i*2 << " " << tab[i-1]/1000 << endl;
    }
}
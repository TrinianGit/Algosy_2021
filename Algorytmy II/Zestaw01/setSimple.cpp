#include <iostream>
#include <chrono>
#include "Sets.hpp"

using namespace std;

int main(){

    std::vector<int> vec;
    double tab[500];

    for (int i = 0; i < 500; i++){
        tab[i] = 0;
    }


    for (int k = 0; k < 1000; k++){
        setSimple* s1 = new setSimple(vec, 1000);
        setSimple* s2 = new setSimple(vec, 1000);
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
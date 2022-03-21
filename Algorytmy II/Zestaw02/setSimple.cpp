#include <iostream>
#include <chrono>
#include "Sets.hpp"

using namespace std;

int main(){
    srand(time(NULL));
    double tab[1000];

    for (int i = 0; i < 1000; i++){
        tab[i] = 0;
    }

    for (int k = 0; k < 20000; k++){
        setSimple<string>* s1 = new setSimple<string>(2);
        setSimple<string>* s2 = new setSimple<string>(2);
        cerr << "Progress " << k << "/" << "20000" << endl;
        for (int i = 0; i < 500; i++){
            string st = "";
            string st2 = "";
            for (int j = 0; j < 2; j++){
                st += rand()%26+97;
                st2 += rand()%26+97;
            }
            s1->addElement(st);
            s2->addElement(st2);

            auto start = std::chrono::system_clock::now();
            s1->setIntersection(*s2);
            auto end = std::chrono::system_clock::now();
            auto elapsed = end - start;
            
            tab[i] += elapsed.count();
        }
        delete s1;
        delete s2;
    }

    for (int i = 0; i < 500; i++){
        cout << (i+1)*2 << " " << tab[i]/20000 << endl;
    }
}
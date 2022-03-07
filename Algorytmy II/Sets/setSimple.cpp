#include <iostream>
#include "Sets.h"

using namespace std;

int main(){

    std::vector<int> vec;
    int tab[1000];

    for (int i = 0; i < 1000; i++){
        tab[i] = 0;
    }


    for (int k = 0; k < 1000; k++){
        setSimple* s1 = new setSimple(vec, 1000);
        setSimple* s2 = new setSimple(vec, 1000);
        for (int i = 0; i < 1000; i++){
            s1->addElement(i);
            s2->addElement(999 - i);
            tab[i] += s1->setUnion(*s2);
        }
        delete s1;
        delete s2;
    }

    for (int i = 0; i < 1000; i++){
        cout << i << " " << tab[i]/1000 << endl;
    }
}
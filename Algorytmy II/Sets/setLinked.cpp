#include <iostream>
#include "Sets.h"

using namespace std;

int main(){

    std::vector<int> vec;
    int tab[1000];

    for (int i = 0; i < 1000; i++){
        tab[i] = 0;
    }

    for (int k = 0; k < 10; k++){
        setLinked* s2 = new setLinked();
        setLinked* s1 = new setLinked();

        for (int i = 0; i < 1000; i++){
            if (i % 2 == 0){
                s1->addElement(i / 2);
                s2->addElement((i / 2) + 1);

            }
            tab[i] += s1->setUnion(*s2);
            //cerr << tab[i] << endl;
        }
        delete s1;
        delete s2;
    }

    for (int i = 0; i < 1000; i++){
        cout << i << " " << tab[i]/10 << endl;
    }
}
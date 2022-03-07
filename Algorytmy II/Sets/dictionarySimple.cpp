#include <iostream>
#include "Sets.h"

using namespace std;

int main(){
    srand(time(NULL));
    
    vector<string> strings;
    int tab[1000];

    for (int i = 0; i < 1000; i++){
        tab[i] = 0;
    }

    for (int k = 0; k < 1000; k++){
        dictionarySimple* s1 = new dictionarySimple(strings, 10000);
        for (int i = 0; i < 1000; i++){
            string s = "";
            for (int j = 0; j < 50; j++){
                s += rand()%100+33;
            }
            s1->addElement(s);
            strings.push_back(s);
        }
        for (int i = 0; i < 1000; i++){
            tab[i] += s1->removeElement(strings.back());
            strings.pop_back();
        }
        delete s1;
    }

    for (int i = 0; i < 1000; i++){
        cout << i << " " << tab[i]/1000 << endl;
    }
}
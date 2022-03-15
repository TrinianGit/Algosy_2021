#include <iostream>
#include <chrono>
#include "Sets.hpp"

using namespace std;

int main(){
    srand(time(NULL));
    
    vector<string> strings;
    double tab[1000];

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
            auto start = std::chrono::system_clock::now();
            s1->removeElement(strings.back());
            auto end = std::chrono::system_clock::now();
            auto elapsed = end - start;
            
            tab[i] += elapsed.count();
            strings.pop_back();
        }
        delete s1;
    }

    for (int i = 0; i < 1000; i++){
        cout << i << " " << tab[i]/1000 << endl;
    }
}
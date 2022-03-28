#include "priorityQueues.hpp"
#include <chrono>

using namespace std;

int main (int argc, char* argv[]){

    double tab[1000];

    for (int i = 0; i < 1000; i++){
        tab[i] = 0;
    }

    for (int i = 0; i < 1000; i++){
        priorityQueue<string>* pq = new priorityQueue<string>();
        for (int j = 0; j < 10000; j++){
            string s = "";
            for (int k = 0; k < 5; k++){
                rand() % 2 ? (s += rand() % 26 + 65) : (s += rand() % 26 + 97);
            }
            pq->addElement(s);
        }
        for (int j = 0; j < 10000; j++){
            auto start = std::chrono::system_clock::now();
            pq->returnLowPrio();
            auto end = std::chrono::system_clock::now();
            auto elapsed = end - start;
            
            tab[i] += elapsed.count();
        }
        cout << i << " " << tab[i] / 10000 << endl;
    }
}
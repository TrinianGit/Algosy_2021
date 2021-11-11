#include "ArrayQueue.hpp"
#include <vector>
#include <ctime>


void radix (vector<int>& v){
    vector <Queue> kolejki;
    for (int i = 0; i < 10; i++){
        Queue Kolejka = Queue (1000000);
        kolejki.push_back(Kolejka);
    }
    int zmiany = true;
    int rzad = 1;
    vector<int> pomoc(v);
    while (zmiany){
        zmiany = false;
        while (!v.empty()){
            int x = pomoc.back();
            pomoc.pop_back();
            x/=rzad;
            kolejki[x%10].push(v.back());
            cout << x%10 << ": " << v.back() << endl;
            v.pop_back();
        }
        for (int i = 0; i < 10; i++ ){
            vector <int> odwrot;
            while (!kolejki[i].empty()){
                odwrot.push_back(kolejki[i].pop());
                if (i != 0) zmiany = true;
            }
            while (!odwrot.empty()){
                v.push_back(odwrot.back());
                odwrot.pop_back();
            }
        }

        cout << endl;
        pomoc = v;
        rzad *= 10;
    }
    
}


int main (int argn, char* argv[]){

    srand(time(NULL));
    int x;
    std::vector<int> v;
    while(std::cin >> x){
        v.push_back(x);
    }

    radix(v);

    for (long unsigned int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

static int counter = 0;

template <class T> void sort(vector<T>& v){
    
    
    for (int i = 1; i < v.size(); i++){
        for (int j = v.size()-1; j > i-1; j--){
            counter++;
            if (v[j-1] > v[j]){
                T help = v[j];
                v[j] = v[j-1];
                v[j-1] = help;
            }
        }
    }
}

int main (int argn, char* argv[]){
    int a;

    vector<int> v;

    while(cin >> a){
        v.push_back(a);
    }

    sort<int> (v);

    for(const auto& i : v){
        cout << i << endl;
    }

    cerr << "Liczba operacji dominujacych wynosi: " << counter << endl;
}
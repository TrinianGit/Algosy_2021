#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <class T> void sort(vector<T>& v){
    int min = v[0];
    int max = v[0];
    for (int i = 0; i < v.size(); i++){
        if (v[i] > max){
            max = v[i];
        }
        if (v[i] < min){
            min = v[i];
        }
    }

    vector<T> tmp;
    for (int i = min; i < max + 1; i++){
        tmp.push_back(0);
    }
    for (int i = 0; i < v.size(); i++){
        tmp[v[i]-min]++;
    }
    vector<T> result;
    for (int i = 0; i < tmp.size(); i++, min++){
        for(int j = 0; j < tmp[i]; j++){
            result.push_back(min);
        }
    }

    v = result;
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
}
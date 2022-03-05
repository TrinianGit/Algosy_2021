#include <iostream>
#include <vector>
#include <chrono>

using namespace std;


template <class T> void sort(vector<T>& v){
    vector <T> tmp;
    tmp.push_back(v[0]);
    for (int i = 1; i < v.size(); i++){
        typename vector<T>::iterator it = tmp.begin();

        while (it != tmp.end() && *it < v[i]){
            it++;
        }

        tmp.insert(it, v[i]);
    }
    v = tmp;
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
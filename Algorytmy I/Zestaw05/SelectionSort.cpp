#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <class T> void sort(vector<T>& v){

    for (int i = 0; i < v.size(); i++){
        int min = i;
        for (int j = i; j < v.size(); j++){
            if (v[j] < v[min]){
                min = j;
            }
        }

        int help = v[i];
        v[i] = v[min];
        v[min] = help;

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
}
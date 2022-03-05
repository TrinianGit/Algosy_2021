#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <class T> void sort(vector<T>& v){

    for (int i = 0; i < (v.size() - i); i++){
        int min = i;
        int max = (v.size() - i - 1);
        for (int j = i; j < v.size() - i; j++){
            if (v[j] < v[min]){
                min = j;
            }
            if (v[j] > v[max]){
                max = j;
            }
        }
        if (max != i && min != (v.size() - i - 1)){

            int help = v[i];
            v[i] = v[min];
            v[min] = help;

            help = v[v.size() - i - 1];
            v[v.size()- i - 1] = v[max];
            v[max] = help;
        }
        else if (max == i && min == (v.size() - i - 1)) {
            int help = v[i];
            v[i] = v[min];
            v[min] = help;
        }
        else if (max != i && min == (v.size() - i - 1)){
            int help = v[i];
            v[i] = v[min];
            v[min] = help;

            help = v[v.size() - i - 1];
            v[v.size()- i - 1] = v[max];
            v[max] = help;
        }
        else if (max == i && min != (v.size() - i - 1)){
            int help = v[i];
            v[i] = v[min];
            v[min] = help;

            max = min;
            
            help = v[v.size() - i - 1];
            v[v.size()- i - 1] = v[max];
            v[max] = help;
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
}
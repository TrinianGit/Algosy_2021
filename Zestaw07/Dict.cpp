#include <iostream>
#include <fstream>
#include "Dict.hpp"

using namespace std;


int main (int argn, char* argv[]){
    if (argn < 2){
        cerr << "Not Enough Arguments";
        exit(EXIT_FAILURE);
    }
    fstream file;
    Dict<string,string> D = Dict<string,string>();
    string a;
    string b;

    file.open(argv[1], fstream::in);
    while (file >> a){
        file >> b;
        pair<string,string> p = make_pair(a,b);
        D.insert(p);
    }
    file.close();
    while (cin >> a){
        if (D.find(a)){
            cout << D[a] << endl;
        }
        else{
            cout << "-" << endl;
        }
    }
    D.buckets();
}

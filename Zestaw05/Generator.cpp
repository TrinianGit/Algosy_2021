#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main (int argn, char* argv[]){

    srand(time(NULL));

    int ilosc = 0;
    int max = 0;
    
    if(argn == 3){
        ilosc = atoi (argv[1]);
        max = atoi (argv[2]);
    }
    else if (ilosc <= 0 || max <= 0){
        cin >> ilosc;
        cin >> max;
    }
    
    while (ilosc != 0){
        cout << rand()%max+1 << endl;
        ilosc--;
    }
    return 0;
}
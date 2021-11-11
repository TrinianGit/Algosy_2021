#include <iostream>
#include <ctime>

using namespace std;

int main (int argn, char* argv[]){
    srand(time(NULL));

    int wylosowana;
    int losowanie;
    int ilosc = 100; //rand()%999999+1;
    
    cout << ilosc;

    for (int i = 0; i<ilosc; i++){

        losowanie = rand()%3;
        
        switch (losowanie){
            case 0:
                wylosowana = rand()%1000001;
                cout << "A";
                cout << wylosowana;
                break;
            case 1:
                cout << "D";
                break;
            case 2:
                cout << "S";
                break;
            default:
                break;
        }

    }
    return 0;
}
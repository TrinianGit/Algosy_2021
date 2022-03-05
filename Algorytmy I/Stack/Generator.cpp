#include <iostream>
#include <ctime>

using namespace std;

int main (int argn, char* argv[]){
    srand(time(NULL)); // potrzebne do generowania liczb pseudolosowych

    int wylosowana; // zmienna przechowujaca wartosc wylosowanej liczby
    int losowanie; // zmienna przechowujaca wartosc wylosowanej liczby
    int ilosc = rand()%999999+1; // losowanie liczby od 1 do 1000000
    
    cout << ilosc;

    for (int i = 0; i<ilosc; i++){

        losowanie = rand()%3; // losowanie liczby od 0 do 2
        
        switch (losowanie){
            case 0:
                wylosowana = rand()%1000001; // losowanie liczby od 0 do 1000000
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
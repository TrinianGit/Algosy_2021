#include "LinkedQueue.hpp"

int main(int argn, char* Argv[]){

    char litera;
    int liczba;
    int ilosc;
    Queue Kolejka = Queue(1000000);
    
    cin >> ilosc;

    

    while (ilosc != 0){
        cin >> litera;
        switch (litera){
            case 'A':
                cin >> liczba;
                Kolejka.push(liczba);
                cout << "Dodano liczbe " << liczba << " na stos" << endl;
                break;
            case 'D':
                if (Kolejka.empty()){
                    cout << "EMPTY" << endl;
                    break;
                }
                cout << "Usunieto liczbe " << Kolejka.pop() << " ze stosu" << endl;
                break;
            case 'S':
                cout << "Liczba elementow na stosie to: " << Kolejka.size() << endl;
                break;
            default:
                break;
        }
        ilosc--;
    }
    return 0;
}
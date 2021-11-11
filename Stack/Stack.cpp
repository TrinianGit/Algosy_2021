#include "LinkedStack.hpp" // plik naglowkowy z klasa Stack

int main(int argn, char* Argv[]){

    char litera; // zmienna przechowujaca odczytana litere
    int liczba; // zmienna przechowujaca odczytana liczbe
    int ilosc; // zmienna przechowujaca ilosc operacji do wykonania
    
    Stack Stos = Stack(1000000); // utworzenie nowego stosu
    
    cin >> ilosc;

    

    while (ilosc != 0){
        cin >> litera;
        switch (litera){ // switch zawierajacy rozne dzialania w zaleznosci od odczytanej litery 
            case 'A': // dodawanie liczby na stos
                cin >> liczba;
                Stos.push(liczba);
                cout << "Dodano liczbe " << liczba << " na stos" << endl;
                break;
            case 'D': // usuwanie liczby ze stosu
                if (Stos.empty()){
                    cout << "EMPTY" << endl;
                    break;
                }
                cout << "Usunieto liczbe " << Stos.pop() << " ze stosu" << endl;
                break;
            case 'S': // wyswietlanie liczby elementow na stosie
                cout << "Liczba elementow na stosie to: " << Stos.size() << endl;
                break;
            default:
                break;
        }
        ilosc--;
    }
    return 0;
}
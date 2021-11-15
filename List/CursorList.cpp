#include "CursorList.hpp"

using namespace std;

int main(int argn, char* Argv[]){

    char litera;
    int liczba;
    int ilosc;
    int found = 0;
    List Lista = List();
    
    cin >> ilosc;

    int i = 2;

    while (ilosc != 0){
        cin >> litera;
        cout << i << ": " << flush;
        i++;
        switch (litera){
            case 'F':
                cin >> liczba;
                Lista.push_front(liczba);
                break;
            case 'B':
                cin >> liczba;
                Lista.push_back(liczba);
                break;
            case 'f':
                if (Lista.empty()){
                    cout << "EMPTY" << endl;
                    break;
                }
                cout << Lista.pop_front() << endl;
                break;
            case 'b':
                if (Lista.empty()){
                    cout << "EMPTY" << endl;
                    break;
                }
                cout << Lista.pop_back() << endl;
                break;
            case 'R':
                int liczba2;
                cin >> liczba;
                cin >> liczba2;
                cout << endl;
                Lista.show();
                if ((found = Lista.find(liczba)) == -1) cout << "FALSE" << endl;
                else {
                    Lista.show();
                    Lista.erase(found);
                    Lista.show();
                    Lista.insert(found, liczba2);
                    cout << "TRUE" << endl;
                }
                break;
            case 'S':
                cout << Lista.size() << endl;
                break;
            default:
                break;
        }
        ilosc--;
    }
    return 0;
}
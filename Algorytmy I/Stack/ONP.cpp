#include "LinkedStack.hpp"
#include <cstring>

void wypisywanie(Stack* characters){ // funkcja wypisujaca znaki na stosie az do znaku '('
    char character;
    while ((character = characters->pop()) != '('){
        if (character != '(') cout << character << " ";
    }
}

int main (int argn, char* Argv[]){

    Stack characters = Stack(1000000); // tworzenie nowego stosu
    
    string input; // napis zawierajacy rownanie

    getline(cin, input); // czytanie linii ze standardowego wejscia
    
    int n = input.length(); // sprawdzanie dlugosci napisu

    char* equation = new char [n+1]; // tworzenie tablicy char
    
    strcpy(equation, input.c_str()); // kopiowanie stringa do char*

    char* ptr;
    ptr = strtok(equation, " "); // dzielenie char* na mniejsze kawalki wzgledem znaku spacji

    while (ptr != NULL){
        if (atoi(ptr) == 0){ // sprawdzanie czy znak to zero czy nie
            if (!strcmp(ptr, "0")){
                cout << ptr << " ";
            }
            else {
                char character = ptr[0];
                if (character == ')'){ // jezeli ')' wywolana jest funkcja wypisywania
                   wypisywanie(&characters);
                }
                else { // w przeciwnym razie znak umieszczany na stosie
                    characters.push(character);
                }
            }
        }
        else{
            cout << ptr << " "; // jezeli badana czesc napisu nie jest ani zerem ani znakiem to wypisz na standardowe wyjscie
        }
        ptr = strtok (NULL, " "); // dalszy podzial napisu
    }
    cout << endl;
    delete[] equation; // usuwanie dynamicznie zaalokowanej pamieci
    return 0;
}
#ifndef _HPP_ARRAYSTACK
#define _HPP_ARRAYSTACK

#include <iostream>

using namespace std;

class Stack{ // klasa Stack
    public:
        Stack(int capacity){ // konstruktor klasy Stack
            Array = new int[capacity];
            top = 0;
            Array_size = capacity;
        }

        void push(int x){ // dodwanie elementu na stos
            if (top == Array_size){
                cerr << "Out of range error: Array full" << endl;
                exit(-1);
            }
            Array[top] = x;
            top++;
        }
        
        int pop(){ // usuwanie elementu na stosie
            if (empty()){
                cerr << "Out of range error: Array empty" << endl;
                exit(-1);
            }
            top--;
            return Array[top];
        }
        
        int size(){ // informacja o ilosci elementow na stosie
            return top;
        }
        
        bool empty(){ // informacja czy stos jest pusty
            if (top == 0) return true;
            return false;
        }
        
        ~Stack(){ // destruktor klasy Stack
            delete [] Array;
        }


    private:
        int* Array; // tablica reprezentujaca stos
        int top; // liczba informujaca o miejscu zapisu kolejnego elementu a takze o rozmiarze stosu
        int Array_size; // aktualny rozmiar stosu
};

#endif
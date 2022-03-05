#ifndef _HPP_LINKEDSTACK
#define _HPP_LINKEDSTACK

#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* pointer;
} node;

class Stack{
    public:
        Stack(int capacity = 0){ // konstruktor klasy Stack
            Stack_size = 0;
            ptr = nullptr;
        }

        void push(int x){ // dodawanie elementu na stos
            Node* new_node = new Node();
            new_node->pointer = ptr;
            new_node->value = x;
            ptr = new_node;
            Stack_size++;
        }

        int pop(){ // usuwanie elementu ze stosu
            if (empty()){
                cerr << "Out of range error: Array empty" << endl;
                exit(-1);
            }
            int help = ptr->value;
            Node* ToDelete = ptr;
            ptr = ptr->pointer;
            delete ToDelete;
            Stack_size--;
            return help;
        }

        int size(){ // informacja o ilosci elementow na stosie
            return Stack_size;
        }
        
        bool empty(){ // informacja czy stos jest pusty
            if (Stack_size == 0){
                return true;
            }
            return false;
        }

    private:
        int Stack_size; // aktualny rozmiar stosu
        Node* ptr; // wskaznik na gorny element stosu

};


#endif

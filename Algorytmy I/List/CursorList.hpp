#ifndef _HPP_CURSORLIST
#define _HPP_CURSORLIST

#include <iostream>

struct Node{
    int prev;
    int value;
    int next;
};

class List{
    public:
        List (int capacity = 1000000){
            FreeListCreator(capacity);
            head = 0;
            tail = 0;
        }
        
        void FreeListCreator(int capacity){
            Array = new Node[capacity];
            Array_size = capacity;
            Actual_size = 0;
            spare = 0;
            while (Actual_size != Array_size){
                InitFreeList();
            }
            Actual_size = 0;
            spare = 0;
        }

        void InitFreeList(){
            if (spare + 1 == Array_size) {
                Array[spare].next = 0;
            }
            else {
                Array[spare].next = spare + 1;
            }
            if (spare - 1 == -1){
                Array[spare].prev = Array_size - 1;
            }
            else{
                Array[spare].prev = spare - 1;
            }
            Actual_size++;
            spare++;
        }

        void push_front(int x){
            if (Actual_size == Array_size){
                throw std::out_of_range("full");
            }
            int help = Array[spare].next;
            Array[head].prev = spare;
            Array[spare].value = x;
            Array[spare].next = head;
            head = spare;
            spare = help;
            if (Actual_size == 0){
                tail = head;
            }
            Actual_size++;
        }

        int pop_front(){
            if (empty()){
                throw std::out_of_range("empty");
            }
            int x = Array[head].value;
            int help = head;
            head = Array[head].next;
            Array[help].next = spare;
            spare = help;
            Actual_size--;
            if (Actual_size == 0){
                head = spare;
                tail = spare;
            }
            return x;
        }

        void push_back(int x){
            if (Actual_size == Array_size){
                throw std::out_of_range("full");
            }
            int help = Array[spare].next;
            Array[spare].value = x;
            Array[spare].prev = tail;
            Array[tail].next = spare;
            tail = spare; 
            spare = help;
            if (Actual_size == 0){
                head = tail;
            }
            Actual_size++;
        }

        int pop_back(){
            if (empty()){
                throw std::out_of_range("empty");
            }
            int x = Array[tail].value;
            int help = tail;
            tail = Array[tail].prev;
            Array[help].next = spare;
            spare = help;
            Actual_size--;
            if (Actual_size == 0){
                head = spare;
                tail = spare;
            }
            return x;
        }

        int size(){
            return Actual_size;
        }

        bool empty(){
            if (Actual_size == 0) return true;
            return false;
        }

        void clear(){
            while (!empty()){
                pop_front();
            }
        }

        int find(int x){
            if (empty()) return -1;
            int position = 0;
            int i;
            for (i = head; Array[i].value != x  && (position < Actual_size); position++, i = Array[i].next);
            if (Array[i].value == x) return position;
            return -1;
        }

        int erase(int i){
            if (i == 0){
                return pop_front();
            }
            int position = head;
            int save;

            while (i != 0){
                if (i == 1) save = position;
                position = Array[position].next;
                i--;
            }
            Array[save].next = Array[position].next;
            Array[Array[position].next].prev = save;
            Array[position].next = spare;
            spare = position;
            Actual_size--;
            return Array[position].value;

        }

        void insert(int i, int x) {
            if (i==0){
                push_front(x);
            }
            else{
                int position = head;
                int save;
                int toSpare = Array[spare].next;
                Array[spare].value = x;
                while (i != 0){
                    if (i == 1) save = position;
                    position = Array[position].next;
                    i--;
                }
                Array[spare].prev = save;
                Array[save].next = spare;
                Array[spare].next = position;
                Array[position].prev = spare;
                spare = toSpare;
                Actual_size++;
            }
        }

        void show(){
            int position = 0;
            for (int i = head; position < Actual_size; position++){
                std::cout << Array[i].value << " ";
                i = Array[i].next; 
            }
            std::cout << std::endl;
        }

        ~List(){
            delete[] Array;
        }

    private:
        Node* Array;
        int Actual_size;
        int Array_size;
        int head;
        int tail;
        int spare;

};

#endif
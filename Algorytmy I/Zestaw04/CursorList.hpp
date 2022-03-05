#ifndef _HPP_CURSORLIST
#define _HPP_CURSORLIST

#include <iostream>

struct Node{
    int value;
    int next;
};
// ArraySize = capacity = 1000 0-999 Array[Arraysize] -> Array[1000] out_of_bounds
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
            Actual_size++;
            spare++;
        }

        void push_front(int x){
            if (Actual_size == Array_size){
                throw std::out_of_range("full");
            }
            int help = Array[spare].next;
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
            int i;
            int x = Array[tail].value;
            Array[tail].next = spare;
            spare = tail;
            for (i = head; i != tail && Array[i].next != tail; i = Array[i].next);
            tail = i;
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
                Array[save].next = spare;
                Array[spare].next = position;
                spare = toSpare;
                Actual_size++;
            }
        }
        
        int remove(int x){
            int count = 0;
            int save = head;
            for (int i = head; i != tail; i = Array[i].next){
                if (Array[i].value == x){
                    Array[save].next = Array[i].next;
                    Array[i].next = spare;
                    spare = i;
                    count++;
                }
                save = i;
            }

            Actual_size -= count;
            return count;
        }

        ~List(){
            delete[] Array;
        }

        // delete Cos -> typ* Cos
        // typ* Cos = new typ(inicjalizacja)
        // delete [] Cos_innego -> typ* Cos_innego
        // typ* Cos_innego = new typ[ilosc_elementow]

    private:
        Node* Array;
        int Actual_size;
        int Array_size;
        int head;
        int tail;
        int spare;

};

#endif
#ifndef _HPP_ARRAYLIST
#define _HPP_ARRAYLIST

#include <iostream>

class List{
    public:
        List (int capacity = 1000000){
            Array = new int[capacity];
            Array_size = capacity;
            Actual_size = 0;
            front = Array_size/2;
            back = (Array_size/2);
        }

        void push_front(int x){
            if (Actual_size == Array_size){
                throw std::out_of_range("full");
            }
            Array[front] = x;
            front--;
            if (front == -1) front = Array_size - 1;
            Actual_size++;
        }

        int pop_front(){
            if (empty()){
                throw std::out_of_range("empty");
            }
            front++;
            if (front == Array_size) front = 0;
            int x = Array[front];
            Array[front] = 0;
            Actual_size--;
            return x;
        }

        void push_back(int x){
            if (Actual_size == Array_size){
                throw std::out_of_range("full");
            }
            back++;
            if (back == Array_size) back = 0;
            Array[back] = x;
            Actual_size++;
        }

        int pop_back(){
            if (empty()){
                throw std::out_of_range("empty");
            }
            int x = Array[back];
            Array[back] = 0;
            back--;
            if (back == -1) back = Array_size - 1;
            Actual_size--;
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
            int position = front + 1;
            while (Array[position] != x && position != back){
                position++;
                if (position == Array_size) position = 0;
            }
            if (Array[position] == x && position != back) return position - front;
            return -1;
        }

        int erase(int i){
            i = i + 1;
            int position = front - 1;
            int next = position + 1;
            if (next == Array_size) next = 0;
            int change = 0;
            int ToReturn = 0;
            int searched = 0;
            while (i != 0){
                if (i == 1) ToReturn = Array[next];
                change = searched;
                searched = Array[next];
                Array[next] = change;
                next++;
                if (next == Array_size) position = 0;
                i--;
            }
            front++;
            Actual_size--;
            return ToReturn;
        }

        void insert(int i, int x) {
            if (i == 0) {
                push_front(x);
            }
            else{
                i = i + 1;
                int position = front - 2;
                int prev = position - 1;
                if (prev == -1) prev = Array_size - 1;
                int next = position + 1;
                if (next == Array_size) next = 0;
                while (i != 0){
                    Array[prev] = Array[position];
                    Array[position] = Array[next];
                    position++;
                    if (position == Array_size) position = 0;
                    prev = position - 1;
                    if (prev == -1) prev = Array_size - 1;
                    next = position + 1;
                    if (next == Array_size) next = 0;
                    i--;
                }
                Array[position] = x;
                front--;
                Actual_size++;
            }

        }

        int remove(int x){
            int count = 0;
            for (int i = front + 1; i != back;){
                
                if (Array[i] == x){
                    erase(i - front);
                    count++;
                }

                i++;

                if (i == Array_size) {
                    i = 0;
                }
            }

            Actual_size -= count;
            return count;
        }

        ~List(){
            delete[] Array;
        }

    private:
        int* Array;
        int Actual_size;
        int Array_size;
        int front;
        int back;

};

#endif
#ifndef _HPP_ARRAYQUEUE
#define _HPP_ARRAYQUEUE

#include <iostream>

using namespace std;

class Queue{
    
    public:
        Queue(int capacity){
            Array = new int[capacity];
            Array_size = capacity;
            Actual_size = 0;
            head = 0;
            tail = 0;
        }
        
        void push(int x){
            if (Array_size == Actual_size){
                cerr << "Out of range: Queue full" << endl;
                exit(-1);
            }
            Array[head] = x;
            head++;
            if (head%Array_size == 0) head = 0;
            Actual_size++;
        }
        
        int pop(){
            if (empty()){
                cerr << "Out of range: Queue empty" << endl;
                exit(-1);
            }
            int x = Array[tail];
            tail++;
            if (tail%Array_size == 0) tail = 0;
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

    private:
        int* Array;
        int Array_size;
        int Actual_size;
        int head;
        int tail;
};

#endif
#ifndef _HPP_LINKEDQUEUE
#define _HPP_LINKEDQUEUE

#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* ptr;
} node;

class Queue{
    
    public:
        Queue(int capacity = 0){
            head = nullptr;
            tail = nullptr; 
            Actual_size = 0;          
        }
        
        void push(int x){
            Node* new_node = new Node();
            if (head != nullptr) head->ptr = new_node;
            head = new_node;
            if (tail == nullptr) tail = new_node;
            new_node->value = x;
            Actual_size++;
        }
        
        int pop(){
            if (empty()){
                cerr << "Out of Range: Empty Queue" << endl;
                exit(-1); 
            }
            int x = tail->value;
            Node* toDelete = tail;
            Actual_size--;
            if (Actual_size == 0){
                head = nullptr;
                tail = nullptr;
            }
            else tail = tail->ptr;
            delete toDelete;
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
        int Actual_size;
        Node* head;
        Node* tail;
};

#endif
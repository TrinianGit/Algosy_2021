#ifndef _HPP_LINKEDLIST
#define _HPP_LINKEDLIST

#include <iostream>

struct Node{
    Node* prev;
    int value;
    Node* next;
};


class List{
    public:
        List (){
            guard = new Node;
            guard->prev = guard;
            guard->next = guard;
            Actual_size = 0;
        }

        void push_front(int x){
            Node* new_node = new Node;
            new_node->value = x;
            new_node->next = guard->prev;
            Node* gp = guard->prev;
            gp->prev = new_node;
            guard->prev = new_node;
            if (Actual_size == 0) guard->next = guard->prev;
            Actual_size++;
        }

        int pop_front(){
            if (Actual_size == 0){
                throw std::out_of_range("Empty");
            }
            Node* gp = guard->prev;
            int x = gp->value;
            guard->prev = gp->next;
            Actual_size--;
            if (Actual_size == 0) {
                guard->prev = guard;
                guard->next = guard;
            }
            delete gp;
            return x;
        }

        void push_back(int x){
            Node* new_node = new Node;
            Node* gn = guard->next;
            new_node->value = x;
            new_node->prev = guard->next;
            gn->next = new_node;
            guard->next = new_node;
            if (Actual_size == 0) guard->prev = guard->next;
            Actual_size++;
        }

        int pop_back(){
            if (Actual_size == 0){
                throw std::out_of_range("Empty");
            }
            Node* gn = guard->next;
            int x = gn->value;
            guard->next = gn->prev;
            Actual_size--;
            if (Actual_size == 0) {
                guard->prev = guard;
                guard->next = guard;
            }
            delete gn;
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
            int position = 0;
            Node* search = guard->prev;
            while ( (search != (guard->next)) && (search->value != x) ){
                search = search->next;
                position++;
            }
            if (search == (guard->next)) return -1;
            return position;
        }

        int erase(int i){
            if (i == Actual_size) return pop_back();
            else if (i == 0) return pop_front();
            Node* search = guard->prev;
            int x;
            while (i != 0){
                search = search->next;
                i--;
            }
            Node* n = search->next;
            Node* p = search->prev;
            p->next = search->next;
            n->prev = search->prev;
            x = search->value;
            delete search;
            Actual_size--;
            return x;
        }

        void insert(int i, int x) {
            if (i == 0) {
                push_front(x);
            }
            else if (i == (Actual_size - 1) ){
                push_back(x);
            }
            else{
                Node* add = new Node;
                Node* search = guard->prev;
                add->value = x;
                while (i != 0){
                    search = search->next;
                    i--;
                }
                Node* p = search->prev;
                add->next = search;
                add->prev = p;
                p->next = add;
                search->prev = add;
                Actual_size++;
            }

        }

        int remove(int x){
            Node* search = guard->prev;
            int count = 0;
            while ( search != (guard->next) ){
                if (search->value == x){
                    (search->next)->prev = (search->prev);
                    (search->prev)->next = (search->next);
                    delete search;
                    count++;
                }
            }
            return count;
        }

        ~List(){
            clear();
        }

    private:
        Node* guard;
        int Actual_size;

};

#endif
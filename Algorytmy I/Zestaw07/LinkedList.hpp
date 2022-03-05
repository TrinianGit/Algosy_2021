#ifndef _HPP_LINKEDLIST
#define _HPP_LINKEDLIST

#include <iostream>

template <class T>
struct Node{
    Node<T>* prev;
    T value;
    Node<T>* next;
};

template<class T>
class List{
    public:


        List (){
            guard = new Node<T>;
            guard->prev = guard;
            guard->next = guard;
            Actual_size = 0;
        }

        List (const List& l){
            this->guard = new Node<T>;
            this->guard->prev = guard;
            this->guard->next = guard;
            Actual_size = 0;
            Node<T>* head = l.returnGuard()->prev;
            while (head != l.returnGuard()->next){
                T obiekt = head -> value;
                this->push_back(obiekt);
                head = head->next;
            }
            T obiekt = head -> value;
            this->push_back(obiekt);
        }

        Node<T>* returnGuard(){
            return guard;
        }

        Node<T>* returnGuard() const{
            return guard;
        }

        void show(){
            Node<T>* head = guard->prev;
            for(; head != guard->next; head = head->next){
                std::cout << head->value << std::endl;
            }
            std::cout << head->value << std::endl;
        }

        void push_front(T x){
            Node<T>* new_node = new Node<T>;
            new_node->value = x;
            new_node->next = guard->prev;
            Node<T>* gp = guard->prev;
            gp->prev = new_node;
            guard->prev = new_node;
            if (Actual_size == 0) guard->next = guard->prev;
            Actual_size++;
        }

        T pop_front(){
            if (Actual_size == 0){
                throw std::out_of_range("Empty");
            }
            Node<T>* gp = guard->prev;
            T x = gp->value;
            guard->prev = gp->next;
            Actual_size--;
            if (Actual_size == 0) {
                guard->prev = guard;
                guard->next = guard;
            }
            delete gp;
            return x;
        }

        void push_back(T x){
            Node<T>* new_node = new Node<T>;
            Node<T>* gn = guard->next;
            new_node->value = x;
            new_node->prev = guard->next;
            gn->next = new_node;
            guard->next = new_node;
            if (Actual_size == 0) guard->prev = guard->next;
            Actual_size++;
        }

        T pop_back(){
            if (Actual_size == 0){
                throw std::out_of_range("Empty");
            }
            Node<T>* gn = guard->next;
            T x = gn->value;
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

        int find(T x){
            int position = 0;
            Node<T>* search = guard->prev;
            while ( (search != (guard->next)) && (search->value != x) ){
                search = search->next;
                position++;
            }
            if (search == (guard->next) && (search->value != x)) return -1;
            std::cout << position << std::endl;
            return position;
        }

        T erase(int i){
            if (i == Actual_size - 1) return pop_back();
            else if (i == 0) return pop_front();
            Node<T>* search = guard->prev;
            T x;
            while (i != 0){
                search = search->next;
                i--;
            }
            Node<T>* n = search->next;
            Node<T>* p = search->prev;
            p->next = search->next;
            n->prev = search->prev;
            x = search->value;
            delete search;
            Actual_size--;
            return x;
        }

        void insert(int i, T x) {
            if (i == 0) {
                push_front(x);
            }
            else if(i == Actual_size){
                push_back(x);
            }
            else{
                Node<T>* add = new Node<T>;
                Node<T>* search = guard->prev;
                add->value = x;
                while (i != 0){
                    search = search->next;
                    i--;
                }
                Node<T>* p = search->prev;
                add->next = search;
                add->prev = p;
                p->next = add;
                search->prev = add;
                Actual_size++;
            }

        }

        int remove(int x){
            int count = 0;
            int found;
            while ( (found = find(x) != -1) ){
                erase(x);
                count++;
            }
            Actual_size-=count;
            return count;
        }

        ~List(){
            clear();
        }

    private:
        Node<T>* guard;
        int Actual_size;

};

#endif
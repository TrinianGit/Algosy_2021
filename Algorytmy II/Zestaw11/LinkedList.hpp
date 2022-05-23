#ifndef _HPP_LINKEDLIST
#define _HPP_LINKEDLIST

#include <iostream>
#include "LinkedList.hpp"

template <class T>
struct Node{
    Node* prev;
    T value;
    Node* next;
};

template <class T, class X>
class List{
    
    public:

        class iterator{
            public:

                iterator(Node<T>* n) noexcept{
                    ptr = n;
                }


                iterator& operator=(Node<T>* n){
                    this->ptr = n;
                    return *this;
                }

                iterator& operator=(iterator& it){
                    this->ptr = it.ptr;
                    return *this;
                }

                iterator& operator=(iterator it){
                    this->ptr = it.ptr;
                    return *this;
                }

                iterator& operator++(){
                    ptr = ptr->next;
                    return *this;
                }

                iterator operator++(int){
                    iterator it = *this;
                    ++*this;
                    return it;
                }

                bool operator==(const iterator& it){
                    return ptr == it.ptr;
                }

                bool operator!=(const iterator& it){
                    return ptr != it.ptr;
                }

                T& operator*(){
                    return ptr->value;
                }

                Node<T>* getptr(){
                    return ptr;
                }

            private:
                Node<T>* ptr;
        };



        List (X ident){
            guard = new Node<T>;
            guard->prev = guard;
            guard->next = guard;
            Identifier = ident;
            Actual_size = 0;
        }

        List (const List& l){
            this->guard = new Node<T>;
            this->guard->prev = guard;
            this->guard->next = guard;
            Identifier = l.Identifier;
            Actual_size = 0;
            List<T, X>::iterator it = l.begin();
            while (it != l.end()){
                T obiekt = *it;
                this->push_back(obiekt);
                it++;
            }
        }

        List (List&& l){
            this->guard = l.guard;
            Actual_size = l.Actual_size;
            Identifier = l.Identifier;
            while (!l.empty()){
                T obiekt = l.pop_front();
                this->push_front(obiekt);
            }
            l.guard = new Node<T>;
        }

        List<T, X>& operator=(List<T, X> l){
            this->guard = new Node<T>;
            this->guard->prev = guard;
            this->guard->next = guard;
            Actual_size = 0;
            List<T, X>::iterator it = l.begin();
            while (it != l.end()){
                T obiekt = *it;
                this->push_back(obiekt);
                it++;
            }
            return *this;
        }

        List<T, X>& operator=(List<T, X>& l){
            this->guard = new Node<T>;
            this->guard->prev = guard;
            this->guard->next = guard;
            Actual_size = 0;
            List<T, X>::iterator it = l.begin();
            while (it != l.end()){
                T obiekt = *it;
                this->push_back(obiekt);
                it++;
            }
            return *this;
        }

        iterator begin(){
            return iterator(guard->next);
        }

        iterator end(){
            return iterator(guard);
        }

        iterator begin() const{
            return iterator(guard->next);
        }

        iterator end() const{
            return iterator(guard);
        }

        T back(){
            return guard->prev->value;
        }

        T front(){
            return guard->next->value;
        }

        void push_front(T x){
            Node<T>* temp = new Node<T>;
            temp->value = x;
            
            temp->next = guard->next;
            temp->prev = guard;
            guard->next->prev = temp;
            guard->next = temp;
            Actual_size++;
        }

        T pop_front(){
            if (Actual_size == 0){
                throw std::out_of_range("Empty");
            }
            T x = guard->next->value;
            Node<T>* temp = guard->next;
            guard->next = temp->next;
            temp->next->prev = guard;
            
            Actual_size--;
            delete temp;
            
            return x;
        }

        void push_back(T x){
            Node<T>* temp = new Node<T>;
            temp->value = x;
            
            temp->prev = guard->prev;
            temp->next = guard;
            guard->prev->next = temp;
            guard->prev = temp;
            Actual_size++;
        }

        T pop_back(){
            T x = guard->prev->value;
            Node<T>* temp = guard->prev;
            guard->prev = temp->prev;
            temp->prev->next = guard;
            
            Actual_size--;
            delete temp;
            
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

        bool find(T x){
            iterator it = begin();
            while (it != end()){
                if (*it == x){
                    return true;
                }
                it++;
            }
            return false;
        }

        void changeIdentifier(X x){
            Identifier = x;
        }

        X identifier(){
            return Identifier;
        }

        T erase(iterator it){
            
            T x = *it;
            Node<T>* tmp = it.getptr()->next;

            it.getptr()->next->prev = it.getptr()->prev;

            it.getptr()->prev->next = tmp;

            delete it.getptr();

            Actual_size--;

            return x;
        }

        void insert(iterator it, T x) {
            
            Node<T>* add = new Node<T>;
            add->value = x;

            Node<T>* tmp = it.getptr()->prev;

            add->next = it.getptr();
            add->prev = it.getptr()->prev;
            it.getptr()->prev = add;
            tmp->next = add;
            Actual_size++;

        }

        int remove(T x, int max = -1){
            int count = 0;
            iterator it = begin();
            while (it != end() && max != count){
                if (*it == x){
                    erase(it);
                    count++;
                }
                it++;
            }
            Actual_size -= count;
            return count;
        }

        void removeOne(T x){

            iterator it = begin();
            while (it != end()){
                if (*it == x){
                    erase(it);
                    break;
                }
                it++;
            }
            Actual_size--;
        }        

        ~List(){
            clear();
        }

    private:
        Node<T>* guard;
        int Actual_size;
        X Identifier;

};

#endif
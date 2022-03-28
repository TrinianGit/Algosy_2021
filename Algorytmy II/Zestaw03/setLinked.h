#ifndef SETLINKED_H
#define SETLINKED_H

#include <iostream>

template <class T>
struct Node{
    Node* prev;
    T value;
    Node* next;
};

template <class T>
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

                T operator*(){
                    return ptr->value;
                }

                Node<T>* getptr(){
                    return ptr;
                }

            private:
                Node<T>* ptr;
        };



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
            typename List<T>::iterator it = l.begin();
            while (it != l.end()){
                T obiekt = *it;
                this->push_back(obiekt);
                it++;
            }
        }

        List (List&& l){
            this->guard = l->guard;
            Actual_size = l.Actual_size;
            while (!l.empty()){
                T obiekt = l.pop_front();
                this->push_front(obiekt);
            }
            l->guard = new Node<T>;
        }

        List<T>& operator=(List<T> l){
            this->guard = new Node<T>;
            this->guard->prev = guard;
            this->guard->next = guard;
            Actual_size = 0;
            typename List<T>::iterator it = l.begin();
            while (it != l.end()){
                T obiekt = *it;
                this->push_back(obiekt);
                it++;
            }
            return *this;
        }

        List<T>& operator=(List<T>& l){
            this->guard = new Node<T>;
            this->guard->prev = guard;
            this->guard->next = guard;
            Actual_size = 0;
            typename List<T>::iterator it = l.begin();
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

};


template <class T>
class setLinked{
    
    public:

        setLinked(List<T> defaultSet = List<T>()){
            setdata = List<T>();
            while (!defaultSet.empty()){
                addElement(defaultSet.pop_back());
            }
        }

        void addElement(T x){
            for (typename List<T>::iterator it = setdata.begin(); it != setdata.end(); it++){
                if (x < (*it)){
                    setdata.insert(it, x);
                    return;
                }
            }
            setdata.push_back(x);
        }

        void removeElement(T x){

            for (typename List<T>::iterator it = setdata.begin(); it != setdata.end(); it++){
                if (x == (*it)){
                    setdata.erase(it);
                    return;
                }
            }
        }

        T returnFirst(){
            typename List<T>::iterator it = setdata.begin();
            T toReturn = *it;
            setdata.erase(it);
            return toReturn;
        }

        bool checkExistance(T x){

            for (typename List<T>::iterator it = setdata.begin(); it != setdata.end(); it++){
                if (x == (*it)){
                    return true;
                }
                else if (x < (*it)){
                    return false;
                }
            }
            return false;
        }

        setLinked& setUnion(setLinked& s){
            List<T>* tmp = new List<T>();
            typename List<T>::iterator it = setdata.begin();
            typename List<T>::iterator it2 = s.setdata.begin();
            int counter = 0;
            if (setdata.back() > s.setdata.back()){
                for (; it != setdata.end(); it++){
                    for (; it2 != s.setdata.end(); it2++){
                        counter++;
                        if ((*it2) < (*it)){
                            int c = (*it2);
                            tmp->push_back(c);
                        }
                        else if ((*it2) == (*it)){
                            break;
                        }
                        else if ((*it2) > (*it)){
                            break;
                        }
                    }
                    int c = *it;
                    tmp->push_back(c);
                }
            }
            else{
                for (; it2 != s.setdata.end(); it2++){
                    for (; it != setdata.end(); it++){
                        counter++;
                        if ((*it) < (*it2)){
                            int c = (*it);
                            tmp->push_back(c);
                        }
                        else if ((*it) == (*it2)){
                            break;
                        }
                        else if ((*it) > (*it2)){
                            break;
                        }
                    }
                    int c = *it2;
                    tmp->push_back(c);
                }
            }
            setLinked* toReturn = new setLinked(*tmp);
            delete tmp;
            return (*toReturn);
        }

        setLinked& setIntersection(setLinked& s){
            List<T>* tmp = new List<T>();

            typename List<T>::iterator it = setdata.begin();
            typename List<T>::iterator it2 = s.setdata.begin();

            if (setdata.back() > s.setdata.back()){
                for (; it != setdata.end(); it++){
                    for (; it2 != s.setdata.end(); it2++){
                        if ((*it2) == (*it)){
                            int c = (*it2);
                            tmp->push_back(c);
                            break;
                        }
                        else if ((*it2) > (*it)){
                            break;
                        }
                    }
                }
            }
            else{
                for (; it2 != s.setdata.end(); it2++){
                    for (; it != setdata.end(); it++){
                        if ((*it) == (*it2)){
                            int c = (*it2);
                            tmp->push_back(c);
                            break;
                        }
                        else if ((*it) > (*it2)){
                            break;
                        }
                    }
                }
            }
            setLinked* toReturn = new setLinked(*tmp);
            delete tmp;
            return (*toReturn);
        }
        setLinked& setDifference(setLinked& s){
            List<T>* tmp2 = new List<T>();

            typename List<T>::iterator it = setdata.begin();
            typename List<T>::iterator it2 = s.setdata.begin();
            for (; it != setdata.end(); it++){
                tmp2->push_back(*it);
            }
            for(; it2 != s.setdata.end(); it2++){
                tmp2->push_back(*it2);
            }

            it = setdata.begin();
            it2 = s.setdata.begin();

            for (; it != setdata.end(); it++){
                for (; it2 != s.setdata.end(); it2++){
                    if ((*it2) == (*it)){
                        tmp2->remove(*it, 2);
                        break;
                    }
                    else if ((*it2) > (*it)){
                        break;
                    }
                }
            }
            setLinked* toReturn = new setLinked(*tmp2);
            return (*toReturn);
        }

        bool checkIdentity(setLinked& s){
            typename List<T>::iterator it2 = s.setdata.begin();
            if (setdata.size() != s.setdata.size()){
                return false;
            }
            for (typename List<T>::iterator it = setdata.begin(); it != setdata.end(); it++, it2++){
                if ((*it) != (*it2)){
                    return false;
                }
            }
            return true;
        }

        friend std::ostream& operator<<(std::ostream& os, setLinked<T>& sl){
            for (typename List<T>::iterator i = sl.setdata.begin(); i != sl.setdata.end(); i++){
                os << "[Element:" << *i << "]" << " exists" << std::endl;
            }
            return os;
        }

        ~setLinked(){

        }

    private:
        List<T> setdata;
};

#endif
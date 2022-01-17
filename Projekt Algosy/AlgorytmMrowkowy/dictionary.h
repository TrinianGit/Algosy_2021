#ifndef DICTIONARY_H
#define DICTIONARY_H


#include <utility>
#include <string>
#include "linkedlist.h"

template <class K, class V>

class Dictionary{
    using Pair = std::pair<K,V>;
    public:
        Pair DFL;
        K defK = DFL.first;
        V defV = DFL.second;

        Dictionary(int size = 100){
            Dict = new List<Pair>[size];
            dictionary_size = size;
            pair_number = 0;
        }

        void clear(){
            delete [] Dict;
            Dict = new List<Pair>[dictionary_size];
        }

        bool insert(const Pair& p){
            int Hash = HashFunc(p.first);
            bool inserted = false;
            Node<Pair>* head = Dict[Hash].returnGuard()->prev;
            for (; head != Dict[Hash].returnGuard(); head = head->next){
                if (head->value == p){
                    head->value = std::make_pair(p.first, p.second);
                    inserted = true;
                }
            }
            if (inserted == false){
                Dict[Hash].push_front(p);
                pair_number++;
                return true;
            }
            return false;
        }

        bool find(const K& k){
            int Hash = HashFunc(k);
            Node<Pair>* head = Dict[Hash].returnGuard()->prev;
            for (; head != Dict[Hash].returnGuard(); head = head->next){
                if (head->value.first == k){
                    return true;
                }
            }
            return false;
        }

        V& operator[](const K& k){
            int Hash = HashFunc(k);
            Node<Pair>* head = Dict[Hash].returnGuard()->prev;
            for (; head != Dict[Hash].returnGuard(); head = head->next){
                if (head->value.first == k){
                    return head->value.second;
                }
            }
            Pair p = std::make_pair(k, defV);
            Dict[Hash].push_back(p);
            pair_number++;
            head = Dict[Hash].returnGuard()->next;
            return head->value.second;
        }

        bool erase(const K& k){
            int Hash = HashFunc(k);
            int a = 0;
            Node<Pair>* head = Dict[Hash].returnGuard()->prev;
            for (; head != Dict[Hash].returnGuard(); head = head->next){
                if (head->value.first == k){
                    Dict[Hash].erase(a);
                    return true;
                }
                a++;
            }
            return false;
        }

        int size(){
            return pair_number;
        }

        bool empty(){
            return (pair_number != 0) ? false : true;
        }

        void buckets(){
            std::pair<int, int> Len = ClassLen();
            std::cout << "#" << " " << pair_number << " " << HowManyClasses() << " " << Len.first << " " << Len.second << std::endl;
        }

        int HashFunc(const std::pair<int, double>& p){
            return p.first % dictionary_size;
        }

        int HashFunc(const std::pair<int,int>& p){
            int a = p.first * 5;
            int b = p.second * 10;
            return (a * b) % dictionary_size;
        }

        int HashFunc(const int& k){
            return k % dictionary_size;
        }

        int HashFunc(const std::string& k){
            std::string s = k;
            int sum = 0;
            for (long unsigned int i = 0; i < s.length(); i++){
                sum += s[i];
            }
            return sum % dictionary_size;
        }

        std::pair<int, int> ClassLen(){
            int min = 1;
            for (int i = 0; i < dictionary_size; i++){
                if (Dict[i].size() > 0){
                    min = Dict[i].size();
                    break;
                }
            }
            int max = Dict[0].size();
            for (int i = 1; i < dictionary_size; i++){
                if (Dict[i].size() > max){
                    max = Dict[i].size();
                }
                if (Dict[i].size() < min && Dict[i].size() != 0){
                    min = Dict[i].size();
                }
            }
            std::pair<int, int> pair = std::make_pair(min, max);
            return pair;
        }

        void show(){
            for (int i = 0; i < dictionary_size; i++){
                std::cout << Dict[i].size() << std::endl;
            }
        }

        int HowManyClasses(){
            int classes = 0;
            for (int i = 0; i < dictionary_size; i++){
                if(Dict[i].size() > 0){
                    classes++;
                }
            }
            return classes;
        }

        ~Dictionary(){
            delete[] Dict;
        }

    private:
        List<Pair>* Dict;
        int dictionary_size;
        int pair_number;
        int class_number;

};

#endif // DICTIONARY_H

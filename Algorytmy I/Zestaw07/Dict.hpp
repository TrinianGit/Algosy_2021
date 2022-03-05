#ifndef _HPP_DICT
#define _HPP_DIST

#include <utility>
#include <string>
#include "LinkedList.hpp"

template <class K, class V>

class Dict{
    using Pair = std::pair<K,V>;
    public:
        Pair DFL;
        K defK = DFL.first;
        V defV = DFL.second;

        Dict(int size = 100){
            Dictionary = new List<Pair>[size];
            dictionary_size = size;
            pair_number = 0;
        }

        void clear(){
            delete [] Dictionary;
            Dictionary = new List<Pair>[dictionary_size];
        }

        bool insert(const Pair& p){
            int Hash = HashFunc(p.first);
            bool inserted = false;
            Node<Pair>* head = Dictionary[Hash].returnGuard()->prev;
            for (; head != Dictionary[Hash].returnGuard(); head = head->next){
                if (head->value == p){
                    head->value = std::make_pair(p.first, p.second);
                    inserted = true;
                }
            }
            if (inserted == false){
                Dictionary[Hash].push_front(p);
                pair_number++;
                return true;
            }
            return false;
        }

        bool find(const K& k){
            int Hash = HashFunc(k);
            Node<Pair>* head = Dictionary[Hash].returnGuard()->prev;
            for (; head != Dictionary[Hash].returnGuard(); head = head->next){
                if (head->value.first == k){
                    return true;
                }
            }
            return false;
        }

        V& operator[](const K& k){
            int Hash = HashFunc(k);
            Node<Pair>* head = Dictionary[Hash].returnGuard()->prev;
            for (; head != Dictionary[Hash].returnGuard(); head = head->next){
                if (head->value.first == k){
                    return head->value.second;
                }
            }
            Pair p = std::make_pair(k, defV);
            Dictionary[Hash].push_back(p);
            pair_number++;
            head = Dictionary[Hash].returnGuard()->next;
            return head->value.second;
        }

        bool erase(const K& k){
            int Hash = HashFunc(k);
            int a = 0;
            Node<Pair>* head = Dictionary[Hash].returnGuard()->prev;
            for (; head != Dictionary[Hash].returnGuard(); head = head->next){
                if (head->value.first == k){
                    Dictionary[Hash].erase(a);
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
                if (Dictionary[i].size() > 0){
                    min = Dictionary[i].size();
                    break;
                }
            }
            int max = Dictionary[0].size();
            for (int i = 1; i < dictionary_size; i++){
                if (Dictionary[i].size() > max){
                    max = Dictionary[i].size();
                }
                if (Dictionary[i].size() < min && Dictionary[i].size() != 0){
                    min = Dictionary[i].size();
                }
            }
            std::pair<int, int> pair = std::make_pair(min, max);
            return pair;
        }

        void show(){
            for (int i = 0; i < dictionary_size; i++){
                std::cout << Dictionary[i].size() << std::endl;
            }
        }

        int HowManyClasses(){
            int classes = 0;
            for (int i = 0; i < dictionary_size; i++){
                if(Dictionary[i].size() > 0){
                    classes++;
                }
            }
            return classes;
        }

        ~Dict(){
            delete[] Dictionary;
        }

    private:
        List<Pair>* Dictionary;
        int dictionary_size;
        int pair_number;
        int class_number;
        
};

#endif
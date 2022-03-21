#ifndef SETS_HPP
#define SETS_HPP

#include <vector>
#include <list>
#include <iostream>
#include <cmath>
#include "LinkedList.hpp"


template <class T>
class setSimple{
    public:

        setSimple(int multiply = 1, int sp = 0, int ep = 0){
            setSize = 1;
            this->multiply = multiply;
            if(sp == ep && typeid(T) == typeid(char)){
                startpoint = 97;
                endpoint = 123;
                setSize = abs(endpoint - startpoint);
            }
            else if(sp == ep && typeid(T) == typeid(std::string)){
                startpoint = 97;
                endpoint = 123;
                for (int i = 0; i < multiply; i++){
                    setSize *= 26;
                }
            }
            else{
                startpoint = sp;
                endpoint = ep;
                setSize = abs(ep - sp) + 1;
            }
            setdata = new bool[setSize];
        }

        setSimple(std::vector<int> defaultSet, int multiply, int elementcount, int startpoint, int endpoint){
            setSize = elementcount;
            setdata = new bool[elementcount];
            this->multiply = multiply;

            for (auto& a : defaultSet){
                setdata[a] = true;
            }
        }


        int find_index(int x){
            return (x - startpoint) / multiply;
        }

        int find_index(char x){
            return x - startpoint;
        }

        int find_index(std::string x){
            long unsigned int index = 0;
            int i = 0;
            for (int a = multiply - 1; a >= 0; a--){
                index += (x[i] - 97) * std::pow(26, a);
                i++;
            }
            return index;
        }

        std::string printer(int toPrint){
            std::string toReturn = "";

            if (typeid(T) == typeid(int)){
                toReturn += std::to_string((toPrint * multiply) + startpoint);
                return toReturn;
            }

            else if (typeid(T) == typeid(char)){
                toReturn = toPrint + startpoint;
                return toReturn;
            }

            else{
                int* tab = new int[multiply];
                for (int i = 0; i < multiply; i++){
                    tab[i] = 0;
                }
                int i = 0;
                int toTab = 0;
                int a = multiply - 1;
                while (true){
                    if (a > 0 && toPrint >= std::pow(26, a)){
                        toTab++;
                        toPrint -= std::pow(26, a);
                    }
                    else{
                        tab[i] = toTab;
                        toTab = 0;
                        i++;
                        a--;
                        if (a == 0){
                            tab[i] = toPrint;
                            break;
                        }
                    }
                }
                std::string s = "";
                for (int i = 0; i < multiply; i++){
                    s += tab[i] + 97;
                }
                delete [] tab;
                return s;
            }
        }

        void addElement(T x){
            int index = find_index(x);
            setdata[index] = true;
        }

        void removeElement(T x){
            int index = find_index(x);
            setdata[index] = false;
        }

        bool checkExistance(std::string x){
            int index = find_index(x);
            return setdata[index];
        }

        bool checkExistance(char x){
            int index = find_index(x);
            return setdata[index];
        }

        bool checkExistance(int x){
            return setdata[x];
        }

        setSimple& setUnion(setSimple& s){
            std::vector<int> tmp;
            for (int i = 0; i < setSize; i++){
                if (s.setdata[i] || setdata[i]){
                    tmp.push_back(i);
                }
            }
            setSimple* toReturn = new setSimple(tmp, multiply, setSize, startpoint, endpoint);
            return (*toReturn);
        }

        setSimple<T>& setIntersection(setSimple<T>& s){
            std::vector<int> tmp;
            for (int i = 0; i < setSize; i++){
                if (s.setdata[i] && setdata[i]){
                    tmp.push_back(i);
                }
            }
            setSimple* toReturn = new setSimple(tmp, multiply, setSize, startpoint, endpoint);
            return (*toReturn);
        }

        setSimple<T>& setDifference(setSimple<T>& s){
            std::vector<int> tmp;
            for (int i = 0; i < setSize; i++){
                if (s.setdata[i] && setdata[i]){

                }
                else if ((!s.checkExistance(i) && setdata[i]) || (s.checkExistance(i) && !setdata[i])){
                    tmp.push_back(i);
                }
            }

            setSimple<T>* toReturn = new setSimple<T>(tmp, multiply, setSize, startpoint, endpoint);
            return (*toReturn);

        }

        bool checkIdentity(setSimple<T>& s){
            for (int i = 0; i < setSize; i++){
                if (s.checkExistance(i) != setdata[i]){
                    return false;
                }
            }
            return true;
        }

        friend std::ostream& operator<<(std::ostream& os, setSimple<T>& s){
            for (int i = 0; i < s.setSize; i++){
                if (s.setdata[i]){
                    os << s.printer(i) << " ";
                }
            }
            os << std::endl;
            return os;
        }

        ~setSimple(){
            delete [] setdata;
        }

    private:
        bool* setdata;
        int setSize;
        int multiply;
        int startpoint;
        int endpoint;
};


class setHashed{
    
    public:
        
        setHashed (std::vector<std::string> defaultSet = std::vector<std::string>(), int n = 100){
            setsize = n;
            setdata = new List<std::string> [setsize];
            for (auto& i : defaultSet){
                addElement(i);
            }
        }

        int HashFunc(std::string s){
            unsigned long int hash = 0;
            int multnum = 7;
            for (unsigned long int i = 0; i < s.length(); i++){
                hash += s[i] * std::pow(multnum, i);
            }
            return hash % setsize;
        }

        void addElement(std::string x){
            int index = HashFunc(x);
            if (!setdata[index].find(x)){
                setdata[index].push_back(x);
            }
        }

        void removeElement(std::string x){
            int index = HashFunc(x);
            List<std::string>::iterator it = setdata[index].begin();
            for (it = setdata[index].begin(); it != setdata[index].end(); it++){
                if (*it == x){
                    setdata[index].erase(it);
                    break;
                }
            }
        }

        bool checkExistance(std::string x){
            int index = HashFunc(x);
            return setdata[index].find(x);
        }

        setHashed& setUnion(setHashed& s){
            setHashed* newSet = new setHashed(std::vector<std::string>(), setsize);
            for (int i = 0; i < setsize; i++){
                for (List<std::string>::iterator it = setdata[i].begin(); it != setdata[i].end(); it++){
                    newSet->addElement(*it);
                }
                for (List<std::string>::iterator it = s.setdata[i].begin(); it != s.setdata[i].end(); it++){
                    if (!newSet->checkExistance(*it)){
                        newSet->addElement(*it);
                    }
                }
            }
            return (*newSet);
        }

        setHashed& setIntersection(setHashed& s){
            setHashed* newSet = new setHashed(std::vector<std::string>(), setsize);
            for (int i = 0; i < setsize; i++){
                for (List<std::string>::iterator it = s.setdata[i].begin(); it != s.setdata[i].end(); it++){
                    if (checkExistance(*it)){
                        newSet->addElement(*it);
                    }
                }
            }
            return (*newSet);
        }

        setHashed& setDifference(setHashed& s){
            setHashed* newSet = new setHashed(std::vector<std::string>(), setsize);
            for (int i = 0; i < setsize; i++){
                for (List<std::string>::iterator it = setdata[i].begin(); it != setdata[i].end(); it++){
                    newSet->addElement(*it);
                }
                for (List<std::string>::iterator it = s.setdata[i].begin(); it != s.setdata[i].end(); it++){
                    if (!newSet->checkExistance(*it)){
                        newSet->addElement(*it);
                    }
                    else{
                        newSet->removeElement(*it);
                    }
                }
            }
            return (*newSet);
        }

        bool checkIdentity(setHashed& s){
            for (int i = 0; i < setsize; i++){
                if (setdata[i].size() != s.setdata[i].size()){
                    return false;
                }
                else{
                    for (List<std::string>::iterator it = setdata[i].begin(); it != setdata[i].end(); it++){
                        if (!s.checkExistance(*it)){
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        friend std::ostream& operator<<(std::ostream& os, setHashed const& sl){
            for (int i = 0; i < sl.setsize; i++){
                for (List<std::string>::iterator it = sl.setdata[i].begin(); it != sl.setdata[i].end(); it++){
                    os << *it << " ";
                }
            }
            os << std::endl;
            return os;
        }

        ~setHashed(){
            delete [] setdata;
        }

    private:

        List<std::string>* setdata;
        int setsize;
};

    


#endif
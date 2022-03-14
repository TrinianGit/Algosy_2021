#ifndef SETS_HPP
#define SETS_HPP

#include <vector>
#include <list>
#include <iostream>
#include "LinkedList.hpp"

class Set{
    public:

        Set(){

        };
        virtual void addElement(int x){};
        virtual void removeElement(int x){};
        virtual bool checkExistance(int x){return false;};

        virtual void addElement(std::string x){};
        virtual void removeElement(std::string x){};
        virtual bool checkExistance(std::string x){return false;};


        virtual ~Set(){

        };

};

class setSimple : Set{
    public:

        setSimple(std::vector<int> defaultSet = std::vector<int>(), int n = 100){
            setdata = new bool[n];
            setSize = n;
            for (auto& a : defaultSet){
                setdata[a] = true;
            }
        }

        void addElement(int x) final{
            setdata[x] = true;
        }

        void removeElement(int x) final{
            setdata[x] = false;
        }

        bool checkExistance(int x) final{
            return setdata[x];
        }

        setSimple& setUnion(setSimple& s){
            std::vector<int> tmp;
            int counter = 0;
            for (int i = 0; i < setSize; i++){
                counter++;
                if (s.checkExistance(i) || setdata[i]){
                    tmp.push_back(i);
                }
            }
            setSimple* toReturn = new setSimple(tmp, setSize);
            return (*toReturn);
        }

        setSimple& setIntersection(setSimple& s){
            std::vector<int> tmp;
            for (int i = 0; i < setSize; i++){
                if (s.checkExistance(i) && setdata[i]){
                    tmp.push_back(i);
                }
            }
            setSimple* toReturn = new setSimple(tmp, setSize);
            return (*toReturn);
        }
        setSimple& setDifference(setSimple& s){
            std::vector<int> tmp;
            for (int i = 0; i < setSize; i++){
                if (s.checkExistance(i) && setdata[i]){

                }
                else if ((!s.checkExistance(i) && setdata[i]) || (s.checkExistance(i) && !setdata[i])){
                    tmp.push_back(i);
                }
            }
            setSimple* toReturn = new setSimple(tmp, setSize);
            return (*toReturn);
        }

        bool checkIdentity(setSimple& s){
            for (int i = 0; i < setSize; i++){
                if (s.checkExistance(i) != setdata[i]){
                    return false;
                }
            }
            return true;
        }

        friend std::ostream& operator<<(std::ostream& os, setSimple const& s);

        ~setSimple(){
            delete [] setdata;
        }

    private:
        bool* setdata;
        int setSize;
};

    std::ostream& operator<<(std::ostream& os, setSimple const& s){
        for (int i = 0; i < s.setSize; i++){
            os << "[Element:" << i << "]" << (s.setdata[i] ? " exists" : " doesn't exist") << std::endl;
        }
        return os;
    }


class setLinked : Set{
    
    public:

        setLinked(List<int> defaultSet = List<int>()){
            setdata = List<int>();
            while (!defaultSet.empty()){
                addElement(defaultSet.pop_back());
            }
        }

        void addElement(int x) final{
            for (List<int>::iterator it = setdata.begin(); it != setdata.end(); it++){
                if (x < (*it)){
                    setdata.insert(it, x);
                    return;
                }
            }
            setdata.push_back(x);
        }

        void removeElement(int x) final{

            for (List<int>::iterator it = setdata.begin(); it != setdata.end(); it++){
                if (x == (*it)){
                    setdata.erase(it);
                    return;
                }
            }
        }

        bool checkExistance(int x) final{

            for (List<int>::iterator it = setdata.begin(); it != setdata.end(); it++){
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
            List<int>* tmp = new List<int>();
            List<int>::iterator it = setdata.begin();
            List<int>::iterator it2 = s.setdata.begin();
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
            List<int>* tmp = new List<int>();

            List<int>::iterator it = setdata.begin();
            List<int>::iterator it2 = s.setdata.begin();

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
            List<int>* tmp2 = new List<int>();

            List<int>::iterator it = setdata.begin();
            List<int>::iterator it2 = s.setdata.begin();
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
            List<int>::iterator it2 = s.setdata.begin();
            if (setdata.size() != s.setdata.size()){
                return false;
            }
            for (List<int>::iterator it = setdata.begin(); it != setdata.end(); it++, it2++){
                if ((*it) != (*it2)){
                    return false;
                }
            }
            return true;
        }

        friend std::ostream& operator<<(std::ostream& os, setLinked& sl);

        ~setLinked(){

        }

    private:
        List<int> setdata;
};

    std::ostream& operator<<(std::ostream& os, setLinked& sl){
        for (List<int>::iterator i = sl.setdata.begin(); i != sl.setdata.end(); i++){
            os << "[Element:" << *i << "]" << " exists" << std::endl;
        }
        return os;
    }

class dictionarySimple : Set{
    
    public:
        
        dictionarySimple (std::vector<std::string> defaultSet = std::vector<std::string>(), int n = 100){
            setsize = n;
            setdata = new std::string[n];
            for (auto& i : defaultSet){
                addElement(i);
            }
        }

        int HashFunc(std::string s){
            return std::hash<std::string>{}(s) % setsize;
        }

        void addElement(std::string x) final{
            int index = HashFunc(x);
            while (setdata[index] != ""){
                if (setdata[index] == x){
                    return;
                }
                index++;
                if (index == setsize){
                    index = 0;
                }
            }
            setdata[index] = x;
        }

        void removeElement(std::string x) final{
            int index = HashFunc(x);
            int counter = 1;
            while (setdata[index] != x){
                index++;
                counter++;
                if (index == setsize){
                    index = 0;
                }
            }
            setdata[index] = "";
        }

        bool checkExistance(std::string x) final{
            int index = HashFunc(x);
            int defindex;
            if (index != 0){
                defindex = index - 1;
            }
            else{
                defindex = setsize - 1;
            }
            while (setdata[index] != x && index != defindex){
                index++;
                if (index == setsize){
                    index = 0;
                }
            }
            if (setdata[index] == x){
                return true;
            }
            return false;
        }

        friend std::ostream& operator<<(std::ostream& os, dictionarySimple const& s);

        ~dictionarySimple(){
            delete [] setdata;
        }

    private:

        std::string* setdata;
        int setsize;
};

    std::ostream& operator<<(std::ostream& os, dictionarySimple const& sl){
        for (int i = 0; i < sl.setsize; i++){
            os << sl.setdata[i] << ((sl.setdata[i] != "") ? " " : "");
        }
        os << std::endl;
        return os;
    }


#endif
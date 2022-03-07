#ifndef SETS_H
#define SETS_H

#include <vector>
#include <list>
#include <iostream>

class Set{
    public:

        Set(){

        };
        virtual void addElement(int x){};
        virtual void removeElement(int x){};
        virtual bool checkExistance(int x){return false;};

        virtual void addElement(std::string x){};
        virtual int removeElement(std::string x){return 0;};
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

        //setSimple& setUnion(setSimple& s){
        int setUnion(setSimple& s){
            std::vector<int> tmp;
            int counter = 0;
            for (int i = 0; i < setSize; i++){
                counter++;
                if (s.checkExistance(i) || setdata[i]){
                    tmp.push_back(i);
                }
            }
            setSimple* toReturn = new setSimple(tmp, setSize);
            //return (*toReturn);
            return counter;
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
                if (!s.checkExistance(i) && setdata[i]){
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

        setLinked(std::list<int> defaultSet = std::list<int>()){
            setdata = std::list<int>(defaultSet);
        }

        void addElement(int x) final{
            std::list<int>::iterator it;
            for (it = setdata.begin(); it != setdata.end(); it++){
                if (x < (*it)){
                    setdata.insert(it, x);
                    break;
                }
            }
            if (it == setdata.end()){
                setdata.push_back(x);
            }
        }

        void removeElement(int x) final{
            std::list<int>::iterator it;
            for (it = setdata.begin(); it != setdata.end(); it++){
                if (x == (*it)){
                    setdata.erase(it);
                    break;
                }
            }
        }

        bool checkExistance(int x) final{
            std::list<int>::iterator it;
            for (it = setdata.begin(); it != setdata.end(); it++){
                if (x == (*it)){
                    return true;
                }
                else if (x < (*it)){
                    return false;
                }
            }
            return (*it) == x;
        }

        //setLinked& setUnion(setLinked& s){
        int setUnion(setLinked& s){
            std::list<int> tmp;
            std::list<int>::iterator it = setdata.begin();
            std::list<int>::iterator it2 = s.setdata.begin();
            int counter = 0;
            if (setdata.back() > s.setdata.back()){
                for (it; it != setdata.end(); it++){
                    for (it2; it2 != s.setdata.end(); it2++){
                        counter++;
                        if ((*it2) < (*it)){
                            int c = (*it2);
                            tmp.push_back(c);
                        }
                        else if ((*it2) == (*it)){
                            break;
                        }
                        else if ((*it2) > (*it)){
                            break;
                        }
                    }
                    int c = *it;
                    tmp.push_back(c);
                }
            }
            else{
                for (it2; it2 != s.setdata.end(); it2++){
                    for (it; it != setdata.end(); it++){
                        counter++;
                        if ((*it) < (*it2)){
                            int c = (*it);
                            tmp.push_back(c);
                        }
                        else if ((*it) == (*it2)){
                            break;
                        }
                        else if ((*it) > (*it2)){
                            break;
                        }
                    }
                    int c = *it2;
                    tmp.push_back(c);
                }
            }
            setLinked* toReturn = new setLinked(tmp);
            //return (*toReturn);
            return counter;
        }

        setLinked& setIntersection(setLinked& s){
            std::list<int> tmp;
            std::list<int>::iterator it = setdata.begin();
            std::list<int>::iterator it2 = s.setdata.begin();
            if (setdata.back() > s.setdata.back()){
                for (it; it != setdata.end(); it++){
                    for (it2; it2 != s.setdata.end(); it2++){
                        if ((*it2) == (*it)){
                            int c = (*it2);
                            tmp.push_back(c);
                            break;
                        }
                        else if ((*it2) > (*it)){
                            break;
                        }
                    }
                }
            }
            else{
                for (it2; it2 != s.setdata.end(); it2++){
                    for (it; it != setdata.end(); it++){
                        if ((*it) == (*it2)){
                            int c = (*it2);
                            tmp.push_back(c);
                            break;
                        }
                        else if ((*it) > (*it2)){
                            break;
                        }
                    }
                }
            }
            setLinked* toReturn = new setLinked(tmp);
            return (*toReturn);
        }
        setLinked& setDifference(setLinked& s){
            std::list<int> tmp;
            std::list<int>::iterator it = setdata.begin();
            std::list<int>::iterator it2 = s.setdata.begin();

            for (it; it != setdata.end(); it++){
                int c = (*it);
                tmp.push_back(c);
                for (it2; it2 != s.setdata.end(); it2++){
                    if ((*it2) == (*it)){
                        tmp.pop_back();
                        break;
                    }
                    else if ((*it2) > (*it)){
                        break;
                    }
                }
            }
        
            setLinked* toReturn = new setLinked(tmp);
            return (*toReturn);
        }

        bool checkIdentity(setLinked& s){
            std::list<int>::iterator it;
            std::list<int>::iterator it2;
            if (setdata.size() != s.setdata.size()){
                return false;
            }
            for (it = setdata.begin(), it2 = s.setdata.begin(); it != setdata.end(); it++, it2++){
                if ((*it) != (*it2)){
                    return false;
                }
            }
            return (*it) == (*it2);
        }

        friend std::ostream& operator<<(std::ostream& os, setLinked const& sl);

        ~setLinked(){
        }

    private:
        std::list<int> setdata;
};

    std::ostream& operator<<(std::ostream& os, setLinked const& sl){
        for (auto& i : sl.setdata){
            os << "[Element:" << i << "]" << " exists" << std::endl;
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
                index++;
                if (index == setsize){
                    index = 0;
                }
            }
            setdata[index] = x;
        }

        int removeElement(std::string x) final{
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
            return counter;
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

        ~dictionarySimple(){
            delete [] setdata;
        }

    private:

        std::string* setdata;
        int setsize;
};


#endif
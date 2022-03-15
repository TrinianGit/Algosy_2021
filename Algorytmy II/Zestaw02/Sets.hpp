#ifndef SETS_HPP
#define SETS_HPP

#include <vector>
#include <list>
#include <iostream>

template <class T>
class Set{
    public:

        Set(){

        };
        virtual void addElement(T x){};
        virtual void removeElement(T x){};
        virtual bool checkExistance(T x){return false;};

        virtual void addElement(std::string x){};
        virtual void removeElement(std::string x){};
        virtual bool checkExistance(std::string x){return false;};


        virtual ~Set(){

        };

};


template <class T>
class setSimple : public Set<T>{
    public:

        setSimple(std::vector<int> defaultSet = std::vector<int>(), int multiply = 1, int sp = 0, int ep = 0){
            setSize = 1;
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
                setSize = abs(endpoint - startpoint);
            }
            setdata = new bool[setSize];
            for (auto& a : defaultSet){
                int index = find_index(a);
                setdata[index] = true;
            }
        }

        int find_index(T x){
            if (typeid(T) == typeid(int)){
                return x / multiply;
            }
            else if (typeid(T) == typeid(char)){
                return x - startpoint;
            }
            else{
                int index = 0;
                for (int i = 0; i < multiply; i++){
                    index += 123 * (i+1);
                }
                for (int i = 0; i < multiply; i++){
                    index -= (x[i] * (multiply - i));
                }
                return index;
            }
        }

        std::string printer(int toPrint){
            std::string toReturn = "";
            if (typeid(T) == typeid(int)){
                toReturn += std::to_string((toPrint * multiply) + startpoint);
                return toReturn;
            }
            else if (typeid(T) == typeid(char)){
                toReturn += toPrint;
                return toReturn;
            }
            else{
                int index = toPrint + 1;
                for (int i = 0; i < multiply; i++){
                    if (i != (multiply - 1){
                        toReturn += (index / 26) + startpoint;
                        if (index / 26 > 0){
                            index /= 26;
                        }
                    }
                    else{
                        toReturn += index + startpoint;
                    }
                }
                return index;
            }
        }

        void addElement(T x) final{
            int index = find_index(x);
            setdata[index] = true;
        }

        void removeElement(T x) final{
            int index = find_index(x);
            setdata[index] = false;
        }

        bool checkExistance(T x) final{
            int index = find_index(x);
            return setdata[index];
        }

        setSimple& setUnion(setSimple& s){
            std::vector<T> tmp;
            int counter = 0;
            for (int i = 0; i < setSize; i++){
                counter++;
                if (s.checkExistance(i) || setdata[i]){
                    tmp.push_back(i);
                }
            }
            setSimple* toReturn = new setSimple(tmp, multiply);
            return (*toReturn);
        }

        setSimple<T>& setIntersection(setSimple<T>& s){
            std::vector<T> tmp;
            for (int i = 0; i < setSize; i++){
                if (s.checkExistance(i) && setdata[i]){
                    tmp.push_back(i);
                }
            }
            setSimple* toReturn = new setSimple(tmp, multiply);
            return (*toReturn);
        }
        setSimple<T>& setDifference(setSimple<T>& s){
            std::vector<T> tmp;
            for (int i = 0; i < setSize; i++){
                if (s.checkExistance(i) && setdata[i]){

                }
                else if ((!s.checkExistance(i) && setdata[i]) || (s.checkExistance(i) && !setdata[i])){
                    tmp.push_back(i);
                }
            }
            if (typeid(T) == typeid(int)){
                setSimple<T>* toReturn = new setSimple<T>(tmp, multiply, startpoint, endpoint);
                return (*toReturn);
            }
            else{
                setSimple<T>* toReturn = new setSimple<T>(tmp, multiply);
                return (*toReturn);
            }
        }

        bool checkIdentity(setSimple<T>& s){
            for (int i = 0; i < setSize; i++){
                if (s.checkExistance(i) != setdata[i]){
                    return false;
                }
            }
            return true;
        }

        friend std::ostream& operator<<(std::ostream& os, setSimple<T> const& s);

        ~setSimple(){
            delete [] setdata;
        }

    private:
        T* setdata;
        int setSize;
        int multiply;
        int startpoint;
        int endpoint;
};

    template <class T>
    std::ostream& operator<<(std::ostream& os, setSimple<T> const& s){
        for (int i = 0; i < s.setSize; i++){
            os << (s.setdata[i] ? s.printer(i) : "") << " ";
        }
        os << std::endl;
        return os;
    }


class dictionarySimple : public Set<std::string>{
    
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
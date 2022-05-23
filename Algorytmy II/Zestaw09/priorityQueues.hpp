#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>

template <class T>
class Heap{
    
    public:
        using Pair = std::pair<T,int>;
        Heap(){
            heapdata = std::vector<Pair>();
            size = 0;
        };

        int parent(int i) {
            return (i - 1) / 2;
        }
        int lChild(int i){
            return (2 * i) + 1;
        }
        int rChild(int i){
            return (2 * i) + 2;
        }

        void addElement(Pair x) {
            T object;
            size++;
            heapdata.push_back(std::make_pair(object, INT64_MAX));
            increaseKey(x, size - 1);
        }

        void increaseKey(Pair x, int i){
            heapdata[i] = x;
            while (i != 0 && heapdata[parent(i)].second > heapdata[i].second){
                swapTwo(i, parent(i));
                i = parent(i);
            }

        }

        void swapTwo(int i, int j){
            Pair tmp = heapdata[i];
            heapdata[i] = heapdata[j];
            heapdata[j] = tmp;
        }

        void repairHeap(int i){
            int left = lChild(i);
            int right = rChild(i);
            int min = i;
            
            if (left < size && heapdata[left].second < heapdata[min].second){
                min = left;
            }
            
            if (right < size && heapdata[right].second < heapdata[min].second){
                min = right;
            }
            
            if (min != i){
                swapTwo(i, min);
                repairHeap(min);
            }
        }

        T returnLowPrio(){
            if (size == 1){
                size--;
                return heapdata[0].first;
            }

            T toReturn = heapdata[0].first;
        
            heapdata[0] = heapdata[size - 1];
            heapdata.pop_back();
            
            size--;
            repairHeap(0);
            return toReturn;
        }

        int LowPrioValue(){
            return heapdata[0].second;
        }

        ~Heap(){

        }


    private:
        std::vector<Pair> heapdata;
        int size;
};


template<typename T>
class priorityQueueBinary {
    using Pair = std::pair<T,int>;
    public:
        
        priorityQueueBinary(){
            heap = new Heap<T>();
            size = 0;
        }

        void addElement(Pair x) {
            heap->addElement(x);
            size++;
        }

        T returnLowPrio(){
            size--;
            return heap->returnLowPrio();
        }

        int LowestPrio(){
            return heap->LowPrioValue();
        }

        bool empty(){
            return size == 0;
        }

        ~priorityQueueBinary(){
            delete heap;
        }
        int size;

    private:
        Heap<T>* heap;
};



#endif
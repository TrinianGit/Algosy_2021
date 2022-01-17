#ifndef PAINTTHREAD_H
#define PAINTTHREAD_H

#include "algorithm.h"
#include "linkedlist.h"

class PaintThread
{
    public:
        PaintThread();
        void setAlgo(Algorithm* Alg);
        void giveList(List<int>* l);
        void run();
    private:
        QThread* th;
        Algorithm* A;
        List<int>* points;
        //QTimeLine *timer;
};

#endif // PAINTTHREAD_H

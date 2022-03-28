#include "priorityQueues.hpp"

using namespace std;

int main(int argc, char* argv[]){
    priorityQueue<string>* pq = new priorityQueue<string>();
    priorityQueueBinary<string>* pqb = new priorityQueueBinary<string>();

    cout << "--------------------------------------------------" << endl;
    cout << "                  priorityQueue                   " << endl;
    cout << "--------------------------------------------------" << endl;
    pq->addElement("Ola");
    pq->addElement("Natalia");
    pq->addElement("Ala");
    pq->addElement("Bartek");
    pq->addElement("Arek");
    pq->addElement("Zenek");
    pq->addElement("Marcin");

    while(!pq->empty()){
        cout << pq->returnLowPrio() << endl;
    }

    cout << "--------------------------------------------------" << endl;
    cout << "               priorityQueueBinary                " << endl;
    cout << "--------------------------------------------------" << endl;

    pqb->addElement(make_pair("Ola", 2));
    pqb->addElement(make_pair("Natalia", 11));
    pqb->addElement(make_pair("Ala", 8));
    pqb->addElement(make_pair("Bartek", 4));
    pqb->addElement(make_pair("Arek", 6));
    pqb->addElement(make_pair("Zenek", 10));
    pqb->addElement(make_pair("Marcin", 5));
    
    while(!pqb->empty()){
        cout << pqb->returnLowPrio() << endl;
    }

    delete pq;
    delete pqb;
}
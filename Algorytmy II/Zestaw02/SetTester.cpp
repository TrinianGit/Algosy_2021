#include <iostream>
#include "Sets.hpp"
#include <ctime>


using namespace std;

int main(int argc, char* argv[]){

    srand(time(NULL));

    setSimple<int>* s1 = new setSimple<int>(1, 0, 5);
    setSimple<int>* s2 = new setSimple<int>(2, -4, 4);
    setSimple<char>* s3 = new setSimple<char>();
    setSimple<string>* s4 = new setSimple<string>(4);
    setSimple<string>* s5 = new setSimple<string>(4);
    setHashed* s6 = new setHashed();
    setHashed* s7 = new setHashed();

    for (int i = 0; i < 6; i++){
        s1->addElement(i);
    }
    for(int i = -4; i < 6; i += 2){
        s2->addElement(i);
    }
    for(int i = 0; i < 10; i++){
        s3->addElement(rand()%26+97);
    }
    s4->addElement("aaaa");
    s4->addElement("baaa");
    s4->addElement("cgaa");
    s4->addElement("ffaa");
    s4->addElement("glaa");
    s4->addElement("opaa");
    s5->addElement("cgaa");
    s5->addElement("aaaa");
    s5->addElement("naaa");
    s5->addElement("ruaa");

    s6->addElement("aaaa");
    s6->addElement("baaa");
    s6->addElement("cgaa");
    s6->addElement("ffaa");
    s6->addElement("glaa");
    s6->addElement("opaa");
    s7->addElement("cgaa");
    s7->addElement("aaaa");
    s7->addElement("naaa");
    s7->addElement("ruaa");

    cout << "----------------------------------------------------" << endl;
    cout << " Zbior przechowujacy liczby rzeczywiste n, n+1, n+2 " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Set 1 data: " << endl;
    cout << (*s1);
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << " Zbior przechowujacy liczby rzeczywiste n, n+2, n+4 " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Set 2 data: " << endl;
    cout << (*s2);
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << " Zbior przechowujacy znaki od a do z (bez polskich) " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Set 3 data: " << endl;
    cout << (*s3);
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Zbior przechowujacy pary liter (bez polskich znakow)" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Set 4 data: " << endl;
    cout << (*s4);
    cout << "Set 5 data: " << endl;
    cout << (*s5);
    cout << "Sets union: " << endl;
    cout << s4->setUnion(*s5);
    cout << "Sets intersection: " << endl;
    cout << s4->setIntersection(*s5);
    cout << "Sets difference: " << endl;
    cout << s4->setDifference(*s5);
    cout << "Sets identity check: " << endl;
    cout << "Set 4 == Set 4?: " << (s4->checkIdentity(*s4) ? "true" : "false") << endl;
    cout << "Set 4 == Set 5?: " << (s4->checkIdentity(*s5) ? "true" : "false");
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "                      setHashed                     " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Set 6 data: " << endl;
    cout << (*s6);
    cout << "Set 7 data: " << endl;
    cout << (*s7);
    cout << "Sets union: " << endl;
    cout << s6->setUnion(*s7);
    cout << "Sets intersection: " << endl;
    cout << s6->setIntersection(*s7);
    cout << "Sets difference: " << endl;
    cout << s6->setDifference(*s7);
    cout << "Sets identity check: " << endl;
    cout << "Set 6 == Set 6?: " << (s6->checkIdentity(*s6) ? "true" : "false") << endl;
    cout << "Set 6 == Set 7?: " << (s6->checkIdentity(*s7) ? "true" : "false");
    cout << endl;
}
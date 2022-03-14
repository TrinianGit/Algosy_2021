#include <iostream>
#include "Sets.hpp"

using namespace std;

int main(int argc, char* argv[]){

    setSimple* s1 = new setSimple(vector<int>(), 10);
    setSimple* s2 = new setSimple(vector<int>(), 10);
    setLinked* s3 = new setLinked();
    setLinked* s4 = new setLinked();
    dictionarySimple* s5 = new dictionarySimple();
    dictionarySimple* s6 = new dictionarySimple(); 

    for (int i = 0; i < 6; i++){
        s1->addElement(i);
        s3->addElement(i);
    }
    for(int i = 3; i < 8; i++){
        s2->addElement(i);
        s4->addElement(i);
    }

    cout << "----------------------------------------" << endl;
    cout << "                SetSimple               " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Set 1 data: " << endl;
    cout << (*s1);
    cout << "Set 2 data: " << endl;
    cout << (*s2);
    cout << "Sets union: " << endl;
    cout << s1->setUnion(*s2);
    cout << "Sets intersection: " << endl;
    cout << s1->setIntersection(*s2);
    cout << "Sets difference: " << endl;
    cout << s1->setDifference(*s2);
    cout << "Sets identity check: " << endl;
    cout << "Set 1 == Set 1?: " << (s1->checkIdentity(*s1) ? "true" : "false") << endl;
    cout << "Set 2 == Set 1?: " << (s2->checkIdentity(*s1) ? "true" : "false");
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "                SetLinked               " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Set 3 data: " << endl;
    cout << (*s3);
    cout << "Set 4 data: " << endl;
    cout << (*s4);
    cout << "Sets union: " << endl;
    cout << s3->setUnion(*s4);
    cout << "Sets intersection: " << endl;
    cout << s3->setIntersection(*s4);
    cout << "Sets difference: " << endl;
    cout << s3->setDifference(*s4);
    cout << "Sets identity check: " << endl;
    cout << "Set 3 == Set 3?: " << (s3->checkIdentity(*s3) ? "true" : "false") << endl;
    cout << "Set 4 == Set 3?: " << (s4->checkIdentity(*s3) ? "true" : "false");
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "             DictionarySimple           " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Set 5 adding elements 'Ala', 'ma', 'Maciek', 'pies': " << endl;
    s5->addElement("Ala");
    cout << (*s5);
    s5->addElement("ma");
    cout << (*s5);
    s5->addElement("Maciek");
    cout << (*s5);
    s5->addElement("pies");
    cout << (*s5);
    cout << "Set 6 adding elements 'Nie', 'tymczasowo', 'niesmiertelny': " << endl;
    s6->addElement("Nie");
    cout << (*s6);
    s6->addElement("tymczasowo");
    cout << (*s6);
    s6->addElement("niesmiertelny");
    cout << (*s6);
    cout << "Removing element 'Ala' from Set 5: " << endl;
    s5->removeElement("Ala");
    cout << (*s5);
    cout << "Removing element 'tymczasowo' from Set 6: " << endl;
    s6->removeElement("tymczasowo");
    cout << (*s6);
    cout << "Checking if words are in sets: " << endl;
    cout << "Does 'Nie' exist in Set 5?: " << (s5->checkExistance("Nie") ? "true" : "false") << endl;
    cout << "Does 'Nie' exist in Set 6?: " << (s6->checkExistance("Nie") ? "true" : "false");
    cout << endl;
}
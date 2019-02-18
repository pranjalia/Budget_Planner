#include <iostream>
#include <vector>
#include <string.h>
#include "node.cpp"

using namespace std;

class Longterm{
    private:
    node* head;

    Public:
    //constructor
    Longterm(){
        head = NULL;
        next = NULL;
    }

    //destructor
    ~Longterm(){
        Node *p;
        while (head != NULL) {
            p = head;
            head = p->get_next();
            delete p;
        }
    }
}
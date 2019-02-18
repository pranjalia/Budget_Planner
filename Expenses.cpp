#include <iostream>
#include <vector>
#include <string.h>
#include "node.cpp"

using namespace std;

class Expenses {
    private:
    node* head;

    Public:
    //constructor
    Expenses(){
        head = NULL;
        next = NULL;
    }

    //destructor
    ~Expenses(){
        Node *p;
        while (head != NULL) {
            p = head;
            head = p->get_next();
            delete p;
        }
    }
};

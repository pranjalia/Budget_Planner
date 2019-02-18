#include <iostream>
#include <vector>
#include <string.h>
#include "node.cpp"

using namespace std;

class Purchase_Goals {
    private:
    node* head;

    Public:
    //constructor
    Purchase_Goals(){
        head = NULL;
        next = NULL;
    }
    
    //destructor
    ~Income(){
        Node *p;
        while (head != NULL) {
            p = head;
            head = p->get_next();
            delete p;
        }
    }
};
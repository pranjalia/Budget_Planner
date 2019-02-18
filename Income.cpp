#include <iostream>
#include <vector>
#include <string.h>
#include "node.cpp"

using namespace std;

class Income {
    private:
    node* head;

    Public:
    //constructor
    Income(){
        head = new node;
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
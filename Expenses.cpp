#include <iostream>
#include <vector>
#include <string.h>
#include "node.cpp"

using namespace std;
#ifndef _Expenses_h
#define _Expenses_h

class Expenses {
    private:
    node* head;

    public:
    //constructor
    Expenses(){
        head = NULL;
    }

    //destructor
    ~Expenses(){
        node *p;
        while (head != NULL) {
            p = head;
            head = p->get_next_node();
            delete p;
        }
    }

    //add a node
    void add_expense(float amount){
        node *p = head;
        while (p != NULL){
            if (p->get_next_node() == NULL){
                p->set_next_node(amount);
            }
            else{
                p = p->get_next_node();
            }
        }
    }
};

#endif

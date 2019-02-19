#include <iostream>
#include <vector>
#include <string>
#include "node.h"

using namespace std;
#ifndef _Expenses_h
#define _Expenses_h

class Expenses {
    private:
    node* head;

    public:
    //constructor
    Expenses(){
        head = new node(0);
    }

    //destructor
    ~Expenses(){
        node *p;
        while (head != NULL) {
            p = head;
            head = p->get_next_node();
            delete p;
        }
        delete head;
        head = NULL;
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

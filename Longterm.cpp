#include <iostream>
#include <vector>
#include <string.h>
#include "node.cpp"

using namespace std;
#ifndef _Longterm_h
#define _Longterm_h

class Longterm{
    private:
    node* head;

    public:
    //constructor
    Longterm(){
        head = new node(0);
    }

    //destructor
    ~Longterm(){
        if (head->get_next_node()==NULL){
            delete head;
        }
        node *p;
        while (head != NULL) {
            p = head;
            head = p->get_next_node();
            delete p;
            p = NULL;
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
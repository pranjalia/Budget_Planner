#include <iostream>
#include <vector>
#include <string>
#include "node.h"

using namespace std;
#ifndef _PurchaseGoals_h
#define _PurchaseGoals_h

class Purchase_Goals {
    private:
    node* head;

    public:
    //constructor
    Purchase_Goals(){
        head = NULL;
    }
    
    //destructor
    ~Purchase_Goals(){
        node *p;
        while (head != NULL) {
            p = head;
            head = p->get_next_node();
            delete p;
        }
    }

    //add a node
    void add_goal(float amount){
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

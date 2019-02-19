#include <iostream>
#include <vector>
#include <string>
#include "node.h"

using namespace std;
#ifndef _Income_h
#define _Income_h

class Income {
    private:
    node* head;

    public:
    //constructor
    Income(){
        head = new node(0);
    }

    //destructor
    ~Income(){
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
    void add_income(float amount){
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

void Income::add_income(float amount)

#endif
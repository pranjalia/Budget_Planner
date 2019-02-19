#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#ifndef _node_h
#define _node_h

class node{
    private:
    float data;
    node* next;

    public:
    //constructor
    node(float d){
        data = d;
        next = NULL;
    }

    float get_data(){
        return data;
    }

    node *get_next_node(){
        return next;
    }

    void set_next_node(float d){
        next = new node(d);
    }

};

#endif

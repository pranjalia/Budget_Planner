#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

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
};

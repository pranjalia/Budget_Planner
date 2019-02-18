#include <iostream>
#include <vector>
#include <string.h>
#include "node.cpp"
#include "Budget.cpp"

using namespace std;

class Account {
    private:
    string name;
    string email;
    string phone_number;
    Budget* budget;

    public:
    //constructor
    Account(){
        budget = new Budget(0);
    }
    Account(string account_name){
        budget = new Budget(0);
        name = account_name;
    }
    //destructor
    ~Account(){
        delete budget;
        budget = NULL;
    }
    //mutators
    void change_first_name(string fname);
    void change_last_name(string lname);
    void change_email(string newemail);
    void change_phone_number(string newphone);
    //setting 
    void set_first_name(string fname);
    void set_last_name(string lname);
    void set_email(string newemail);
    void set_phone_number(string newphone);
};


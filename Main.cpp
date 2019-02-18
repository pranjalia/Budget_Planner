#include <iostream>
#include <vector>
#include <string.h>
#include "Budget.cpp"
#include "Account.cpp"

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

class Budget {
    private:
    float budget;
    float bank_balance;
    Income* income;
    Expenses* expenses;
    Longterm * longterm_expenses;
    Purchase_Goals* purchase_goals;

    public:
    //constructor
    Budget (float bankBalance){
        budget = 0;
        bank_balance = bankBalance;
        income = NULL;
        expenses = NULL;
        longterm_expenses = NULL;
        purchase_goals = NULL;
    }
    //Destructor
    ~Budget (){
        delete income;
        delete expenses;
        delete longterm_expenses;
        delete purchase_goals;

        income = NULL;
        expenses = NULL;
        longterm_expenses = NULL;
        purchase_goals = NULL;

    }
    //set bank balnce
    void set_bank_balance(float amount);
    //Add expenses
    void add_monthly_expense(float amount);
    //Add income
    void add_monthly_income(float amount);
    //Add longterm bills
    void add_longterm_expense(float amount, int months);
    //Add purchasing goal
    void add_purchasing_goal(float amount, string item);
};

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

class Expenses {
    private:
    node* head;

    Public:
    //constructor
    Expenses(){
        head = NULL;
        next = NULL;
    }

    //destructor
    ~Expenses(){
        Node *p;
        while (head != NULL) {
            p = head;
            head = p->get_next();
            delete p;
        }
    }
};

class Longterm{
    private:
    node* head;

    Public:
    //constructor
    Longterm(){
        head = NULL;
        next = NULL;
    }

    //destructor
    ~Longterm(){
        Node *p;
        while (head != NULL) {
            p = head;
            head = p->get_next();
            delete p;
        }
    }
}

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

///DECLARATION OF FUNCTIONS IN MAIN///

void bank_balance(Account& user);
void monthly_income(Account& user);
void long_term_bills(Account& user);
void purchasing_goals(Account& user);

int main(int argc, char** argv) {
    Account user;
    string name;
    float amount;
    string response;
    
    cout<<"welcome to Pranjali'a Budget Planner. Here, you will be able to fill in your expenses, income
    , and purchasing goals. You will recieve a budget for this month." <<endl<< "Please start by entering 
    your name:" endl;

    cin << name;
    user.set_first_name(name);

    cout<<"What is your current Bank Balance?"<<endl<<"$";
    cin<<amount;
    user->budget->set_bank_balance(amount);

    monthly_income(user);
    monthly_bills(user);
    long_term_bills(user);
    purchasing_goals(user);

    //now we will write the results
    //modify dollars and shit withcolours and bold
}

void bank_balance(Account& user){
    float amount;

    cout<<"Do you have a monthly income? ('y' for yes, 'n' for no)"<<endl;
    cin<<response;
    while (response != 'y' && response != 'Y', && response != 'n' && response!= 'N'){
        cout << "Invalid command! Please respond with 'y' or 'n'"<<endl;
    }

    while(response == 'y' || response=='Y'){
        response = 'n';
        cout<<"Income Amount:"<<endl<<"$";
        cin<<amount;
        user->budget->add_monthly_income(amount);

        cout<<"Do you have anymore income? ('y' for yes, 'n' for no)"<<endl;
        cin<<response;
    }    
}

void monthly_bills(Account& user){
    float amount;

    cout<<"Do you have any monthly expenses? ('y' for yes, 'n' for no)"<<endl;
    cin<<response;
    while (response != 'y' && response != 'Y', && response != 'n' && response!= 'N'){
        cout << "Invalid command! Please respond with 'y' or 'n'"<<endl;
    }

    while(response == 'y' || response=='Y'){
        response = 'n';
        cout<<"Expense Amount:"<<endl<<"$";
        cin<<amount;
        user->budget->add_longterm_expense(amount);

        cout<<"Do you have anymore expenses? ('y' for yes, 'n' for no)"<<endl;
        cin<<response;
    }    
}

void long_term_bills(Account& user){
    float amount;
    int months;

    cout<<"Do you have any long-term expenses (ex. school tuition)? ('y' for yes, 'n' for no)"<<endl;
    cin<<response;
    while (response != 'y' && response != 'Y', && response != 'n' && response!= 'N'){
        cout << "Invalid command! Please respond with 'y' or 'n'"<<endl;
    }

    while(response == 'y' || response=='Y'){
        response = 'n';
        cout<<"Expense Amount:"<<endl<<"$";
        cin<<amount;
        cout<<"How many months do you need to pay this by?"<<endl;
        cin<<months;

         user->budget->add_longterm_expense(amount, months);

        cout<<"Do you have anymore expenses? ('y' for yes, 'n' for no)"<<endl;
        cin<<response; 
    }      
}

void purchasing_goals(Account& user){
    float amount;
    string item;

    cout<<"Do you have any purchasing goals (ex. new air maxes)? ('y' for yes, 'n' for no)"<<endl;
    cin<<response;
    while (response != 'y' && response != 'Y', && response != 'n' && response!= 'N'){
        cout << "Invalid command! Please respond with 'y' or 'n'"<<endl;
    }

    while(response == 'y' || response=='Y'){
        response = 'n';
        cout<<"Item:"<<endl;
        cin<<item;
        cout<<"Cost:"<<endl<<"$";
        cin<<amount;

         user->budget->add_purchasing_goal(amount, item);

        cout<<"Do you have anymore purchasing goals? ('y' for yes, 'n' for no)"<<endl;
        cin<<response; 
    }      
}
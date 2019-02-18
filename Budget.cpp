#include <iostream>
#include <vector>
#include <string.h>
#include "node.cpp"
#include "Income.cpp"
#include "Expenses.cpp"
#include "Longterm.cpp"
#include "Purchase_Goals.cpp"

using namespace std;

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
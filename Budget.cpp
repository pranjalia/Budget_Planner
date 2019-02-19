#include <iostream>
#include <vector>
#include <string.h>
#include "node.cpp"
#include "Income.cpp"
#include "Expenses.cpp"
#include "Longterm.cpp"
#include "Purchase_Goals.cpp"

using namespace std;
#ifndef _Budget_h
#define _Budget_h

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
        income = new Income();
        expenses = new Expenses();
        longterm_expenses = new Longterm();
        purchase_goals = new Purchase_Goals();
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
    void set_bank_balance(float amount){
        bank_balance = amount;
    }
    //Add expenses
    void add_monthly_expense(float amount){
         expenses->add_expense(amount);
    }
    //Add income
    void add_monthly_income(float amount){
        income->add_income(amount);
    }
    //Add longterm bills
    void add_longterm_expense(float amount, int months){
        if (months < 6){
            longterm_expenses->add_expense(amount);
        }
    }
    //Add purchasing goal
    void add_purchasing_goal(float amount, string item){
        purchase_goals->add_goal(amount);
    }
};

#endif
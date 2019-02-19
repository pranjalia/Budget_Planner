#include <iostream>
#include <vector>
#include <string>
#include "Budget.h"
#include "Account.h"

using namespace std;

///DECLARATION OF FUNCTIONS IN MAIN///

void monthly_income(Account& user);
void monthly_bills(Account& user);
void long_term_bills(Account& user);
void purchasing_goals(Account& user);

int main(int argc, char** argv) {
    Account user;
    string name;
    float amount;
    string response;
    
    cout<< "welcome to Pranjali'a Budget Planner. Here, you will be able to fill in your expenses, income";
    cout<< ", and purchasing goals. You will recieve a budget for this month." << endl << "Please start by entering";
    cout<<" your name:" << endl;

    cin >> name;
    user.set_first_name(name);

    cout<<"What is your current Bank Balance?"<<endl<<"$";
    cin >> amount;
    user.get_budget()->set_bank_balance(amount);

    monthly_income(user);
    monthly_bills(user);
    long_term_bills(user);
    purchasing_goals(user);

    user.get_budget()->calculate_budget();
}

void monthly_income(Account& user){
    float amount;
    string response;

    cout<<"Do you have a monthly income? ('y' for yes, 'n' for no)"<<endl;
    cin>>response;
    while (response != "y" && response != "Y" && response != "n" && response!= "N"){
        cout << "Invalid command! Please respond with 'y' or 'n'"<<endl;
        cin >> response;
    }

    while(response == "y" || response=="Y"){
        response = "n";
        cout<<"Income Amount:"<<endl<<"$";
        cin>>amount;
        user.get_budget()->add_monthly_income(amount);

        cout<<"Do you have anymore income? ('y' for yes, 'n' for no)"<<endl;
        cin>>response;
    }    
}

void monthly_bills(Account& user){
    float amount;
    string response;

    cout<<"Do you have any monthly expenses? ('y' for yes, 'n' for no)"<<endl;
    cin>>response;
    while (response != "y" && response != "Y" && response != "n" && response!= "N"){
        cout << "Invalid command! Please respond with 'y' or 'n'"<<endl;
        cin >> response;
    }

    while(response == "y" || response=="Y"){
        response = 'n';
        cout<<"Expense Amount:"<<endl<<"$";
        cin>>amount;
        user.get_budget()->add_monthly_expense(amount);

        cout<<"Do you have anymore expenses? ('y' for yes, 'n' for no)"<<endl;
        cin>>response;
    }    
}

void long_term_bills(Account& user){
    float amount;
    string response;
    int months;

    cout<<"Do you have any long-term expenses (ex. school tuition)? ('y' for yes, 'n' for no)"<<endl;
    cin>>response;
    while (response != "y" && response != "Y" && response != "n" && response!= "N"){
        cout << "Invalid command! Please respond with 'y' or 'n'"<<endl;
        cin >> response;
    }

    while(response == "y" || response=="Y"){
        response = "n";
        cout<<"Expense Amount:"<<endl<<"$";
        cin>>amount;
        cout<<"How many months do you need to pay this by?"<<endl;
        cin>>months;

         user.get_budget()->add_longterm_expense(amount, months);

        cout<<"Do you have anymore expenses? ('y' for yes, 'n' for no)"<<endl;
        cin>>response; 
    }      
}

void purchasing_goals(Account& user){
    float amount;
    string response;
    string item;

    cout<<"Do you have any purchasing goals (ex. new air maxes)? ('y' for yes, 'n' for no)"<<endl;
    cin>>response;
    while (response != "y" && response != "Y" && response != "n" && response!= "N"){
        cout << "Invalid command! Please respond with 'y' or 'n'"<<endl;
        cin >> response;
    }

    while(response == "y" || response =="Y"){
        response = "n";
        cout<<"Item:"<<endl;
        cin>>item;
        cout<<"Cost:"<<endl<<"$";
        cin>>amount;

         user.get_budget()->add_purchasing_goal(amount, item);

        cout<<"Do you have anymore purchasing goals? ('y' for yes, 'n' for no)"<<endl;
        cin>>response; 
    }      
}
#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "CashFlowManager.h"


using namespace std;

class PersonalBudget {
    UserManager userManager;
    CashFlowManager* cashFlowManager;
    const string INCOME_FILENAME;
    const string EXPENSES_FILENAME;

public:
    PersonalBudget(string usersFilename, string incomeFilename, string expensesFilename) : userManager(usersFilename), INCOME_FILENAME(incomeFilename), EXPENSES_FILENAME(expensesFilename) {
        cashFlowManager = NULL;
    };
    ~PersonalBudget() {
        delete cashFlowManager;
        cashFlowManager = NULL;
    };
    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();
    bool isUserLoggedIn();

    void addIncome();
    void addExpense();
    void printCurrentMonthBalance();
    void printLastMonthBalance();
    void printBalanceFromCustomRange();

    char selectFromLoginMenu();
    char selectFromUserMenu();

};
#endif

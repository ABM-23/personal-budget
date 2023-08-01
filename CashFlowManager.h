#ifndef CASHFLOWMANAGER_H
#define CASHFLOWMANAGER_H

#include <iostream>
#include <vector>
#include <time.h>
#include "CashFlow.h"
//#include "FileWithCashFlow.h"
#include "AuxiliaryMethods.h"

using namespace std;

class CashFlowManager {
    const int LOGGED_IN_USER_ID;
    //FileWithCashFlow fileWithIncome;
    //FileWithCashFlow fileWithExpenses;
    vector<CashFlow> expenses;
    vector<CashFlow> income;

    CashFlow getNewCashFlowData();
    void printCashflowData(CashFlow cashFlow);
    void printBalance(int firstDate,int lastDate);
    void sortByDate(vector<CashFlow> &dataToSort);
    int getDateFromUser();
    float getAmountFromUser();
    int checkLoginAndPassword();
    bool isLeapYear(int year);
    bool isDateCorrect(string date);
    int howManyDaysInMonth(int month, int year);

    public:
    CashFlowManager() : LOGGED_IN_USER_ID(0){
    }

    int getTodaysDate();
    void addIncome();
    void addExpense();
    void printCurrentMonthBalance();
    void printLastMonthBalance();
    void printBalanceFromCustomRange();
};
#endif

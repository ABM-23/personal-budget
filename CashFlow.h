#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <iostream>

using namespace std;

class CashFlow {
    int userID;
    int cashFlowID;
    string item;
    float amount;
    int date;

    public:

    bool operator < (CashFlow& cashFlow);

    int getUserID();
    void setUserID(int newUserID);

    int getCashFlowID();
    void setCashFlowID(int newCashFlowID);

    string getItemName();
    void setItemName(string newItemName);

    float getAmount();
    void setAmount(float newAmount);

    int getDate();
    void setDate(int newDate);
};
#endif

#include "CashFlow.h"

int CashFlow::getUserID(){
    return userID;
}
void CashFlow::setUserID(int newUserID){
    userID = newUserID;
}
int CashFlow::getCashFlowID(){
    return cashFlowID;
}
void CashFlow::setCashFlowID(int newCashFlowID){
    cashFlowID = newCashFlowID;
}
string CashFlow::getItemName(){
    return item;
}
void CashFlow::setItemName(string newItemName){
    item = newItemName;
}
float CashFlow::getAmount(){
    return amount;
}
void CashFlow::setAmount(float newAmount){
    amount = newAmount;
}
int CashFlow::getDate(){
    return date;
}
void CashFlow::setDate(int newDate){
    date = newDate;
}

#include <iostream>
#include "UserManager.h"
#include "CashFlowManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

int main(){

    CashFlowManager manag;

    manag.addExpense();


    string sztring = "1995-23-24";

    cout << AuxiliaryMethods::convertStringToDate(sztring);

    return 0;
}


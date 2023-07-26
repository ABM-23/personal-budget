#include <iostream>
#include "UserManager.h"
#include "CashFlowManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

int main(){

    CashFlowManager manag;

    for (int i = 0; i < 2; i++) {

        manag.addExpense();
        manag.addIncome();
    }

    manag.printCurrentMonthBalance();



    return 0;
}


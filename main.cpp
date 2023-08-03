#include <iostream>
#include "PersonalBudget.h"


using namespace std;

int main(){

    char choice;
    PersonalBudget personalBudget("Users.xml", "Income.xml", "Expenses.xml");

    while (true)
    {
        if (!personalBudget.isUserLoggedIn())
        {
            choice = personalBudget.selectFromLoginMenu();

            switch (choice)
            {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

            choice = personalBudget.selectFromUserMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.printCurrentMonthBalance();
                break;
            case '4':
                personalBudget.printLastMonthBalance();
                break;
            case '5':
                personalBudget.printBalanceFromCustomRange();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logoutUser();
                break;
            }
        }
    }

    return 0;
}





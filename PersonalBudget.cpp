#include "PersonalBudget.h"

void PersonalBudget::registerUser(){
    userManager.registerUser();
}
void PersonalBudget::loginUser(){
    userManager.loginUser();
        if (userManager.isUserLoggedIn()){
     cashFlowManager = new CashFlowManager(userManager.getLoggedInUserID(), EXPENSES_FILENAME, INCOME_FILENAME);
    }
}
void PersonalBudget::changePassword(){
    userManager.changeLoggedUserPassword();
}
void PersonalBudget::logoutUser(){
    userManager.logout();
}
bool PersonalBudget::isUserLoggedIn(){
 return userManager.isUserLoggedIn();
}
void PersonalBudget::addIncome(){
    cashFlowManager -> addIncome();
}
void PersonalBudget::addExpense(){
    cashFlowManager -> addExpense();
}
void PersonalBudget::printCurrentMonthBalance(){
    cashFlowManager -> printCurrentMonthBalance();
}
void PersonalBudget::printLastMonthBalance(){
    cashFlowManager -> printLastMonthBalance();
}
void PersonalBudget::printBalanceFromCustomRange(){
    cashFlowManager -> printBalanceFromCustomRange();
}

char PersonalBudget::selectFromLoginMenu(){
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}
char PersonalBudget::selectFromUserMenu(){
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Wyswietl bilans miesiaca" << endl;
    cout << "4. Wyswietl bilans poprzedniego miesiaca" << endl;
    cout << "5. Wyswietl bilans dla zadanego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

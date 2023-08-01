#include "CashFlowManager.h"
#include "conio.h"

CashFlow CashFlowManager::getNewCashFlowData(){
    char choice = '0';
    bool isDateSet = false;
    CashFlow newCashFlow;
    newCashFlow.setUserID(LOGGED_IN_USER_ID);

    cout << "1) Dodaj z data dzisiejsza" << endl;
    cout << "2) Dodaj z inna data" << endl;


    while(!isDateSet) {
        cout << endl << "Twoj wybor:";
        choice = AuxiliaryMethods::loadChar();
        switch(choice) {
        case '1':
            system("cls");
            cout << "Dodawanie z data dzisiejsza" << endl << endl;
            newCashFlow.setDate(getTodaysDate());
            isDateSet = true;
            break;

        case '2':
            system("cls");
            cout << "Dodawanie z data uzytkownika" << endl << endl;
            newCashFlow.setDate(getDateFromUser());
            isDateSet = true;
            break;

        default:
            cout << "Nieprawidlowy wybor, wybierz opcje 1 lub 2";
        }
    }

    cout << "Podaj nazwe przychodu/wydatku :";
    newCashFlow.setItemName(AuxiliaryMethods::loadLine());

    cout << "Podaj kwote :";
    newCashFlow.setAmount(getAmountFromUser());
    system("cls");

    return newCashFlow;
}
void CashFlowManager::printCashflowData(CashFlow cashFlow){
    cout << endl;
    cout << "Data  :" << cashFlow.getDate() << endl;
    cout << "Nazwa :" << cashFlow.getItemName() << endl;
    cout << "Kwota :" << cashFlow.getAmount() << endl;

}
void CashFlowManager::sortByDate(vector<CashFlow> &dataToSort){
    sort(dataToSort.begin(), dataToSort.end());
}
int CashFlowManager::getDateFromUser(){
    string dateString = "";
    do {
        cout << "Wprowadz date w formacie RRRR-MM-DD :";
        dateString = AuxiliaryMethods::loadLine();
    } while(!isDateCorrect(dateString));

    return AuxiliaryMethods::convertStringToDate(dateString);
}
int CashFlowManager::getTodaysDate(){
    time_t actualTime;
    struct tm* date;

    time(&actualTime);
    date = localtime(&actualTime);

    return date -> tm_mday +(date -> tm_mon + 1) * 100 + (date -> tm_year + 1900) * 10000;
}

float CashFlowManager::getAmountFromUser(){
    float amount = 0;
    bool getSuccesfull = false;

    while(!getSuccesfull) {
        try {
            string userInput = AuxiliaryMethods::loadLine();
            userInput = AuxiliaryMethods::changeCommaToDot(userInput);
            amount = stof(userInput);
            getSuccesfull = true;
        } catch (invalid_argument const&) {
            cerr << "Podana wartosc nie jest liczba! Wprowadz jeszce raz :";
        }
    }
    return amount;
}
void CashFlowManager::addIncome(){
    CashFlow newIncome = getNewCashFlowData();
    if (income.empty()) newIncome.setCashFlowID(1);
    else newIncome.setCashFlowID(income.back().getCashFlowID() + 1);
    income.push_back(newIncome);
    //fileWithIncome.addCashFlow(newIncome);
}
void CashFlowManager::addExpense(){
    CashFlow newExpense = getNewCashFlowData();
    if (expenses.empty()) newExpense.setCashFlowID(1);
    else newExpense.setCashFlowID(expenses.back().getCashFlowID() + 1);
    expenses.push_back(newExpense);
    //fileWithExpenses.addCashFlow(newExpense);
}
void CashFlowManager::printBalance(int firstDate,int lastDate){
    int incomeValue = 0;
    int expensesValue = 0;

    cout << "=================================================================" << endl;
    cout << "PRZYCHODY:" << endl;

    vector <CashFlow>::iterator itr = income.begin();
    while (itr != income.end()) {

        if (( itr -> getDate() >= firstDate) && (itr -> getDate() <= lastDate)) {
        printCashflowData(*itr);
        incomeValue += itr -> getAmount();
        }
        itr++;
    }
    if (incomeValue == 0) cout << endl << "Brak przychodow spelniajacych kryteria!" << endl;

    cout << "=================================================================" << endl;
    cout << "WYDATKI:" << endl;

    itr = expenses.begin();
    while (itr != expenses.end()) {

        if (( itr -> getDate() >= firstDate) && (itr -> getDate() <= lastDate)) {
            printCashflowData(*itr);
            expensesValue += itr -> getAmount();
        }
        itr++;
    }
    if (expensesValue == 0) cout << endl << "Brak wydatkow spelniajacych kryteria!" << endl;
    cout << "=================================================================" << endl;

    cout << "Suma przychodow : " << incomeValue << endl;
    cout << "Suma wydatkow   : " << expensesValue << endl << endl;

    cout << "Bilans okresu   : " << incomeValue - expensesValue << endl;
}
void CashFlowManager::printCurrentMonthBalance(){
    int today = getTodaysDate();
    int firstDay = 100 * (today / 100) + 1;
    int lastDay  = 100 * (today / 100) + 31;

    printBalance(firstDay, lastDay);
}
void CashFlowManager::printLastMonthBalance(){
    int today = getTodaysDate();
    int firstDay = 100 * (today / 100 - 1) + 1;
    int lastDay = 100 * (today / 100 - 1) + 31;

    printBalance(firstDay, lastDay);
}
void CashFlowManager::printBalanceFromCustomRange(){
    cout <<  "Wyswietlone zostana przychody oraz wydatki ktore wystapily pomiedzy dwoma wprowadzonymi datami" << endl << endl;

    cout << "Podaj pierwsza date" << endl;
    int firstDate = getDateFromUser();

    cout << "Podaj druga date" << endl;
    int secondDate = getDateFromUser();

    if(firstDate <= secondDate) printBalance(firstDate, secondDate);
    else  printBalance(secondDate, firstDate);
}
bool CashFlowManager::isLeapYear(int year){
    if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
    else return false;
}
bool CashFlowManager::isDateCorrect(string date){
    if((date.length() == 10) && (date[4] == '-') && (date[7] == '-')) {
        int year = AuxiliaryMethods::getYear(date);
        int month = AuxiliaryMethods::getMonth(date);
        int day = AuxiliaryMethods::getDay(date);

        if ((year >= 2000) && (( month > 0) && (month <= 12))) {
            if ((day > 0) && (day <= howManyDaysInMonth(month, year))) return true;
        }
    }
    cout << "Wprowdzona data jest nieprawidlowa!" << endl;
    return false;
}
int CashFlowManager::howManyDaysInMonth(int month, int year){
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month  == 2 && isLeapYear(year)) return 29;
    else return daysInMonth[month - 1];
}

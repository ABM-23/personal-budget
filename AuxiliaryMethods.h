#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {
public:
    static string convertIntegerToString(int number);
    static int convertStringToInteger(string numberString);
    static int convertCharToInteger(char character);
    static string convertDateToString(int dateInt);
    static int convertStringToDate(string dateString);
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static string changeCommaToDot(string text);
    static string loadLine();
    static char loadChar();
    static int loadInteger();
    static int getYear(string date);
    static int getMonth(string date);
    static int getDay(string date);
};
#endif

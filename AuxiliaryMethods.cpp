#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntegerToString(int number){
    ostringstream ss;
    string numberString;

    ss << number;
    numberString = ss.str();

    return numberString;
}
int AuxiliaryMethods::convertStringToInteger(string numberString){
    int number;
    istringstream iss(numberString);
    iss >> number;

    return number;
}
int AuxiliaryMethods::convertCharToInteger(char character){
    return character - 48;
}
string AuxiliaryMethods::convertDateToString(int dateInt){

}
int AuxiliaryMethods::convertStringToDate(string dateString){

}
string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
string AuxiliaryMethods::changeCommaToDot(string text){
    string changedText;

    for (int i = 0; i < text.length(); i++){
        if (text[i] == ',') changedText += '.';
        else  changedText += text[i];
    }
    return changedText;
}
string AuxiliaryMethods::loadLine(){
    string input = "";
    getline(cin, input);
    return input;
}
char AuxiliaryMethods::loadChar() {
    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}
int AuxiliaryMethods::loadInteger() {
    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

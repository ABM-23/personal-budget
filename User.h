#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int userID;
    string firstName;
    string surname;
    string login;
    string password;

    public:
    int getUserID();
    void setUserID(int newUserID);

    string getFirstName();
    void setFirstName(string newFirstName);

    string getSurname();
    void setSurname(string newSurname);

    string getLogin();
    void setLogin(string newLogin);

    string getPassword();
    void setPassword(string newPassword);
};
#endif

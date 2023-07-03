#include "User.h"

int User::getUserID(){
    return userID;
}
void User::setUserID(int newUserID){
    userID = newUserID;
}
string User::getFirstName(){
    return firstName;
}
void User::setFirstName(string newFirstName){
    firstName = newFirstName;
}
string User::getSurname(){
    return surname;
}
void User::setSurname(string newSurname){
    surname = newSurname;
}
string User::getLogin(){
    return login;
}
void User::setLogin(string newLogin){
    login = newLogin;
}
string User::getPassword(){
    return password;
}
void User::setPassword(string newPassword){
    password = newPassword;
}

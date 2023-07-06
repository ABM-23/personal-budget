#include "UserManager.h"
//PO DODANIU METOD POMOCNICZYCH ZAMIENIC GETLINE

void UserManager::registerUser(){
    User user = getNewUserData();
    users.push_back(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
User UserManager::getNewUserData(){
    User user;
    string firstName;
    string surname;
    string login;
    string password;
    user.setUserID(getNewUserID());

    cout << "Podaj imie: ";
    getline(cin, firstName);
    user.setFirstName(firstName);

    cout << "Podaj nazwisko: ";
    getline(cin, surname);
    user.setSurname(surname);

    do
    {
        cout << "Podaj login: ";
        //login = MetodyPomocnicze::wczytajLinie();
        getline(cin, login);
        user.setLogin(login);

    } while (loginExists(user.getLogin()));

    cout << "Podaj haslo: ";
    //password = MetodyPomocnicze::wczytajLinie();
    getline(cin, password);
    user.setPassword(password);

    return user;
}
bool UserManager::loginExists(string login) {
    for (int i = 0; i < (int)users.size(); i++) {
        if (users.at(i).getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie!" << endl;
            return true;
        }
    }
    return false;
}
void UserManager::loginUser(){
    loggedUserID = checkLoginAndPassword();
}
void UserManager::logout(){
    loggedUserID = 0;
}
int UserManager::checkLoginAndPassword() {
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    getline(cin,login);

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int triesLeft = 3; triesLeft > 0; triesLeft--) {
                cout << "Podaj haslo. Pozostalo prob: " << triesLeft << ": ";
                getline(cin, password);

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return itr -> getUserID();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
bool UserManager::isUserLoggedIn(){
    if (loggedUserID > 0) return true;
    else return false;
}
int UserManager::getLoggedInUserID(){
    return loggedUserID;
}
int UserManager::getNewUserID() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserID() + 1;
}
void UserManager::changeLoggedUserPassword(){
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    getline(cin, newPassword);

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserID() == loggedUserID) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
}

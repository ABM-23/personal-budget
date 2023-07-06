#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class UserManager {
    int loggedUserID;
    vector<User> users;

    User getNewUserData();
    int getNewUserID();
    bool loginExists(string login);
    int checkLoginAndPassword();

    public:
    UserManager() {
        loggedUserID = 0;
    }

    void registerUser();
    void loginUser();
    void changeLoggedUserPassword();
    void logout();
    bool isUserLoggedIn();
    int getLoggedInUserID();
};
#endif

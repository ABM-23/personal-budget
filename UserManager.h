#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {
    FileWithUsers fileWithUsers;
    int loggedUserID;
    vector<User> users;

    User getNewUserData();
    int getNewUserID();
    bool loginExists(string login);
    int checkLoginAndPassword();

    public:
    UserManager(string usersFileName) : fileWithUsers(usersFileName) {
        users = fileWithUsers.loadUsersFromFile();
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

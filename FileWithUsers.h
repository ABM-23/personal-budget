#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers : public XmlFile  {
    public:
    FileWithUsers(string usersFilename) : XmlFile(usersFilename) {};

    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void editPasswordInFile(int loggedUserID, string newPassword);
};
#endif

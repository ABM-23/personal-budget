#include "FileWithUsers.h"

vector<User> FileWithUsers::loadUsersFromFile(){
    CMarkup xml;
    vector<User> users;
    bool fileExists = xml.Load(getFileName().c_str());

    if (fileExists) {

        xml.FindElem();
        xml.IntoElem();

        while ( xml.FindElem("User") ) {
            User user;
            xml.IntoElem();

            xml.FindElem( "UserID" );
            user.setUserID(atoi(MCD_2PCSZ(xml.GetData())));

            xml.FindElem( "FirstName" );
            user.setFirstName(xml.GetData());

            xml.FindElem( "Surname" );
            user.setSurname(xml.GetData());

            xml.FindElem( "Login" );
            user.setLogin(xml.GetData());

            xml.FindElem( "Password" );
            user.setPassword(xml.GetData());

            users.push_back(user);
            xml.OutOfElem();
        }
    }
    return users;
}
void FileWithUsers::addUserToFile(User userToAdd) {
    CMarkup xml;
    bool fileExists = xml.Load(getFileName().c_str());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "User" );
    xml.IntoElem();
    xml.AddElem( "UserID", userToAdd.getUserID());
    xml.AddElem( "FirstName", userToAdd.getFirstName());
    xml.AddElem( "Surname", userToAdd.getSurname());
    xml.AddElem( "Login", userToAdd.getLogin());
    xml.AddElem( "Password", userToAdd.getPassword());
    xml.Save(getFileName().c_str());
}
void FileWithUsers::editPasswordInFile(int loggedUserID, string newPassword){
    CMarkup xml;
    xml.Load(getFileName().c_str());

    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("User")) {
        xml.IntoElem();
        xml.FindElem("UserID");
        if ( AuxiliaryMethods::convertStringToInteger(xml.GetData()) == loggedUserID) {
            xml.FindElem("Password");
            xml.SetData(newPassword);
            break;
        }
        xml.OutOfElem();
    }
    xml.Save(getFileName().c_str());
}

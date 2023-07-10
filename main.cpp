#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

int main(){
    UserManager userManager("Users.xml");
    //userManager.registerUser();
    while(!userManager.isUserLoggedIn()){
            userManager.loginUser();
    }

    //userManager.changeLoggedUserPassword();

    cout << "dupa";


    return 0;
}


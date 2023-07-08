#include <iostream>
#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

int main() {
    string a ="127,50";
    string b = "";
    float c;

    b = AuxiliaryMethods::changeCommaToDot(a);
    cout << b;
    c = stof(b);
    cout << c;

}

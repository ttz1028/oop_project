#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    User U1 = User();

    Library L1 = Library(50);

    Menu M1 = Menu();

    M1.interface(U1,L1);

    return 0;
}
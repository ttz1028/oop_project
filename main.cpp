#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    Student my_student = Student(); 

    Staff my_staff = Staff();

    Library my_library = Library(50);

    Menu M1 = Menu();

    my_library.read_book_record("mylibrary4.txt");

    M1.interface(my_student,my_staff,my_library);

    return 0;
}
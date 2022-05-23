#ifndef MENU_H
#define MENU_H
#include <cstdlib> // Needed to use the exit function
#include "Library.h"

class Menu{
private:
    Book* book_list;  //array of Books in library
    int* book_number_list; //array of number of Books in library
    Book* test_book_list;  //array of Books in Student
    int* test_book_flag; //array of flags in Student
public:
    Menu(); //Default Constructor

    void interface(Student new_student,Staff new_staff,Library new_Library); //Main interface

    void Student_interface(Student new_student,Staff new_staff,Library new_Library); //Student interface

    void Staff_interface(Student new_student,Staff new_staff,Library new_Library);//Staff interface

    void librarian_interface(Student new_student,Staff new_staff,Library new_Library);//Librarian interface
    
    ~Menu(); //Destructor
};

#endif
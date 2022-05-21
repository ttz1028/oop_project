#ifndef MENU_H
#define MENU_H
#include <cstdlib> // Needed to use the exit function
#include "Library.h"

class Menu{
private:
    Book* test_book_list;
    int* test_book_flag;
public:
    Menu();
    void interface(Student new_student,Staff new_staff,Library new_Library);
    void Student_interface(Student new_student,Staff new_staff,Library new_Library);
    void Staff_interface(Student new_student,Staff new_staff,Library new_Library);
    void librarian_interface(Student new_student,Staff new_staff,Library new_Library);
    ~Menu(); 
};

#endif
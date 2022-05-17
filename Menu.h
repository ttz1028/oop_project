#ifndef MENU_H
#define MENU_H

#include "Library.h"
#include "Abs_user.h"

class Menu{
public:
    Menu();
    void interface(User new_user, Library new_Library);
    ~Menu(); 
};

#endif
#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include<string>
#include "Library.h"
#include "User.h"
#include "Book.h"
#include "Abs_user.h"


using namespace std;

class Librarian:public Abs_user{       
public:
    Librarian();  //Default Constructor
    string get_username();  //return username
    string get_password();  //return password
    ~Librarian(); //Destructor
};



#endif

#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include<string>
#include "Library.h"
#include "User.h"
#include "Book.h"
#include "People.h"


using namespace std;

class Librarian: public People{       
/*protected:
    string m_StaffUsername;
    string m_StaffPassword;*/
public:
    Librarian();
    //Librarian(string StaffUsername,string StaffPassword);
    string get_username();
    string get_password();
    void set_username(string new_username);
    void set_password(string new_password);
    void addBook(Book m_Book,int NumberofBooks);
    void delBook(string BookName,int num_of_del);
    void checkAll();        //查看所有书籍
    void view_user_return_date(User username);
    ~Librarian();
};

#endif

#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include<string>
#include "Library.h"
#include "User.h"
#include "Book.h"


using namespace std;

class Librarian: public User{       
protected:
    string m_StaffUsername;
    string m_StaffPassword;
public:
    Librarian();
    Librarian(string StaffUsername,string StaffPassword);
    void addBook(Book m_Book,int NumberofBooks);
    void delBook(string BookName,int num_of_del);
    void checkAll();        //查看所有书籍
    void view_user_return_date(User username);
    ~Librarian();
};

#endif

#ifndef BOOK_H
#define BOOK_H

#include<string>


using namespace std;

class Book{       
protected:
    string m_bookName;
    string m_bookID;
    string m_author;
public:
    Book();
    Book(string bookName,string bookID,string author);
    string get_bookName();
    string get_bookID();
    string get_author();
    ~Book();
};

#endif
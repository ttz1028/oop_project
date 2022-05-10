#include "Book.h"

Book::Book(){
    m_bookName = "";
    m_bookID = "";
    m_author = "";
}

Book::Book(string bookName,string bookID,string author){
    m_bookName = bookName;
    m_bookID = bookID;
    m_author = author;   
}
string Book::get_bookName(){
    return m_bookName;
}

string Book::get_bookID(){
    return m_bookID;
}

string Book::get_author(){
    return m_author;
}


Book::~Book(){}
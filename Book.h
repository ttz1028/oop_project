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
    Book();      //Default Constructor
    Book(string bookName,string bookID,string author);   //Constructor
    string get_bookName(); //return book name
    string get_bookID();   //return book ID
    string get_author();   //return book author
    void set_bookName(string bookName);  //set book name     
    void set_bookID(string bookID);     //set book ID   
    void set_author(string author);     //set book author   
    ~Book();    //Destructor
};

#endif
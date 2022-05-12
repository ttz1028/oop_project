#ifndef LIBRARY_H
#define LIBRARY_H

#include<string>
#include "Book.h"
#include "User.h"
#include "Librarian.h"

using namespace std;

class Library{       
protected:
    Book* m_Bookcase;  //放书的数组
    int* m_number_of_a_particular_book; //放书的数量的数组
    int m_Maximum_books_collection;  //最大藏书量
    int m_number_of_books_in_library;  //现在图书馆有多少本（不同种类）的书
public:
    Library();
    Library(int Maximum_books_collection);
    Book bookNameSearch(string BookName);
    pair<Book*,int> authorSearch(string Author);  //双返回值
    Book bookIDSearch(string BookID);
    int book_location(Book new_book); //查找书在数组内的index
    void addBook(Book new_book,int num_of_books);
    bool delBook(Book new_book,int num_of_books);  //可通过界面扩展
    bool Book_borrow(Book b_book, User username);
    void Book_return(Book r_book, User username);
    Book* All_books_list();
    int* All_books_number_list();
    void read_book_record(string filename);      
    ~Library();
};

#endif

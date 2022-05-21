#ifndef LIBRARY_H
#define LIBRARY_H

#include<string>
#include "Book.h"
#include "Student.h"
#include "Staff.h"

using namespace std;

class Library{       
protected:
    Book* m_Bookcase;  //Array of books
    int* m_number_of_a_particular_book; //Array of the number of books
    int m_Maximum_books_collection;  //Maximum book collection
    int m_number_of_books_in_library;  // How many (different book name) books in the library
public:
    Library(); //Default Constructor
    Library(int Maximum_books_collection); //Constructor

    Book bookNameSearch(string BookName); //Search by book name and return a book

    pair<Book*,int> authorSearch(string Author);  //Search by author and returns an array of all the books this author has written, 
                                                  //and the size of the array
    
    Book bookIDSearch(string BookID); //Search by book ID and return a book

    int book_location(Book new_book); //Returns the index of the particular book in the book array

    void addBook(Book new_book,int num_of_books);  //Add a book to the library and the number of this book. eg: add 10 books call Anna Karenina
    
    bool delBook(Book new_book,int num_of_books);  //Remove a book from the library, and its number. eg: remove 5 books call Anna Karenina
    
    bool Student_Book_borrow(Book b_book, Student new_user);  //A user borrow a book from the library(interact with User)
    
    void Student_Book_return(Book r_book, Student new_user);  //A user return a book to library(interact with User)

    bool Staff_Book_borrow(Book b_book, Staff new_user);  //A user borrow a book from the library(interact with User)
    
    void Staff_Book_return(Book r_book, Staff new_user);  //A user return a book to library(interact with User)    
    
    Book* All_books_list();  //Return the array of books
    
    int* All_books_number_list();  //Retrun the array of the number of books
    
    void read_book_record(string filename);  //Read txt files and add books to the library system    
    
    int get_number_of_books_in_labrary(); //Returns how many different types of books the library now has, i.e. the size of the array of books
    
    ~Library(); //Destructor
};

#endif

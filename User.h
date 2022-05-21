#ifndef USER_H
#define USER_H

#include<string>
#include "Book.h"


using namespace std;

class User{       
protected:
    int m_max_capacity; // The maximum amount of books a user can borrow
    int number_of_book; // Number of books already borrowed
    Book* book_list; // Array used by users to store books
    
    int* book_flag; //A control array to see if there are empty spaces in book list
                    //This array has only 0 and 1. 
                    //0 is used to indicate that this position is empty 
                    //1 is used to indicate that there is already a book in this position
public:
    User(); //Default Constructor
    User(int max_capacity);  //Constructor
    void set_max_capacity(int max_capacity); // set maximum amount of books a user can borrow
    bool borrow_book(Book new_book); // borrow a book from library(interact with Library)
    void return_book(Book new_book); //return a book to library(interact with Library)
    Book* return_book_list(); //return book_list 
    int* return_book_flag();  //return book_falg
    int user_book_location(Book new_book); //returns the index of a particular book in the array
    double get_book_number(); //return the number of books borrowed
    virtual double get_total_price() = 0; //return the total price of books
    ~User(); //Destructor
};

#endif

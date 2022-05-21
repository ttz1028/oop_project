#include "User.h"
#include<iostream>

using namespace std;

User::User(){
    book_list = nullptr;
    number_of_book = 0;
    book_flag = nullptr;
    m_max_capacity = 0;
}
User::User(int max_capacity){
    m_max_capacity = max_capacity;
    book_list = new Book[m_max_capacity]; // By default, each user can borrow up to five books, which can be modified 
    number_of_book = 0; 
    book_flag = new int[m_max_capacity];  
    //Set all values of book_flag to 0
    for (int i = 0; i < m_max_capacity; i++)
    {
        book_flag[i] = 0;
    }
     
}

void User::set_max_capacity(int max_capacity){
    m_max_capacity = max_capacity;
}


bool User::borrow_book(Book new_book){
    bool flag = false;
    if (number_of_book < 5)
    {
        book_list[number_of_book] = new_book;
        book_flag[number_of_book] = 1;
        cout << "Book Borrowing Success" << " | Book name:" << new_book.get_bookName() << endl;
        
        cout << "User now have" << number_of_book << "book(s)." << endl;
        flag = true;
    }
    return flag;    
}
void User::return_book(Book new_book){
    book_flag[user_book_location(new_book)] = 0; //Change the corresponding position in the flags array of the book to be returned to 0
}

int User::user_book_location(Book new_book){
    for (int i = 0; i < m_max_capacity; i++)
    {
        if (new_book.get_bookID() == book_list[i].get_bookID())
        {
            return i;
        }        
    }
    //If not found, -1 is returned and an error is reported
    cout << "Can not find this book!" << endl;
    return -1;    
}

Book* User::return_book_list(){
    return book_list;
}

int* User::return_book_flag(){
    return book_flag;
}


double User::get_book_number(){  
    double number = 0;  //Books that user have.
    for (int i = 0; i < m_max_capacity; i++)
    {
        if (book_flag[i] == 1)
        {
            number++;
        }
        
    }
    return number;
}


User::~User(){
    //delete[] book_list;         
    //delete[] book_flag;
}
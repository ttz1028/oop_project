#include "Staff.h"

Staff::Staff(){
    m_max_capacity = 5; //max 5 books
    book_price = 2; // $2 each book
    book_list = new Book[m_max_capacity]; // By default, each user can borrow up to five books, which can be modified 
    number_of_book = 0; 
    book_flag = new int[m_max_capacity];  
    //Set all values of book_flag to 0
    for (int i = 0; i < m_max_capacity; i++)
    {
        book_flag[i] = 0;
    }
}

double Staff::get_total_price(){
    return (get_book_number()*book_price);
}

Staff::~Staff(){}
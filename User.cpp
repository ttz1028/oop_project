#include "User.h"
#include<iostream>

using namespace std;

User::User(){
    m_username = "";
    m_password = "";
    book_list = nullptr;
    number_of_book = 0;
    book_flag = nullptr;
    m_max_capacity = 0;
}
User::User(string username, string password){
    m_username = username;
    m_password = password;
    m_max_capacity = 5;
    book_list = new Book[m_max_capacity]; //  默认每个用户最多借五本书，可通过修改max_capacity修改
    number_of_book = 0; 
    book_flag = new int[m_max_capacity]; //可修改  
    //将book_flag的值全部设为0
    for (int i = 0; i < m_max_capacity; i++)
    {
        book_flag[i] = 0;
    }
     
}

void User::set_username(string username){
    m_username = username;
}

void User::set_password(string password){
    m_password = password;
}

void User::set_max_capacity(int max_capacity){
    m_max_capacity = max_capacity;
}

string User::getUserName(){
    return m_username;
}

bool User::borrow_book(Book new_book){
    bool flag = false;
    if (number_of_book < 5)
    {
        book_list[number_of_book] = new_book;
        book_flag[number_of_book] = 1;
        cout << "用户借书成功," << "借到了" << new_book.get_bookName() << endl;
        
        cout << "用户目前有" << number_of_book << "本书" << endl;
        flag = true;
    }
    return flag;    
}
void User::return_book(Book new_book){
    book_flag[user_book_location(new_book)] = 0; //把要还的书的flag数组里的相应位置变为 0
}

int User::user_book_location(Book new_book){
    for (int i = 0; i < m_max_capacity; i++)
    {
        if (new_book.get_bookID() == book_list[i].get_bookID())
        {
            return i;
        }        
    }
    //若找不到则返回-1并报错
    cout << "找不到此书" << endl;
    return -1;    
}

Book* User::return_book_list(){
    return book_list;
}

int* User::return_book_flag(){
    return book_flag;
}

void User::view_all_books_and_return_times(){

}

int User::get_book_number(){  
    int number = 0;  //用户现在多少本书
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
    //delete[] book_list;         Problem：添加即报错
    //delete[] book_flag;
}
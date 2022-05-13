#ifndef USER_H
#define USER_H

#include<string>
#include "Book.h"

using namespace std;

class User{       
protected:
    string m_username;
    string m_password;
    int m_max_capacity; //最大借书量
    int number_of_book; 
    Book* book_list; //已借书籍的数组  最大值为5（可修改）
    int* book_flag; //查看是否有空位借书的数组
public:
    User();    
    User(string username, string password);
    void set_username(string username);
    void set_password(string password);
    void set_max_capacity(int max_capacity);
    string getUserName();
    bool borrow_book(Book new_book);
    void return_book(Book new_book);
    Book* return_book_list(); //返回已借书籍的数组
    int* return_book_flag();  //返回book_falg数组
    int user_book_location(Book new_book); //返回书在数组里的index
    void view_all_books_and_return_times(); //未完成！ 未完成！ 未完成！ 未完成！ 未完成！
    int get_book_number(); //返回现在借了几本书
    ~User();
};

#endif

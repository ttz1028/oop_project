#include "Library.h"
#include <iostream>

using namespace std;

Library::Library(){
    m_Maximum_books_collection = 0;
    m_number_of_books_in_library = 0;
    m_Bookcase = nullptr;
    m_number_of_a_particular_book = nullptr;
}

Library::Library(int Maximum_books_collection){
    m_Maximum_books_collection = Maximum_books_collection;
    m_number_of_books_in_library = 0;
    m_Bookcase = new Book[m_Maximum_books_collection];
    m_number_of_a_particular_book = new int[m_Maximum_books_collection];
}

Book Library::bookNameSearch(string BookName){
    Book cannot_find_this_book = Book();  //找不到对应的书，则返回一本没用的书，在界面中扩展
    for (int i = 0; i < m_number_of_books_in_library; i++)
    {
        if (BookName == m_Bookcase[i].get_bookName())
        {
            return m_Bookcase[i];
        }        
    }
    cout << "Can not find this book!" << endl;
    return cannot_find_this_book;
        
}

pair<Book*,int> Library::authorSearch(string Author){

    Book* All_books_by_this_author = new Book[m_number_of_books_in_library];
    int number_of_book_by_this_author = 0;

    for (int i = 0; i < m_number_of_books_in_library; i++)
    {
        if (Author == m_Bookcase[i].get_author())
        {
            All_books_by_this_author[number_of_book_by_this_author] = m_Bookcase[i];
            number_of_book_by_this_author++;
        }        
    }    
    return make_pair(All_books_by_this_author,number_of_book_by_this_author);  //找不到对应的作者着返回空数组 和 0本书，在界面中扩展
    
    
}


Book Library::bookIDSearch(string BookID){
    Book cannot_find_this_book = Book();  //找不到对应的书，则返回一本没用的书，在界面中扩展
    for (int i = 0; i < m_number_of_books_in_library; i++)
    {
        if (BookID == m_Bookcase[i].get_bookID())
        {
            return m_Bookcase[i];
        }        
    }
    cout << "Can not find this book!" << endl;
    return cannot_find_this_book;
            
}

int Library::book_location(Book new_book){
    for (int i = 0; i < m_number_of_books_in_library; i++)
    {
        if (new_book.get_bookID() == m_Bookcase[i].get_bookID()) //通过ID对比进行定位
        {
            return i; //返回书的index
        }        
    }
    //若找不到则返回-1并报错
    cout << "找不到此书" << endl;
    return -1;
}

void Library::addBook(Book new_book,int num_of_books){
    
    for (int i = 0; i < m_number_of_books_in_library; i++)
    {
        if (new_book.get_bookID() == m_Bookcase[i].get_bookID())  //通过ID确认添加的书籍是否存在
        {
            m_number_of_a_particular_book[i] = m_number_of_a_particular_book[i] + num_of_books; //若存在则添加对应数量
        }        
    }
    //若不存在则添加新书及数量
    m_Bookcase[m_number_of_books_in_library] = new_book;  //添加书
    m_number_of_a_particular_book[m_number_of_books_in_library] = num_of_books; //添加书的数量
    m_number_of_books_in_library++; //index++
    
}

bool Library::delBook(Book m_book,int num_of_books){
    for (int i = 0; i < m_number_of_books_in_library; i++)
    {
        if (m_book.get_bookID() == m_Bookcase[i].get_bookID())  //通过ID确认要删除的书
        {
            m_number_of_a_particular_book[i] = m_number_of_a_particular_book[i] - num_of_books;  //若存在对应的书则删除对应数量,返回true
            cout << "删除书： " << m_Bookcase[i].get_bookID() << "现有数量： " <<  m_number_of_a_particular_book[i] << endl;  //Unit testing
            return true;
        }        
    }
    //若不存在则报错，返回false
    cout << "图书馆内没有这本书" << endl;
    return false;
    
}

bool Library::Book_borrow(Book b_book, User new_user){
    //查看书籍是否可用
    if (m_number_of_a_particular_book[book_location(b_book)] > 0)
    {
        
        for (int i = 0; i < 5; i++)
        {
            if (*(new_user.return_book_flag()+i) == 0)  //检查用户的数组是否有可用空位
            {   
                *new_user.return_book_list() = b_book;    //向用户借书数组内添加书 
                cout << "借书成功" << endl; //unit testing

                *(new_user.return_book_flag()+i) = 1; //将已有书的位置标记为 1（不可用）
                cout <<  "数组可用性测试：" << *(new_user.return_book_flag()+ new_user.user_book_location(b_book)) << "期望值: 1" << endl; //unit testing

                m_number_of_a_particular_book[book_location(b_book)]--; //图书馆里被借走的那本书的库存减 1；
            
                return true;
            }   
        } 
    }
    
    cout << "借书失败" << endl;  //unit testing
    return false; 
               
}
    

void Library::Book_return(Book r_book, User new_user){                 //new_user.user_book_location(r_book)  书在用户的列表中的index 
    *(new_user.return_book_flag()+ new_user.user_book_location(r_book)) = 0;    //将用户书的空的位置标记为0（可用）
    cout << "还书成功" << endl; //unit testing
    cout <<  "数组可用性测试：" << *(new_user.return_book_flag()+ new_user.user_book_location(r_book)) << "期望值: 0" << endl; //unit testing
    m_number_of_a_particular_book[book_location(r_book)]++; //图书馆里被归还的那本书的库存加 1；
    
}

Library::~Library(){
    delete[] m_Bookcase;
    delete[] m_number_of_a_particular_book;
}



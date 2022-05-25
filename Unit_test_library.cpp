#include "Menu.h"
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    Library libA=Library(50);
    libA.read_book_record("mylibrary4.txt");
    cout<<"actual output:"<<endl;
    cout<<libA.bookIDSearch("A001").get_bookName()<<endl;
    cout<<"actual output:"<<endl;
    cout<<libA.bookNameSearch("Three_Body_Problem").get_bookID()<<endl;
    cout<<"expect output:Three_Body_Problem"<<endl;
    cout<<"expect output:A001"<<endl;
    cout<<endl;
//test1


cout<<"actual output:"<<endl;
Book new_book =Book("A_Study_Of_History ","A002"," Arnold_J._Toynbee ");
cout<<libA.book_location(new_book )<<endl;
cout<<"expected output:1"<<endl;
cout<<endl;
//test2


cout<<"actual output:"<<endl;
  Book*  book_list = libA.All_books_list();
 int* book_number_list = libA.All_books_number_list();
 cout<<std::left<<setw(50)<<"Book Name"<<std::left<<setw(50)<<"ID"<< std::left<<setw(50)<<"Author"<< std::left<<setw(50)<<"Quantity"
<<std::left<<setw(50)<<endl;
for (int i = 0; i < libA.get_number_of_books_in_labrary(); i++)
     {
     cout << std::left<<setw(50)<< (book_list+i)->get_bookName() << std::left<<setw(50)<< (book_list+i)->get_bookID() <<std::left<<setw(50)<<
    (book_list+i)->get_author() <<std::left<<setw(50) << *(book_number_list+i) << endl;
    }
cout<<"expected output:all book number and name from mylibrary4.txt"<<endl;
cout<<endl;
//test3


cout<<"actual output:"<<endl;
Book added_book=Book("added_book","A021","Jack");
libA.addBook(added_book,10);
cout<<libA.get_number_of_books_in_labrary()<<endl;

cout<<"expected output: " << endl;
cout << "Added successfully!"<<endl;
cout<<endl;
//test4


cout<<"actual output:"<<endl;
libA.delBook(added_book,10);
cout<<libA.get_number_of_books_in_labrary()<<endl;

cout<<"expected output: " << endl;
cout<<"A021 | Now have: 0"<<endl;
cout<<endl;
//test5

cout<<"actual output:"<<endl;
Student A = Student();
libA.Student_Book_borrow(new_book, A);
cout<<"expected output:"<<endl;
cout<<"Borrowed successfully | Book name is A_Study_Of_History "<<endl;
cout<<endl;
//test6


cout<<"actual output:"<<endl;
libA.Student_Book_return(new_book, A);
cout<<"expected output:"<<endl;
cout<<"Returned successfully | Book name is A_Study_Of_History "<<endl;
cout<<endl;
//test7


cout<<"actual output:"<<endl;
Staff B = Staff();
libA.Staff_Book_borrow(new_book,B);
cout<<"expected output:"<<endl;
cout<<"Borrowed successfully | Book name is A_Study_Of_History "<<endl;
cout<<endl;
//test8


cout<<"actual output:"<<endl;
libA.Staff_Book_return(new_book, B);
cout<<"expected output:"<<endl;
cout<<"Returned successfully | Book name is A_Study_Of_History "<<endl;
cout<<endl;



}
#include "Librarian.h"
#include <iostream>
#include <string>
using namespace std;
int main(){

    Book b1 = Book("假如给我三天光明第二部","海伦凯勒","A123");

    Book b2 = Book("软件工程","张三","B123");

    Book b3 = Book("Matlab从入门到精通","赵四","C989");

    User U1 = User("admin","123456");

    Library L1 = Library(5);

    Librarian LL1 = Librarian("Ladmin","123456");

    L1.addBook(b1,3);
    L1.addBook(b2,2);
    L1.addBook(b3,5);
    L1.addBook(b1,5);

    int count = 3;

    //书数组
    printf("--------------------------------------------------\n");
    printf("书数组:\n");
    Book* test_book_list_22 = L1.All_books_list();
    for (int i = 0; i < count; i++)
    {
        cout <<  (test_book_list_22+i)->get_bookName() << endl;  //借书测试 1  通过
    }

    //书籍对照组
    printf("--------------------------------------------------\n");
    printf("书籍对照组:\n");
    int* test_book_list_11 = L1.All_books_number_list();
    
    for (int i = 0; i < count; i++)
    {
        cout <<  *(test_book_list_11+i) << " ";
    }
    cout << endl;

    L1.Book_borrow(b1,U1);
    L1.Book_borrow(b2,U1);
    L1.Book_borrow(b3,U1);

            //书数组
    printf("--------------------------------------------------\n");
    printf("书数组:\n");
    Book* test_book_list_0 = L1.All_books_list();
    for (int i = 0; i < count; i++)
    {
        cout <<  (test_book_list_0+i)->get_bookName() << endl;  //借书测试 1  通过
    }

    //书籍对照组
    printf("--------------------------------------------------\n");
    printf("书籍对照组:\n");
    int* test_book_list_2 = L1.All_books_number_list();
    
    for (int i = 0; i < count; i++)
    {
        cout <<  *(test_book_list_2+i) << " ";
    }
    cout << endl;




    return 0;
}
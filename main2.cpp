#include "Librarian.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
    Book b1 = Book("假如给我三天光明第二部","海伦凯勒","A123");

    Book b2 = Book("软件工程1","张三","B123");

    Book b21 = Book("软件工程2","张三","B99533");

    Book b23 = Book("软件工程3","张三","B1616");

    Book b3 = Book("Matlab从入门到精通","赵四","C989");

    User U1 = User("admin","123456");

    Library L1 = Library(100);

    Librarian LL1 = Librarian("Ladmin","123456");

    int count = 5;

    //添加图书
    L1.addBook(b1,3);
    L1.addBook(b2,2);
    L1.addBook(b3,77);
    L1.addBook(b21,80);
    L1.addBook(b23,1);

    //书数组
    printf("--------------------------------------------------\n");
    printf("书数组:\n");
    Book* test_book_list_3 = L1.All_books_list();
    for (int i = 0; i < count; i++)
    {
        cout <<  (test_book_list_3+i)->get_bookName() << endl;  //借书测试 1  通过
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
    
    //用户对照组
    printf("--------------------------------------------------\n");
    printf("用户对照组:\n");
    int* test_book_list = U1.return_book_flag();

    for (int i = 0; i < count; i++)
    {
        cout <<  *(test_book_list+i) << " ";
    }
    cout << endl;

    //借书
    printf("--------------------------------------------------\n");    
    L1.Book_borrow(b1,U1);
    L1.Book_borrow(b2,U1);
    L1.Book_borrow(b3,U1);
    L1.Book_borrow(b23,U1);
    L1.Book_borrow(b21,U1);
    
    //用户对照组2    借了三本书      期望值应该为 1 1 1 0 0
    printf("--------------------------------------------------\n");
    printf("用户对照组2:\n");
    int* test_book_list_4 = U1.return_book_flag();

    for (int i = 0; i < count; i++)
    {
        cout <<  *(test_book_list_4+i) << " ";
    }
    cout << endl;

    //用户书数组
    printf("--------------------------------------------------\n");
    printf("用户书数组:\n");
    Book* test_book_list_5 = U1.return_book_list();

    for (int i = 0; i < count; i++)
    {
        cout <<  (test_book_list_5+i)->get_bookName()  << " ";
    }
    cout << endl;



    return 0;
}

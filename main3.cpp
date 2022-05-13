#include "Librarian.h"
#include <iostream>
#include <string>
using namespace std;
int main(){

    User U1 = User("admin","123456");

    Library L1 = Library(50);

    Librarian LL1 = Librarian("Ladmin","123456");

    int count = 20;

        /*书数组      空的
    printf("--------------------------------------------------\n");
    printf("书数组:\n");
    Book* test_book_list_3 = L1.All_books_list();
    for (int i = 0; i < count; i++)
    {
        cout <<  (test_book_list_3+i)->get_bookName() << endl;  //借书测试 1  通过
    }*/

    //书籍对照组
    printf("--------------------------------------------------\n");
    printf("书籍对照组:\n");
    int* test_book_list_2 = L1.All_books_number_list();
    
    for (int i = 0; i < count; i++)
    {
        cout <<  *(test_book_list_2+i) << " ";
    }
    cout << endl;

    L1.read_book_record("mylabrary.txt");

    printf("第一部分通过!\n");

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
    int* test_book_list_1 = L1.All_books_number_list();
    
    for (int i = 0; i < count; i++)
    {
        cout <<  *(test_book_list_2+i) << " ";
    }
    cout << endl;

    printf("--------------------------------------------------\n");
    Book b2 = Book("假如给我三天光明1","A1111","张三");
    cout << b2.get_bookID() << endl;

    Book b3 = Book("软件工程2","B995sdaq3","张三");

    Book b4 = Book("软件工程3","B99dasd3","张三");

    L1.addBook(b2,100);
    L1.addBook(b3,6);
    L1.addBook(b4,9);
    
    L1.read_book_record("mylabrary2.txt");

    Book b5 = Book("软件工程4","B99aacz3","张三");
    L1.addBook(b5,10);
    


    
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
  



    return 0;
}
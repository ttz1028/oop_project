#include "Librarian.h"
#include <iostream>
#include <string>
#include <iomanip>
using std::setw;
using namespace std;
int main(){

    User U1 = User("admin","123456");

    Library L1 = Library(50);

    Librarian LL1 = Librarian("Ladmin","123456");

    L1.read_book_record("mylabrary.txt");


    Book b2 = Book("天地一号","A1111","张三");

    Book b3 = Book("软件工程1","B995sdaq3","张三");

    Book b4 = Book("软件工程2","B99dasd3","张三");

    L1.addBook(b2,1);
    L1.addBook(b3,1);
    L1.addBook(b4,1);
    
    L1.read_book_record("mylabrary2.txt");

    Book b5 = Book("软件工程3","B99aacz3","张三");

    L1.addBook(b5,1);

    /*//书数组
    printf("--------------------------------------------------\n");
    printf("书数组:\n");
    Book* test_book_list_22 = L1.All_books_list();
    for (int i = 0; i < L1.get_number_of_books_in_labrary(); i++)
    {
        cout <<  (test_book_list_22+i)->get_bookName() << endl;  //借书测试 1  通过
    }

    //书籍对照组
    printf("--------------------------------------------------\n");
    printf("书籍对照组:\n");
    int* test_book_list_11 = L1.All_books_number_list();
    
    for (int i = 0; i < L1.get_number_of_books_in_labrary(); i++)
    {
        cout <<  *(test_book_list_11+i) << " ";
    }
    cout << endl;*/

    //------------------------------------------借书测试------------------------------------------------------
    //------------------------------------------借书测试------------------------------------------------------
    //------------------------------------------借书测试------------------------------------------------------
    //------------------------------------------借书测试------------------------------------------------------
    //------------------------------------------借书测试------------------------------------------------------
    //------------------------------------------借书测试------------------------------------------------------
    //------------------------------------------借书测试------------------------------------------------------

    L1.Book_borrow(L1.bookNameSearch("假如给我三天光明"),U1);
    L1.Book_borrow(L1.bookNameSearch("软件工程1"),U1);
    L1.Book_borrow(L1.bookNameSearch("大卫科波菲尔"),U1);
    L1.Book_borrow(L1.bookNameSearch("西游记"),U1);
    L1.Book_borrow(L1.bookNameSearch("水浒传"),U1);
    //L1.Book_borrow(L1.bookNameSearch("假如给我三天光明6"),U1);
    //L1.Book_borrow(L1.bookNameSearch("假如给我三天光明7"),U1);
    

    //书数组
    printf("------------------用户-------------------\n");
    printf("用户书数组:\n");
    Book* test_book_list_12 = U1.return_book_list();
    int* test_book_flag = U1.return_book_flag();
    for (int i = 0; i < 5; i++)
    {
        cout <<  (test_book_list_12+i)->get_bookName() << "    " << test_book_flag[i] <<endl;  //借书测试 1  通过
    }


    cout << "用户现在有: " << U1.get_book_number() << endl;

    printf("--------------------------------------------------\n");

    L1.Book_return(L1.bookNameSearch("大卫科波菲尔"),U1);

        //书数组
    printf("------------------用户-------------------\n");
    printf("用户书数组:\n");
    Book* test_book_list_14 = U1.return_book_list();
    int* test_book_flag_1 = U1.return_book_flag();
    for (int i = 0; i < 5; i++)
    {
        if (test_book_flag_1[i] == 1)
        {
            cout <<  (test_book_list_14+i)->get_bookName() << setw(8) << test_book_flag_1[i] <<endl;  //借书测试 1  通过
        }
                
    }



    cout << "用户现在有: " << U1.get_book_number() << endl;
    

    

    return 0;
}
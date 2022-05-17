#include "Menu.h"

#include <iostream>
#include<string>
using namespace std;

Menu::Menu(){}

void Menu::interface(User new_user, Library new_Library)
{
    cout << "*********** Welcome to Library ************" << endl;
    cout << " 1.User login " << endl;
    cout << " 2.Librarian " << endl;
    cout << " input: ";

    //---------------------------------------------------------------------------------------------------
    
    string people;
    cin >> people;
    if(people == "1")
    {
            cout << " Welcome to user page " << endl;
            cout << " 1.borrow book " << endl;
            cout << " 2.return book " << endl;
            cout << " 3.find book by book name " << endl;
            cout << " 4.find book by book ID" << endl;
            cout << " 5.find book by author" << endl;
            cout << " 6.view books already borrowed" << endl;
            cout << " input your choose: ";
        string choose;
        cin >> choose;

   
        if(choose == "1")
        {
            string book;
            cout << "Enter the book name: ";
            cin >> book;
            new_Library.Book_borrow(new_Library.bookNameSearch(book),new_user);
        }
        else if(choose == "2")
        {
            string book;
            cout << "Enter the book name: " << endl;
            cin >> book;
            new_Library.Book_return(new_Library.bookNameSearch(book),new_user);
        }
        else if(choose == "3")
        {
            string book;
            cout << "Enter the book name: " << endl;
            cin >> book;
            new_Library.bookNameSearch(book);
        }
        else if(choose == "4")
        {
            string book;
            cout << "Enter the book ID: " << endl;
            cin >> book;        
            new_Library.bookIDSearch(book);
        }
        else if(choose == "5")
        {
            string book;
            cout << "Enter the author of the book: " << endl;
            cin >> book;        
            new_Library.authorSearch(book);
        }
        else if(choose == "6")
        {
            Book* test_book_list_14 = new_user.return_book_list();
            int* test_book_flag_1 = new_user.return_book_flag();
            for (int i = 0; i < new_user.get_book_number(); i++)
            {
                if (test_book_flag_1[i] == 1)
                {
                    cout <<  (test_book_list_14+i)->get_bookName() << "  " << test_book_flag_1[i] <<endl;
                }                       
            }
        }
        
    }

    //---------------------------------------------------------------------------------------------------

    else if(people == "2")
    {
        cout << "Welcome to Librarian page \n";
        cout << " 1.Add Book \n";
        cout << " 2.delete Book \n";

        string choose1;
        cin >> choose1;

        if (choose1 == "1")
        {            
            string bookName;
            string bookID;
            string bookAuthor;
            cout << "input the book name: ";
            cin >> bookName;

            cout << "input the book ID: ";
            cin >> bookID;

            cout << "input the book author: ";
            cin >> bookAuthor;

            Book new_book(bookName,bookID,bookAuthor);

            string number;
            cout << "input the number of book: ";
            cin >> number;   
            new_Library.addBook(new_book,stoi(number));         
        }
        else if(choose1 == "2")
        {
            string bookName;
            cout << "input the book name: ";
            cin >> bookName;

            string number;
            cout << "input the number of book: ";
            cin >> number;   


            int book_location = new_Library.book_location(new_Library.bookNameSearch(bookName)); 
            Book new_book = *(new_Library.All_books_list()+book_location);
            new_Library.delBook(new_book,stoi(number));
        }
    }

    //---------------------------------------------------------------------------------------------------

    else
    {
        cout << "wrong input" << endl;
    }
}



Menu::~Menu(){}
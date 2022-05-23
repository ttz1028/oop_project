#include "Menu.h"
#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

Menu::Menu(){}

//Main Interface
void Menu::interface(Student new_student,Staff new_staff,Library new_Library)
{
    cout << "----------------------------------" << endl; 
    cout << "*********** Welcome to Library ************" << endl;
    cout << " [1] Student" << endl;
    cout << " [2] Staff" << endl;
    cout << " [3] Librarian" << endl;
    cout << " [0] Exit library" << endl;
    cout << "----------------------------------" << endl; 
   
    bool flag = 0;
    while(flag != 1){
        cout << "Please enter the mode: ";
        string mode;
        cin >> mode;
        if(mode == "1")
        {
            Student_interface(new_student,new_staff,new_Library);
            flag = 1;
        }

        else if(mode == "2")
        {
            Staff_interface(new_student,new_staff,new_Library);
            flag = 1;
        }
        else if (mode == "3")
        {
            librarian_interface(new_student,new_staff,new_Library);
            flag = 1;
        }
        else if (mode == "0")
        {
            exit(0);
        }
        
        else
        {
            cout << "Invail input, please try again!" << endl;

        }
    }

}

//Student Interface
void Menu::Student_interface(Student new_student,Staff new_staff,Library new_Library){
    
    cout << "----------------------------------" << endl; 
    cout << " Welcome to Student page " << endl;
    cout << " [1] borrow book " << endl;
    cout << " [2] return book " << endl;
    cout << " [3] find book by book name " << endl;
    cout << " [4] find book by book ID" << endl;
    cout << " [5] view books already borrowed" << endl;
    cout << " [6] view total price" << endl;
    cout << " [7] view all books in library" << endl;
    cout << " [0] return to previous page" << endl;
    cout << "----------------------------------" << endl; 

 
    bool flag = 0;
    while(flag != 1){
        cout << "Please enter the mode: ";
        string mode;
        cin >> mode;
        if(mode == "1")
        {
            string bookID;
            cout << "Enter the book ID: ";
            cin >> bookID;
            new_Library.Student_Book_borrow(new_Library.bookIDSearch(bookID),new_student);
            flag = 1;
        }

        else if(mode == "2")
        {
            string bookID;
            cout << "Enter the book ID: " << endl;
            cin >> bookID;
            new_Library.Student_Book_return(new_Library.bookIDSearch(bookID),new_student); 
            flag = 1; 
        }
        else if(mode == "3")
        {
            string book;
            cout << "Enter the book name: " << endl;
            cin >> book;
            cout <<std::left<<setw(50)<<"Book Name"<<std::left<<setw(50)<<"ID"<< std::left<<setw(50)<<"Author" << endl;
            cout << std::left<<setw(50) << new_Library.bookNameSearch(book).get_bookName() << std::left<<setw(50)
            << new_Library.bookNameSearch(book).get_bookID() << std::left<<setw(50) << new_Library.bookNameSearch(book).get_author() << endl;
            flag = 1;
        }
        else if(mode == "4")
        {
            string book;
            cout << "Enter the book ID: " << endl;
            cin >> book;
            cout <<std::left<<setw(50)<<"Book Name"<<std::left<<setw(50)<<"ID"<< std::left<<setw(50)<<"Author" << endl;
            cout << std::left<<setw(50) << new_Library.bookIDSearch(book).get_bookName() << std::left<<setw(50)
            << new_Library.bookIDSearch(book).get_bookID() << std::left<<setw(50) << new_Library.bookIDSearch(book).get_author() << endl;            
            flag = 1;
        }
        else if(mode == "5")
        {
            test_book_list = new_student.return_book_list();
            test_book_flag = new_student.return_book_flag();
            for (int i = 0; i < 5; i++)
            {
                if (test_book_flag[i] == 1)
                {
                    cout <<  (test_book_list+i)->get_bookName() <<"      ID: " << (test_book_list+i)->get_bookID() << endl;
                } 
                                   
            }
            flag = 1;
        }
        else if(mode == "6"){
            cout << "The total price is: " << new_student.get_total_price() << endl;
            flag = 1;
        }    
        else if(mode == "7"){
            book_list = new_Library.All_books_list();
            book_number_list = new_Library.All_books_number_list();

            cout<<std::left<<setw(50)<<"Book Name"<<std::left<<setw(50)<<"ID"<< std::left<<setw(50)<<"Author"<< std::left<<setw(50)<<"Quantity"
            <<std::left<<setw(50)<<endl;

            for (int i = 0; i < new_Library.get_number_of_books_in_labrary(); i++)
            {
                cout << std::left<<setw(50)<< (book_list+i)->get_bookName() << std::left<<setw(50)<< (book_list+i)->get_bookID() <<std::left<<setw(50)<< 
                (book_list+i)->get_author() <<std::left<<setw(50) << *(book_number_list+i) << endl;                          
            }
            flag = 1;
        }    
        else if(mode == "0"){
            interface(new_student,new_staff,new_Library);
        }
        else
        {
            cout << "Invail input, please try again!" << endl;
        }
    }
    Student_interface(new_student,new_staff,new_Library);
}

//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================

//Staff_interface
void Menu::Staff_interface(Student new_student,Staff new_staff,Library new_Library){
    cout << "----------------------------------" << endl; 
    cout << " Welcome to Staff page " << endl;
    cout << " [1] borrow book " << endl;
    cout << " [2] return book " << endl;
    cout << " [3] find book by book name " << endl;
    cout << " [4] find book by book ID" << endl;
    cout << " [5] view books already borrowed" << endl;
    cout << " [6] view total price" << endl;
    cout << " [7] view all books in library" << endl;
    cout << " [0] return to previous page" << endl;
    cout << "----------------------------------" << endl; 


    bool flag = 0;
    while(flag != 1){
        cout << "Please enter the mode: ";
        string mode;
        cin >> mode;
        if(mode == "1")
        {
            string book;
            cout << "Enter the book ID: ";
            cin >> book;
            new_Library.Staff_Book_borrow(new_Library.bookIDSearch(book),new_staff);
            flag = 1;
        }

        else if(mode == "2")
        {
            string book;
            cout << "Enter the book ID: " << endl;
            cin >> book;
            new_Library.Staff_Book_return(new_Library.bookIDSearch(book),new_staff); 
            flag = 1; 
        }
        else if(mode == "3")
        {
            string book;
            cout << "Enter the book name: " << endl;
            cin >> book;
            cout <<std::left<<setw(50)<<"Book Name"<<std::left<<setw(50)<<"ID"<< std::left<<setw(50)<<"Author" << endl;
            cout << std::left<<setw(50) << new_Library.bookNameSearch(book).get_bookName() << std::left<<setw(50)
            << new_Library.bookNameSearch(book).get_bookID() << std::left<<setw(50) << new_Library.bookNameSearch(book).get_author() << endl;
            flag = 1;
        }
        else if(mode == "4")
        {
            string book;
            cout << "Enter the book ID: " << endl;
            cin >> book;
            cout <<std::left<<setw(50)<<"Book Name"<<std::left<<setw(50)<<"ID"<< std::left<<setw(50)<<"Author" << endl;
            cout << std::left<<setw(50) << new_Library.bookIDSearch(book).get_bookName() << std::left<<setw(50)
            << new_Library.bookIDSearch(book).get_bookID() << std::left<<setw(50) << new_Library.bookIDSearch(book).get_author() << endl;            
            flag = 1;
        }
        else if(mode == "5")
        {
            test_book_list = new_staff.return_book_list();
            test_book_flag = new_staff.return_book_flag();
            for (int i = 0; i < 5; i++)
            {
                if (test_book_flag[i] == 1)
                {
                    cout <<  (test_book_list+i)->get_bookName() <<"      ID: " << (test_book_list+i)->get_bookID() << endl;
                } 
                                
            }
            flag = 1;
        }
        else if(mode == "6"){
            cout << "The total price is: " << new_staff.get_total_price() << endl;
            flag = 1;
        }
        else if(mode == "7"){
            book_list = new_Library.All_books_list();
            book_number_list = new_Library.All_books_number_list();

            cout<<std::left<<setw(50)<<"Book Name"<<std::left<<setw(50)<<"ID"<< std::left<<setw(50)<<"Author"<< std::left<<setw(50)<<"Quantity"
            <<std::left<<setw(50)<<endl;

            for (int i = 0; i < new_Library.get_number_of_books_in_labrary(); i++)
            {
                cout << std::left<<setw(50)<< (book_list+i)->get_bookName() << std::left<<setw(50)<< (book_list+i)->get_bookID() <<std::left<<setw(50)<< 
                (book_list+i)->get_author() <<std::left<<setw(50) << *(book_number_list+i) << endl;                          
            }
            flag = 1;
        }         
        else if(mode == "0"){
            interface(new_student,new_staff,new_Library);
        }
        else
        {
            cout << "Invail input, please try again!" << endl;
        }
    }
    Staff_interface(new_student,new_staff,new_Library);
}


//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================
//=====================================================================================================================================


//librarian_interface
void Menu::librarian_interface(Student new_student,Staff new_staff,Library new_Library){
    cout << "----------------------------------" << endl; 
    cout << "Welcome to Librarian page \n";
    cout << " [1] add Book \n";
    cout << " [2] delete Book \n";
    cout << " [3] view all books in library" << endl;
    cout << " [0] return to previous page \n";
    cout << "----------------------------------" << endl; 

    bool flag = 0;
    while(flag != 1){
        cout << "Please enter the mode: ";
        string mode;
        cin >> mode;
        if(mode == "1")
        {
            string bookName;
            string bookID;
            string bookAuthor;

            //Ask user for input
            cout << "input the book name: ";
            cin >> bookName;

            cout << "input the book ID: ";
            cin >> bookID;

            cout << "input the book author: ";
            cin >> bookAuthor;

            Book new_book(bookName,bookID,bookAuthor);

            string number;
            cout << "input the number of book(max 10000): ";
            cin >> number;   

            bool flag2 = 0;
            while (flag2 != 1)
            {
                if (stoi(number) > 0 && stoi(number) < 10000)
                {
                    new_Library.addBook(new_book,stoi(number));
                    flag2 = 1;
                }
                else
                {
                    cout << "Invail input, please try again: ";
                    cin >> number;
                }
            }
            flag = 1;
        }

        else if(mode == "2")
        {
            string bookID;
            cout << "input the book ID: ";
            cin >> bookID;

            string number;
            cout << "input the number of book(max 10000): ";
            cin >> number;   

            bool flag2 = 0;
            while (flag2 != 1)
            {
                if (stoi(number) > 0 && stoi(number) < 10000)
                {
                    int book_location = new_Library.book_location(new_Library.bookIDSearch(bookID)); 
                    Book new_book = *(new_Library.All_books_list()+book_location);
                    new_Library.delBook(new_book,stoi(number));
                    flag2 = 1;
                }
                else
                {
                    cout << "Invail input, please try again: ";
                    cin >> number;
                }
            }
            flag = 1;

        }
        else if(mode == "3"){
            book_list = new_Library.All_books_list();
            book_number_list = new_Library.All_books_number_list();

            cout<<std::left<<setw(50)<<"Book Name"<<std::left<<setw(50)<<"ID"<< std::left<<setw(50)<<"Author"<< std::left<<setw(50)<<"Quantity"
            <<std::left<<setw(50)<<endl;

            for (int i = 0; i < new_Library.get_number_of_books_in_labrary(); i++)
            {
                cout << std::left<<setw(50)<< (book_list+i)->get_bookName() << std::left<<setw(50)<< (book_list+i)->get_bookID() <<std::left<<setw(50)<< 
                (book_list+i)->get_author() <<std::left<<setw(50) << *(book_number_list+i) << endl;                          
            }
            flag = 1;
        }    
        else if(mode == "0"){
            interface(new_student,new_staff,new_Library);
        }

        else
        {
            cout << "Invail input, please try again!" << endl;
        }
    }
    librarian_interface(new_student,new_staff,new_Library);
}



Menu::~Menu(){
    delete[] test_book_list;
    delete[] test_book_flag;
    delete[] book_list;
    delete[] book_number_list;
}
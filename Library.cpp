#include "Library.h"
#include <iostream>
#include <fstream>

using namespace std;

Library::Library(){
    m_Maximum_books_collection = 0;
    m_number_of_books_in_library = 0;
    m_Bookcase = nullptr;
    m_number_of_a_particular_book = nullptr; 
}

Library::Library(int Maximum_books_collection){
    m_Maximum_books_collection = Maximum_books_collection+1; // Preventing memory leaks
    m_number_of_books_in_library = 0;
    m_Bookcase = new Book[m_Maximum_books_collection];
    m_number_of_a_particular_book = new int[m_Maximum_books_collection];
    //Set all space to 0
    for (int i = 0; i < m_Maximum_books_collection; i++)
    {
        m_number_of_a_particular_book[i] = 0;
    }
}

Book Library::bookNameSearch(string BookName){
    Book cannot_find_this_book = Book();  //If you can't find the corresponding book, return a useless book and expand it in the interface!!
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

Book Library::bookIDSearch(string BookID){
    Book cannot_find_this_book = Book();  // If the corresponding book is not found, a useless book is returned and expanded in the interface!!!
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
    int location;
    for (int i = 0; i < m_number_of_books_in_library; i++)
    {
        if (new_book.get_bookID() == m_Bookcase[i].get_bookID()) //Positioning by ID comparison
        {
            location = i;
            return location; //Return to book index
        }        
    }
    //If not found, -1 is returned and an error is reported
    //cout << "(Library::book_location): Can't find this book" << endl;
    location = -2;
    return location;
}

void Library::addBook(Book new_book,int num_of_books){
    int flag = 0; // If the book already exists, the step of adding the book is not performed
    for (int i = 0; i < m_number_of_books_in_library; i++) //Look up from all the books
    {
        //Add the exact same book
        if (new_book.get_bookID() == m_Bookcase[i].get_bookID() && new_book.get_bookName() == m_Bookcase[i].get_bookName() && 
        new_book.get_author() == m_Bookcase[i].get_author())  //Find if the book to be added exists by ID & Name & Author
        {
            m_number_of_a_particular_book[i] = m_number_of_a_particular_book[i] + num_of_books; //If exist, add the corresponding number
            cout << new_book.get_bookName() << " already exist! | Now have: " << m_number_of_a_particular_book[i] << endl;
            flag = 1;
            break;
        }
        //If the book Name and ID do not match
        else if (new_book.get_bookID() == m_Bookcase[i].get_bookID() && new_book.get_bookName() != m_Bookcase[i].get_bookName() ||
                 new_book.get_bookID() != m_Bookcase[i].get_bookID() && new_book.get_bookName() == m_Bookcase[i].get_bookName())
        {
            cout << "Add Failed! | The book Name or ID you entered already exists and does not match!" << endl;
            flag = 1;
        }
                
    }

    if (flag == 0)
    {
        //Add new book and number of book, if not exist
        m_Bookcase[m_number_of_books_in_library] = new_book;  //add book
        m_number_of_a_particular_book[m_number_of_books_in_library] = num_of_books; //add number of book
        m_number_of_books_in_library++; //index++
        cout << "Added successfully!" << endl;
    }
    

    
}

bool Library::delBook(Book m_book,int num_of_books){
    for (int i = 0; i < m_number_of_books_in_library; i++)
    {
        if (m_book.get_bookID() == m_Bookcase[i].get_bookID())  //Find the book to delete by ID
        {
            //If the number of deletions exceeds the number in stock, the number in stock becomes 0
            if (num_of_books > m_number_of_a_particular_book[i])
            {
                m_number_of_a_particular_book[i] = 0;
                cout << "The number of deletions exceeded the number in stock and " << m_Bookcase[i].get_bookID() <<
                " has been all removed " << " | Now have: " <<  m_number_of_a_particular_book[i] << endl;  //Unit testing
                return true;
            }
            else{
                m_number_of_a_particular_book[i] = m_number_of_a_particular_book[i] - num_of_books;  //Delete the number of books if there are any, and return true
                cout << "Delete: " << m_Bookcase[i].get_bookID() << " | Now have: " <<  m_number_of_a_particular_book[i] << endl;  //Unit testing
                return true;
            }
            

        }        
    }
    //If not, an error is reported and false is returned
    cout << "The book is not in the library" << endl;
    return false;
    
}

bool Library::Student_Book_borrow(Book b_book, Student new_user){
    //Check whether the book is available
    if (m_number_of_a_particular_book[book_location(b_book)] > 0)
    {
        
        for (int i = 0; i < 5; i++)
        {
            if (*(new_user.return_book_flag()+i) == 0)  //Check if the user's array has available spaces
            {   
                *(new_user.return_book_list()+i) = b_book;    //Adds books to the user array 
                
                *(new_user.return_book_flag()+i) = 1; //Mark the location of an existing book as 1 (unavailable)
                
                m_number_of_a_particular_book[book_location(b_book)]--; //The library inventory of the book that was taken out decreased by 1
                cout << "Borrowed successfully | Book name is " << b_book.get_bookName() << endl;  //unit testing
                return true;
            }   
        } 
    }

    cout << "Failed" << endl;
    return false;
               
}
    

void Library::Student_Book_return(Book r_book, Student new_user){            
    bool flag = 0;
    int location = book_location(r_book);
    Book* book_list = new_user.return_book_list();
    for (int i = 0; i < 5; i++)
    {
        if((book_list+i)->get_bookName() == r_book.get_bookName() && (book_list+i)->get_bookID() == r_book.get_bookID()
            && new_user.get_book_number() > 0)
        {
            *(new_user.return_book_flag()+ new_user.user_book_location(r_book)) = 0;    //Marks the empty position of the user's comparison array as 0 (available)
            if (location > -1)
            {
                cout << "Returned successfully | Book name is " << r_book.get_bookName() << endl; //unit testing
                m_number_of_a_particular_book[location]++; //The number of returned books in the library increases by 1
            }
            
            flag = 1;
            break;
        }
    } 
    if (flag == 0)
    {
        cout << "You don't have this book !" << endl;
    }
      
}


//------------------------------------------

bool Library::Staff_Book_borrow(Book b_book, Staff new_user){
    //Check whether the book is available
    if (m_number_of_a_particular_book[book_location(b_book)] > 0)
    {
        
        for (int i = 0; i < 5; i++)
        {
            if (*(new_user.return_book_flag()+i) == 0)  //Check if the user's array has available spaces
            {   
                *(new_user.return_book_list()+i) = b_book;    //Adds books to the user array 
                
                *(new_user.return_book_flag()+i) = 1; //Mark the location of an existing book as 1 (unavailable)
                
                m_number_of_a_particular_book[book_location(b_book)]--; //The library inventory of the book that was taken out decreased by 1
                cout << "Borrowed successfully | Book name is " << b_book.get_bookName() << endl;  //unit testing
                return true;
            }   
        } 
    }

    cout << "Failed" << endl;
    return false;
               
}
    

void Library::Staff_Book_return(Book r_book, Staff new_user){            
    bool flag = 0;
    int location = book_location(r_book);
    Book* book_list = new_user.return_book_list();
    for (int i = 0; i < 5; i++)
    {
        if((book_list+i)->get_bookName() == r_book.get_bookName() && (book_list+i)->get_bookID() == r_book.get_bookID()
            && new_user.get_book_number() > 0)
        {
            *(new_user.return_book_flag()+ new_user.user_book_location(r_book)) = 0;    //Marks the empty position of the user's comparison array as 0 (available)
            if (location > -1)
            {
                cout << "Returned successfully | Book name is " << r_book.get_bookName() << endl; //unit testing
                m_number_of_a_particular_book[location]++; //The number of returned books in the library increases by 1
            }
            
            flag = 1;
            break;
        }
    } 
    if (flag == 0)
    {
        cout << "You don't have this book !" << endl;
    }
      
}


Book* Library::All_books_list(){
    return m_Bookcase;
}

int* Library::All_books_number_list(){
    return m_number_of_a_particular_book;
}

void Library::read_book_record(string filename)
{
    ifstream Book_record;
    Book_record.open(filename);
 
    string book_name; string book_ID; string book_author; int book_num;

    int total_books;  
    int i = m_number_of_books_in_library; //Records the index at the end of the book array 
    int flag = 0;    
    while (flag != 1)
    {
        Book_record >> book_name >> book_ID >>  book_author >> book_num;

        int flag2 = 0; // If the book already exists, the add book step is not performed
        for (int i = 0; i < m_number_of_books_in_library; i++) //Look it up in all the books
        {
            if (book_ID == m_Bookcase[i].get_bookID())  //Verify the existence of the added book by ID
            {
                m_number_of_a_particular_book[i] = m_number_of_a_particular_book[i] + book_num; //If yes, add the corresponding quantity
                flag2 = 1;               
            }             
        }

        if (flag2 == 0)
        {
            m_Bookcase[i].set_bookName(book_name);
            //Set the line after the last book to Reading_done to figure out how many books have been imported
            if (m_Bookcase[i].get_bookName() == "Reading_Done") 
            {
                total_books = i;
                flag = 1;
            }        
            m_Bookcase[i].set_bookID(book_ID);
            m_Bookcase[i].set_author(book_author);
            m_number_of_a_particular_book[i] = book_num;     
            i++;
        }

        m_Bookcase[i].set_bookName(book_name);
        //Set the line after the last book to Reading_done to figure out how many books have been imported
        if (m_Bookcase[i].get_bookName() == "Reading_Done")  
        {
            total_books = i;
            flag = 1;
        }    

           
    }
  
    if (total_books < m_Maximum_books_collection)
    {
        m_number_of_books_in_library = total_books-1;  //Set library index to an empty space after the last book
    }
        
}

int Library::get_number_of_books_in_labrary(){    //Returns the number of books available in the library
    return m_number_of_books_in_library;
}
    

Library::~Library(){
    delete[] m_Bookcase;
    delete[] m_number_of_a_particular_book;
}



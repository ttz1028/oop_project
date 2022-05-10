#include "Librarian.h"


Librarian::Librarian(){
    m_StaffUsername = "";
    m_StaffPassword = "";
}

Librarian::Librarian(string StaffUsername,string StaffPassword){
    m_StaffUsername = StaffUsername;
    m_StaffPassword = StaffPassword;
}

void Librarian::checkAll(){}       

void Librarian::view_user_return_date(User username){}

Librarian::~Librarian(){}
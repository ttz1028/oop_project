#include "Abs_user.h"
#include<iostream>
#include<string>

using namespace std;


Abs_user::Abs_user(){}

void Abs_user::set_username(string new_username){
    username = new_username;
}

void Abs_user::set_password(string new_password){
    password = new_password;
}

Abs_user::~Abs_user(){}
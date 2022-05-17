#ifndef ABS_USER_H
#define ABS_USER_H
#include<iostream>
#include<string>

using namespace std;

//Abs_user is an abstract class
class Abs_user{
protected:
    string username;
    string password;
public:
    Abs_user();
    virtual string get_username() = 0;
    virtual string get_password() = 0;
    void set_username(string new_username);
    void set_password(string new_password);
    ~Abs_user();
};

#endif
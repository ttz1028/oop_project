#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"
#include<string>

class Student: public User{
private:
    double book_price;
public:
    Student();

    double get_total_price(); // get total price for student

    ~Student();

};

#endif
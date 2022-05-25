#ifndef STAFF_H
#define STAFF_H
#include "User.h"

class Staff: public User{
private:
    double book_price;
public:
    Staff();

    double get_total_price(); // get total price for staff  
    
    ~Staff();
};

#endif
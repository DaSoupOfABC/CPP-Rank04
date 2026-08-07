#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // 1. Default Constructor -> needed since if we only have a copy constructor, there is no "default"
    Fixed();

    // 2. Copy Constructor
    Fixed(const Fixed& other); //& symbol here means to give an alias instead of the orignal object. Basically MUST NOT be a copy of the object, but a reference to the original object. 
                               // This is important because if we pass by value, it will call the copy constructor again, leading to infinite recursion. 

    // 3. Copy Assignment Operator
    Fixed& operator=(const Fixed& other);

    // 4. Destructor
    ~Fixed();

    // Member functions required by ex00
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif

// We can explain why the OCF is important here. Let's say we have a class with a pointer, and we copy it.
// Now, class A and class B both have a pointer to the same memory location. If we call the destructor, 
// both of them will try to free the same memory, which will lead to a double free error.
// By implementing the OCF, we can ensure that when we copy an object, we create a new copy of the data in memory. 
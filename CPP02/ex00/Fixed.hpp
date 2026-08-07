#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // 1. Default Constructor
    Fixed();

    // 2. Copy Constructor
    Fixed(const Fixed& other);

    // 3. Copy Assignment Operator
    Fixed& operator=(const Fixed& other);

    // 4. Destructor
    ~Fixed();

    // Member functions required by ex00
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
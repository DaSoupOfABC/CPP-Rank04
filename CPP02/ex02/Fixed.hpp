#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // OCF Functions
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // Member functions
    int   getRawBits(void) const;
    void  setRawBits(int const raw);
    float toFloat(void) const;
    int   toInt(void) const;

    // Comparison Operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    // We need const here as we don't want to modify the object here.

    // Arithmetic Operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    // When doing operation, we convert to float, multiply, then pass to Fixed(float) to apply 2^8
    // To prevent overflow, we use float instead of int, especially after converting to 2^n. 

    // Increment / Decrement Operators (adds the smallest possible value, which is 1/256 = 0.00390625)
    Fixed& operator++(void);       // Pre-increment 
    Fixed  operator++(int);        // Post-increment
    Fixed& operator--(void);       // Pre-decrement
    Fixed  operator--(int);        // Post-decrement
    //Pre-increment and pre-decrement return a reference to the modified object
    //Post-increment and post-decrement return a copy of the object before it was modified

    // Min / Max Static Overloads
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    // These are static so that it can be called without needing an instance, such as (Fixed::max(a, b))
    // We have both const and non-const versions so that it can be used with both const and non-const Fixed objects.
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& o, const Fixed& i);

#endif
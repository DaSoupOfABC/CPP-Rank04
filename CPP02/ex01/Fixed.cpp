#include "Fixed.hpp"

// 1. Default Constructor
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// 1.1 New ex01 Constructor for int
Fixed::Fixed(const int n) : _value(n << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// 1.2 New ex01 Constructor for float
Fixed::Fixed(const float n) : _value(roundf(n * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

// 2. Copy Constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // Give copying logic to the operator =
}

// 3. Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) { // Protect against self-assignment, eg(a = a)
        this->_value = other.getRawBits();
    }
    return *this; // Return reference to allow chained (eg a = b = c)
}

// 4. Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


// 5. Functions
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << _fractionalBits);
}

// Convert Fixed-Point to Int: Shift right by 8 bits
int Fixed::toInt(void) const {
    return this->_value >> _fractionalBits;
}

// Stream insertion operator: to insert float representation of Fixed into output stream
std::ostream& operator<<(std::ostream& o, const Fixed& i) {
    o << i.toFloat();
    return o;
}


// For conversion, we take the binary number, and shift it right by 8 times (2 ^ 8 = 256), since it's esstablished
// that the decimal point is 8 from the left. We multiply by 256 to convert to float, and divide by 256 to convert to int.
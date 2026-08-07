#include "Fixed.hpp"

// Constructors & Destructor
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) : _value(n << _fractionalBits) {}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

// Member Functions
int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_value >> _fractionalBits;
}

// Comparison Operators
bool Fixed::operator>(const Fixed& other) const { return this->_value > other._value; }
bool Fixed::operator<(const Fixed& other) const { return this->_value < other._value; }
bool Fixed::operator>=(const Fixed& other) const { return this->_value >= other._value; }
bool Fixed::operator<=(const Fixed& other) const { return this->_value <= other._value; }
bool Fixed::operator==(const Fixed& other) const { return this->_value == other._value; }
bool Fixed::operator!=(const Fixed& other) const { return this->_value != other._value; }

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement Operators
Fixed& Fixed::operator++(void) {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_value++;
    return temp;
}

Fixed& Fixed::operator--(void) {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_value--;
    return temp;
}

// Min / Max Static Overloads
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Stream insertion
std::ostream& operator<<(std::ostream& o, const Fixed& i) {
    o << i.toFloat();
    return o;
}
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(a);   // Call Copy Constructor
    Fixed c;
    c = b;        // Call Copy Assignment Operator (Allows existing object to be assigned to another existing object)

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
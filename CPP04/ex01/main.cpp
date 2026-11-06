#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Array of Animals Test ===" << std::endl;
    const int count = 4;
    Animal* animals[count];

    for (int i = 0; i < count / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = count / 2; i < count; i++) {
        animals[i] = new Cat();
    }

    // Clean up to make sure virtual destructor prevent leaks
    for (int i = 0; i < count; i++) {
        delete animals[i];
    }

    std::cout << "\n=== Deep Copy Verification Test ===" << std::endl;
    Dog basic;
    basic.setIdea(0, "I want to chase a ball!");

    Dog tmp = basic; // Copy constructor
    std::cout << "basic's idea: " << basic.getIdea(0) << std::endl;
    std::cout << "tmp's idea:   " << tmp.getIdea(0) << std::endl;

    // Modify the copy's idea
    tmp.setIdea(0, "I want to sleep!");
    std::cout << "\nAfter modifying tmp:" << std::endl;
    std::cout << "basic's idea (should NOT change): " << basic.getIdea(0) << std::endl;
    std::cout << "tmp's idea:                       " << tmp.getIdea(0) << std::endl;

    return 0;
}
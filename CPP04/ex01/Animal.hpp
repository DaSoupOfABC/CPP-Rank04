#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal(); // Virtual destructor here, not normal to make sure that dereived classes are also destroyed

    virtual void makeSound() const; // Dynamic dispatch to allow derived classes to override this method
    std::string getType() const;
};

#endif
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain(); // Allocate brain
    std::cout << "Dog default constructor called" << std::endl;
}

// Deep copy in Copy Constructor
Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain); // Allocate a NEW Brain and copy content
}

// Deep copy in Assignment Operator
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;                    // 1. Delete existing brain to avoid leaks
        this->brain = new Brain(*other.brain); // 2. Allocate new brain and copy
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain; // Clean up heap memory
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return this->brain->getIdea(index);
}
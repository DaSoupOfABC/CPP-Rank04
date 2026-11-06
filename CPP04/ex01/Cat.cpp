#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain(); // Allocate brain
    std::cout << "Cat default constructor called" << std::endl;
}

// Deep copy in Copy Constructor
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain); // Allocate a NEW Brain and copy content
}

// Deep copy in Assignment Operator
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;                    // 1. Delete existing brain to avoid leaks
        this->brain = new Brain(*other.brain); // 2. Allocate new brain and copy
    }
    return *this;
}

Cat::~Cat() {
    delete this->brain; // Clean up heap memory
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return this->brain->getIdea(index);
}
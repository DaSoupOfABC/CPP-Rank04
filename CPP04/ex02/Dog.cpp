#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain); // Deep copy
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain); // Deep copy
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;
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
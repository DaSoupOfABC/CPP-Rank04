#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain); // Deep copy
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain); // Deep copy
    }
    return *this;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return this->brain->getIdea(index);
}
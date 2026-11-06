#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Correct Polymorphism Test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // Meow
    j->makeSound(); // Woof 
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Wrong Polymorphism Test ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;

    wrongCat->makeSound(); // Will output the WRONGANIMAL sound because no virtual
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat; // WrongCat destructor will NOT run!

    return 0;
}
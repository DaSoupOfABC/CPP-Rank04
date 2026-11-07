#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // 1. Uncommenting this line will cause a compilation error:
    // const AAnimal* meta = new AAnimal(); 
    // Error: cannot allocate an object of abstract type 'AAnimal'

    std::cout << "=== Testing Concrete Derived Instantiation ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    std::cout << "\n=== Testing Deep Copy Still Works ===" << std::endl;
    Dog original;
    original.setIdea(0, "Chase squirrel");

    Dog copy = original;
    copy.setIdea(0, "Sleep on sofa");

    std::cout << "Original idea: " << original.getIdea(0) << std::endl;
    std::cout << "Copy idea:     " << copy.getIdea(0) << std::endl;

    return 0;
}

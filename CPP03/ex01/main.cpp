#include "ScavTrap.hpp"

int main() {
    std::cout << "=== Constructing ===" << std::endl;
    ScavTrap serena("Serena");

    std::cout << "\n=== Actions ===" << std::endl;
    serena.attack("Skag");
    serena.takeDamage(30);
    serena.beRepaired(15);
    serena.guardGate();

    std::cout << "\n=== Destructing ===" << std::endl;
    return 0;
}
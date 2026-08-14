#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== Creating FragTrap ===" << std::endl;
    FragTrap frag("Fraggy");

    std::cout << "\n=== Actions ===" << std::endl;
    frag.attack("Target Dummy");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}
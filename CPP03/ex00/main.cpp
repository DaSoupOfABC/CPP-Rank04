#include "ClapTrap.hpp"

int main() {
    ClapTrap clippy("Clippy");

    clippy.attack("Bandit");
    clippy.takeDamage(5);
    clippy.beRepaired(3);
    clippy.takeDamage(10);
    clippy.attack("Bandit"); //(0 HP)

    return 0;
}
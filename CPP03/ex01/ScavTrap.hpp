#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap { // means that ScavTrap is a derived class of ClapTrap.
//We need the ClapTrap class to be "created" before we can create the ScavTrap class so that it can inherit.
public:
    // OCF
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    // Overridden attack member function (uses it's own version of attack)
    void attack(const std::string& target);

    // Special member function
    void guardGate();
};

#endif
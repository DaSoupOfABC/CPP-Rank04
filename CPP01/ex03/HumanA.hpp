#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
private:
    std::string _name;
    Weapon&     _weapon; // Reference: Guaranteed to exist!

public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();

    void attack(void) const;
};

#endif
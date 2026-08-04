#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string _type;

public:
    Weapon(std::string type);
    ~Weapon();

    // Returns a const reference so getType doesn't copy the string
    const std::string& getType(void) const;
    void setType(std::string newType);
};

#endif
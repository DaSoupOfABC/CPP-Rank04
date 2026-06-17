#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

    std::string _getInput(std::string prompt) const;

public:
    Contact();
    ~Contact();

    bool        setInformation();
    
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    
    void        displayFullContact() const;
};

#endif
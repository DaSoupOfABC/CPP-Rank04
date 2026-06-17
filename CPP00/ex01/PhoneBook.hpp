#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8]; 
    int     _index;       
    int     _total;       

public:
    PhoneBook();
    ~PhoneBook();

    void    addContact();
    void    searchContacts() const;
};

#endif
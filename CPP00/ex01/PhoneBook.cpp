#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip> 
#include <cstdlib> 

PhoneBook::PhoneBook() {
    this->_index = 0;
    this->_total = 0;
}

PhoneBook::~PhoneBook() {}

std::string formatColumn(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::addContact() {
    int targetIndex = this->_index % 8;

    std::cout << "\n--- Creating New Contact ---" << std::endl;
    
    if (this->_contacts[targetIndex].setInformation()) {
        this->_index++;
        if (this->_total < 8) {
            this->_total++;
        }
        std::cout << "Success: Contact saved!" << std::endl;
    } else {
        std::cout << "\nOperation aborted." << std::endl;
    }
}

void PhoneBook::searchContacts() const {
    if (this->_total == 0) {
        std::cout << "The phonebook is currently empty." << std::endl;
        return;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < this->_total; i++) {
        std::cout << "|" << std::setw(10) << i << "|"
                  << std::setw(10) << formatColumn(this->_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatColumn(this->_contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatColumn(this->_contacts[i].getNickname()) << "|" 
                  << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;

    std::string input;
    std::cout << "Enter the index of the contact to view: ";
    
    if (!std::getline(std::cin, input)) {
        return; 
    }

    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
        int target = input[0] - '0'; 
        
        if (target < this->_total) {
            this->_contacts[target].displayFullContact();
        } else {
            std::cout << "Error: Contact at index " << target << " does not exist yet." << std::endl;
        }
    } else {
        std::cout << "Error: Invalid index. Please enter a number between 0 and " << (this->_total - 1) << "." << std::endl;
    }
}
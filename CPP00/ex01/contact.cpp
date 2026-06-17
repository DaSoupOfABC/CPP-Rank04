#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::_getInput(std::string prompt) const {
    std::string input = "";
    
    while (input.empty()) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            return ""; // EOF detected
        }
        if (input.empty()) {
            std::cout << "Error: Field cannot be empty. Please try again." << std::endl;
        }
    }
    return input;
}

bool Contact::setInformation() {
    this->_firstName = _getInput("Enter First Name: ");
    if (this->_firstName.empty()) return false;

    this->_lastName = _getInput("Enter Last Name: ");
    if (this->_lastName.empty()) return false;

    this->_nickname = _getInput("Enter Nickname: ");
    if (this->_nickname.empty()) return false;

    this->_phoneNumber = _getInput("Enter Phone Number: ");
    if (this->_phoneNumber.empty()) return false;

    this->_darkestSecret = _getInput("Enter Darkest Secret: ");
    if (this->_darkestSecret.empty()) return false;

    return true; 
}

std::string Contact::getFirstName() const { return this->_firstName; }
std::string Contact::getLastName() const { return this->_lastName; }
std::string Contact::getNickname() const { return this->_nickname; }

void Contact::displayFullContact() const {
    std::cout << "\n--- Contact Details ---" << std::endl;
    std::cout << "First Name     : " << this->_firstName << std::endl;
    std::cout << "Last Name      : " << this->_lastName << std::endl;
    std::cout << "Nickname       : " << this->_nickname << std::endl;
    std::cout << "Phone Number   : " << this->_phoneNumber << std::endl;
    std::cout << "Darkest Secret : " << this->_darkestSecret << std::endl;
    std::cout << "-----------------------" << std::endl;
}
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to the My Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

    while (true) {
        std::cout << "\n> ";
        
        if (!std::getline(std::cin, command)) {
            std::cout << "\n[EOF detected] Exiting PhoneBook..." << std::endl;
            break;
        }

        if (command == "ADD") {
            phoneBook.addContact();
        } 
        else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } 
        else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } 
        else if (!command.empty()) {
            std::cout << "Error: Invalid command. Use ADD, SEARCH, or EXIT." << std::endl;
        }
    }

    return 0;
}
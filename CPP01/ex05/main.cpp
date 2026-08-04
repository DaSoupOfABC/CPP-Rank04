#include "harl.hpp"

int main() {
    Harl harl;

    std::cout << "--- Testing Valid Log Levels ---" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;

    harl.complain("INFO");
    std::cout << std::endl;

    harl.complain("WARNING");
    std::cout << std::endl;

    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "--- Testing Unmatched Level ---" << std::endl;
    harl.complain("INVALID_LEVEL"); // Silent ignore or unhandled case

    return 0;
}
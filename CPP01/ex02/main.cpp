/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@studekl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:54:37 by jenlee            #+#    #+#             */
/*   Updated: 2026/08/03 21:54:37 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
    // 1. A string variable initialized to "HI THIS IS BRAIN"
    std::string str = "HI THIS IS BRAIN";

    // 2. stringPTR: a pointer to the string
    std::string* stringPTR = &str;

    // 3. stringREF: a reference to the string
    std::string& stringREF = str;

    // --- Printing Memory Addresses ---
    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR:    " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:    " << &stringREF << std::endl;

    std::cout << std::endl;

    // --- Printing Values ---
    std::cout << "Value of the string variable:  " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}

// A way to understand pointer vs reference is with an analogy
// A variable is a house, while a pointer is a blank piece of paper with an adress to that house
//     The paper can be blank (NULL), and the adress can be erased and changed
// A reference is an alias. I can call the house "the crib", and it will still point towards the same house
//     I cannot give a nickname to something that doesn't exist, therefore NULL reference cannot exist
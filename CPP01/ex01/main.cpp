/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@studekl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:39:43 by jenlee            #+#    #+#             */
/*   Updated: 2026/08/03 21:39:43 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int hordeSize = 5;

    std::cout << "--- Allocating a horde of " << hordeSize << " zombies ---" << std::endl;
    // Call the horde allocation function
    Zombie* horde = zombieHorde(hordeSize, "Chomper");

    if (horde == NULL) {
        std::cout << "Error: Failed to create horde." << std::endl;
        return 1;
    }

    std::cout << "\n--- Making all zombies in the horde announce themselves ---" << std::endl;
    for (int i = 0; i < hordeSize; i++) {
        std::cout << "[Zombie #" << i << "] ";
        horde[i].announce(); // Loop through the array
    }

    std::cout << "\n--- Deallocating the entire horde using delete[] ---" << std::endl;
    // Using delete[] ensures ALL destructors run
    delete[] horde;

    std::cout << "\nHorde successfully wiped out. Program exiting cleanly." << std::endl;
    return 0;
}
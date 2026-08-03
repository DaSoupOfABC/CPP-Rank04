/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@studekl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:13:55 by jenlee            #+#    #+#             */
/*   Updated: 2026/08/03 21:13:55 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << "--- Creating a Stack Zombie via randomChump ---" << std::endl;
    randomChump("StackChump");
    // Stack zombie dies immediately after

    std::cout << "--- Creating a Heap Zombie via newZombie ---" << std::endl;
    Zombie* heapZombie = newZombie("HeapFiend");
    
    std::cout << "Calling announce from main:" << std::endl;
    heapZombie->announce();

    std::cout << "\n--- Manually destroying the Heap Zombie ---" << std::endl;
    delete heapZombie; // Destructor called manually here
    // Heap must be manually deleted
    
    std::cout << "Program exiting cleanly." << std::endl;
    return 0;
}

// STack is often used for fast and automatic allocation of local variables,
// while heap is used for more flexible, dynamic memory allocation, or when 
// data is meant to be long lived
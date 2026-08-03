/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@studekl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:13:15 by jenlee            #+#    #+#             */
/*   Updated: 2026/08/03 21:13:15 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor: required so 'new Zombie[N]' can allocate the array
Zombie::Zombie() : _name("Unnamed") {}

// Destructor: prints destruction log so confirm all array elements are freed
Zombie::~Zombie() {
    std::cout << this->_name << ": has been destroyed." << std::endl;
}

// Setter: called after array allocation to assign names to each zombie
void Zombie::setName(std::string name) {
    this->_name = name;
}

// Member function: prints the required announcement message
void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
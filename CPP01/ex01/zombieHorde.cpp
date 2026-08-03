/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@studekl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:33:27 by jenlee            #+#    #+#             */
/*   Updated: 2026/08/03 21:33:27 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) return NULL;

    // 1. Allocate N zombies in a SINGLE allocation
    Zombie* horde = new Zombie[N];

    // 2. Initialize each zombie's name
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }

    // 3. Return the pointer to the first zombie 
    return horde;
}
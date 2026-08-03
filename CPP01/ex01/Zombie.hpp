/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@studekl.edu.my>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:20:20 by jenlee            #+#    #+#             */
/*   Updated: 2026/08/03 21:20:20 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;

public:
    Zombie();                  // Required for array allocation
    ~Zombie();
    
    void    setName(std::string name); // Setter to fix the name later
    void    announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:27:56 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 20:31:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string const name) {
	Zombie* zombies;

	zombies = new Zombie[n];
	for (int i = 0; i < n; i++) {
		zombies[i].setZombieName(name);
	}
	return (zombies);
}

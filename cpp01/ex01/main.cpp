/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:24:57 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 21:08:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie*	zombies;
	int		n = 42;

	zombies = zombieHorde(n, "Harry Potter");
	std::cout << "Total zombies: " << Zombie::totalZombies << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << ORANGE << "Zombie number " << i + 1 << ": " << RESET;
		zombies[i].announce();
	}
	delete [] zombies;
	std::cout << "Total zombies: " << Zombie::totalZombies << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/28 09:14:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void	description(const std::string& text) {
	std::cout << std::endl
			<< LIGHT_PURPLE << text << RESET << std::endl;
}

int main(void) {
	description("Constructors messages");
	ClapTrap robot1;
	ClapTrap robot2;
	ClapTrap marvin("Marvin");
	ClapTrap marvinCopy = marvin;
	ClapTrap marvinCopy2(marvin);

	description("Testing functions");
	robot1.attack(marvin.getName());
	marvin.takeDamage(robot1.getAttackDamage());
	marvin.beRepaired(5);

	description("Testing instance copy");
	robot2.attack(marvinCopy.getName());
	marvinCopy.takeDamage(robot1.getAttackDamage());
	marvinCopy.beRepaired(10);

	description("Testing negative values");
	marvinCopy.beRepaired(-10);
	marvinCopy.takeDamage(-20);

	description("Testing energy <= 0");
	robot1.setEnergyPoints(0);
	robot1.attack(marvinCopy2.getName());
	robot1.beRepaired(1);

	description("Testing hit points <= 0");
	robot2.takeDamage(20);
	robot2.attack(marvin.getName());
	robot2.beRepaired(1);

	description("Destructors messages");
	return (0);
}

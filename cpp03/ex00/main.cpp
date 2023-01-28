/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/28 08:23:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	std::cout << std::endl
			<< LIGHT_PURPLE << "Constructors messages" << RESET << std::endl;
	ClapTrap robot1;
	ClapTrap robot2;
	ClapTrap marvin("Marvin");
	ClapTrap marvinCopy = marvin;
	ClapTrap marvinCopy2(marvin);

	std::cout << std::endl
			<< LIGHT_PURPLE << "Testing functions" << RESET << std::endl;
	robot1.attack(marvin.getName());
	marvin.takeDamage(robot1.getAttackDamage());
	marvin.beRepaired(5);

	std::cout << std::endl
			<< LIGHT_PURPLE << "Testing instance copy" << RESET << std::endl;
	robot2.attack(marvinCopy.getName());
	marvinCopy.takeDamage(robot1.getAttackDamage());
	marvinCopy.beRepaired(10);

	std::cout << std::endl
			<< LIGHT_PURPLE << "Testing negative values" << RESET << std::endl;
	marvinCopy.beRepaired(-10);
	marvinCopy.takeDamage(-20);

	std::cout << std::endl
			<< LIGHT_PURPLE << "Testing energy <= 0" << RESET << std::endl;
	robot1.setEnergyPoints(0);
	robot1.attack(marvinCopy2.getName());
	robot1.beRepaired(1);

	std::cout << std::endl
			<< LIGHT_PURPLE << "Testing hit points <= 0" << RESET << std::endl;
	robot2.takeDamage(20);
	robot2.attack(marvin.getName());
	robot2.beRepaired(1);

	std::cout << std::endl
			<< LIGHT_PURPLE << "Destructors messages" << RESET << std::endl;
	return (0);
}

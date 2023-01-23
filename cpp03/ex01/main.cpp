/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/23 17:57:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	std::cout << std::endl;
	std::cout << LIGHT_PURPLE 
			<< "------------------------- Tests ex00 -------------------------" 
			<< std::endl;
	ClapTrap robot1;
	ClapTrap robot2;
	ClapTrap marvin("Marvin");
	ClapTrap marvinCopy = marvin;
	ClapTrap marvinCopy2(marvin);

	std::cout << std::endl;
	robot1.attack(marvin.getName());
	marvin.takeDamage(robot1.getAttackDamage());
	marvin.beRepaired(1);
	marvin.beRepaired(5);

	std::cout << std::endl;
	robot2.attack(marvinCopy.getName());
	marvinCopy.takeDamage(robot1.getAttackDamage());
	marvinCopy.beRepaired(10);

	std::cout << std::endl;
	while (robot1.getEnergyPoints()) {
		robot1.setEnergyPoints(robot1.getEnergyPoints() - 1);
	}
	robot1.attack(marvinCopy2.getName());
	robot1.beRepaired(1);

	std::cout << std::endl;
	while (robot2.getHitPoints()) {
		robot2.takeDamage(10);
	}
	robot2.attack(marvin.getName());
	robot2.beRepaired(1);

	std::cout << std::endl;

	std::cout << LIGHT_PURPLE 
			<< "------------------------- Tests ex01 -------------------------" 
			<< std::endl;
	ScavTrap sentinel;
	ScavTrap sentinel2;
	ScavTrap sentinelCopy(sentinel);
	ScavTrap ultron("Ultron");

	std::cout << std::endl;
	ultron.attack(marvin.getName());
	marvin.takeDamage(ultron.getAttackDamage());
	
	std::cout << std::endl;
	sentinel2.attack(sentinelCopy.getName());
	sentinelCopy.takeDamage(sentinel2.getAttackDamage());
	sentinelCopy.beRepaired(10);

	std::cout << std::endl;
	sentinel.guardGate();
	
	std::cout << std::endl;
	return (0);
}

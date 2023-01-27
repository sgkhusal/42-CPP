/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/26 23:59:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void	tests_ex00(void) {
	std::cout << std::endl;
	std::cout << LIGHT_PURPLE
			<< "------------------------- Tests ex00 -------------------------"
			<< std::endl << std::endl;

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
	robot1.setEnergyPoints(0);
	robot1.attack(marvinCopy2.getName());
	robot1.beRepaired(1);

	std::cout << std::endl;
	robot2.takeDamage(20);
	robot2.attack(marvin.getName());
	robot2.beRepaired(1);

	std::cout << std::endl;
}

int main(int argc, char *argv[]) {

	if (argc > 1) {
		std::string mode = argv[1];
		if (mode.compare("all") == 0) {
			tests_ex00();
		}
	}

	std::cout << std::endl;
	std::cout << LIGHT_PURPLE
			<< "------------------------- Tests ex01 -------------------------"
			<< std::endl << std::endl;

	ScavTrap sentinel;
	ScavTrap sentinel2;
	ScavTrap sentinelCopy(sentinel);
	ScavTrap ultron("Ultron");

	std::cout << std::endl;
	ultron.attack(sentinel.getName());
	sentinel.takeDamage(ultron.getAttackDamage());

	std::cout << std::endl;
	sentinel2.attack(sentinelCopy.getName());
	sentinelCopy.takeDamage(sentinel2.getAttackDamage());
	sentinelCopy.beRepaired(10);

	std::cout << std::endl;
	sentinel.guardGate();
	sentinel.setEnergyPoints(0);
	sentinel.setHitPoints(0);
	sentinel.guardGate();

	std::cout << std::endl;
	return (0);
}

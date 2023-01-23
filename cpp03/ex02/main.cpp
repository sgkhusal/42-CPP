/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/23 19:39:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	std::cout << LIGHT_PURPLE 
			<< "------------------------- Tests ex02 -------------------------" 
			<< std::endl;

	FragTrap droid1;
	FragTrap droid2;
	FragTrap cp3po("CP3PO");
	FragTrap r2d2("R2-D2");
	FragTrap bb8("BB-8");
	FragTrap bb8_clone(bb8);

	std::cout << std::endl;
	bb8.highFiveGuys();
	bb8.beRepaired(10);
	cp3po.highFiveGuys();
	
	std::cout << std::endl;
	ultron.attack(droid1.getName());
	droid1.takeDamage(ultron.getAttackDamage());
	
	std::cout << std::endl;
	r2d2.attack(bb8_clone.getName()); // não está atualizando o valor do ataque??
	bb8_clone.takeDamage(r2d2.getAttackDamage());

	std::cout << std::endl;
	return (0);
}

// precisa incluir testes da diminuição de energia
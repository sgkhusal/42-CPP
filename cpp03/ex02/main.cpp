/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/28 09:39:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void	description(const std::string& text) {
	std::cout << std::endl
			<< LIGHT_PURPLE << text << RESET << std::endl;
}

static void	tests_ex00(void) {
	description("------------------------- Tests ex00 -------------------------");

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
}

static void	tests_ex01(void) {
	description("------------------------- Tests ex01 -------------------------");

	description("Constructors messages");
	ScavTrap sentinel;
	ScavTrap sentinel2;
	ScavTrap sentinelCopy(sentinel);
	ScavTrap ultron("Ultron");

	description("Testing functions");
	ultron.attack(sentinel.getName());
	sentinel.takeDamage(ultron.getAttackDamage());
	sentinel.beRepaired(10);
	sentinel.guardGate();

	description("Testing instance copy");
	sentinel2.attack(sentinelCopy.getName());
	sentinelCopy.takeDamage(sentinel2.getAttackDamage());
	sentinelCopy.beRepaired(20);
	sentinelCopy.guardGate();

	description("Testing energy <= 0 and hit points <= 0");
	sentinel.setEnergyPoints(0);
	sentinel.setHitPoints(0);
	sentinel.guardGate();

	description("Destructors messages");
}

int main(int argc, char *argv[]) {

	if (argc > 1) {
		std::string mode = argv[1];
		if (mode.compare("all") == 0) {
			tests_ex00();
			tests_ex01();
		}
	}

	description("------------------------- Tests ex02 -------------------------");

	description("Constructors messages");
	FragTrap droid1;
	FragTrap droid2;
	FragTrap c3po("C-3PO");
	FragTrap r2d2("R2-D2");
	FragTrap bb8("BB-8");
	FragTrap bb8_clone(bb8);

	description("Testing functions");
	bb8.highFiveGuys();
	bb8.beRepaired(10);
	droid2.attack(droid1.getName());
	droid1.takeDamage(droid2.getAttackDamage());

	description("Testing instance copy");
	bb8_clone.highFiveGuys();

	description("Testing energy <= 0 and hit points <= 0");
	c3po.setEnergyPoints(0);
	c3po.setHitPoints(0);
	c3po.highFiveGuys();

	description("Destructors messages");
	return (0);
}

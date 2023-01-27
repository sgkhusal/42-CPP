/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:28 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/26 23:57:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

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

static void	tests_ex01(void) {
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
	sentinel.beRepaired(10);

	std::cout << std::endl;
	sentinel2.attack(sentinelCopy.getName());
	sentinelCopy.takeDamage(sentinel2.getAttackDamage());

	std::cout << std::endl;
	sentinel.guardGate();
	sentinel.setEnergyPoints(0);
	sentinel.setHitPoints(0);
	sentinel.guardGate();

	std::cout << std::endl;
}

static void	tests_ex02(void) {
	std::cout << std::endl;
	std::cout << LIGHT_PURPLE
			<< "------------------------- Tests ex02 -------------------------"
			<< std::endl << std::endl;

	FragTrap droid1;
	FragTrap droid2;
	FragTrap cp3po("CP3PO");
	FragTrap r2d2("R2-D2");
	FragTrap bb8("BB-8");
	FragTrap bb8_clone(bb8);

	std::cout << std::endl;
	bb8.highFiveGuys();
	bb8.beRepaired(10);
	cp3po.setEnergyPoints(0);
	cp3po.setHitPoints(0);
	cp3po.highFiveGuys();

	std::cout << std::endl;
	droid2.attack(droid1.getName());
	droid1.takeDamage(droid2.getAttackDamage());

	std::cout << std::endl;
}

void	print_infos(ClapTrap const& robot, std::string const& type) {
	std::cout << LIGHT_GREY << std::setw(12) << type
			<< std::setw(11) << robot.getName() << " | "
			<< robot.getEnergyPoints() << " | "
			<< robot.getHitPoints() << " | "
			<< robot.getAttackDamage() << RESET << std::endl;
}

int main(int argc, char *argv[]) {

	if (argc > 1) {
		std::string mode = argv[1];
		if (mode.compare("all") == 0) {
			tests_ex00();
			tests_ex01();
			tests_ex02();
		}
	}

	std::cout << std::endl;
	std::cout << LIGHT_PURPLE
			<< "------------------------- Tests ex03 -------------------------"
			<< std::endl << std::endl;
	DiamondTrap diamond;
	ClapTrap	robot;
	ScavTrap	sentinel;
	FragTrap	droid;

	std::cout << std::endl;
	print_infos(robot, " ClapTrap: ");
	print_infos(sentinel, "ScarvTrap: ");
	print_infos(droid, " FragTrap: ");
	print_infos(diamond, "  Diamond: ");
	/* std::cout << "ClapTrap:  " << robot.getName() << "   - "
			<< robot.getEnergyPoints() << " "
			<< robot.getHitPoints() << "  "
			<< robot.getAttackDamage() << std::endl;
	std::cout << "ScarvTrap: " << scav.getName() << " - "
			<< scav.getEnergyPoints() << " "
			<< scav.getHitPoints() << " "
			<< scav.getAttackDamage() << std::endl;
	std::cout << "FragTrap:  " << frag.getName() << "   - "
			<< frag.getEnergyPoints() << " "
			<< frag.getHitPoints() << " "
			<< frag.getAttackDamage() << std::endl; */
	std::cout << "Diamond:   " << diamond.getName() << " - "
			<< diamond.getEnergyPoints() << " "
			<< diamond.getHitPoints() << " "
			<< diamond.getAttackDamage() << std::endl;

	std::cout << std::endl;
	diamond.attack(robot.getName());

	std::cout << std::endl;
	return (0);
}

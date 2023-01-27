/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:09:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/27 01:12:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int FragTrap::_droid_nb = 0;

FragTrap::FragTrap(void): ClapTrap() {
	std::stringstream index;

	index << ++FragTrap::_droid_nb;
	this->setName("Droid " + index.str());
	this->setHitPoints(FRAG_TRAP_INIT_HP);
	this->setEnergyPoints(FRAG_TRAP_INIT_EP);
	this->setAttackDamage(FRAG_TRAP_INIT_AD);
	_constructor_msg("Default");
}

FragTrap::FragTrap(FragTrap const& ft): ClapTrap() {
	*this = ft;
	_constructor_msg("Copy");
}

FragTrap::FragTrap(std::string const name): ClapTrap(name) {
	this->setHitPoints(FRAG_TRAP_INIT_HP);
	this->setEnergyPoints(FRAG_TRAP_INIT_EP);
	this->setAttackDamage(FRAG_TRAP_INIT_AD);
	_constructor_msg("Named");
}

FragTrap::~FragTrap(void) {
	std::cout << CYAN << "FragTrap " << this->getName()
			<< " destroyed" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& ft) {
	if (this != &ft) {
		this->_name = ft.getName();
		this->_hitPoints = ft.getHitPoints();
		this->_energyPoints = ft.getEnergyPoints();
		this->_attackDamage = ft.getAttackDamage();
	}
	std::cout << GREY << "FragTrap " << this->getName()
			<< " copied" << RESET << std::endl;
	return (*this);
}

void	FragTrap::highFiveGuys(void) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << ORANGE << "FragTrap " << this->getName()
				<< " unable to give a high five message: hit points = "
				<< hitPoints << RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << ORANGE << "FragTrap " << this->getName()
				<< " unable to give a high five message: energy points = "
				<< energyPoints << RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0)
	std::cout << YELLOW << this->getName() << ": High five guys!!!" << std::endl;
}

void FragTrap::_constructor_msg(std::string type) {
	std::cout << CYAN << "FragTrap " << this->getName()
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

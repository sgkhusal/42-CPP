/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:09:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/28 10:03:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int FragTrap::_droidNb = 0;

FragTrap::FragTrap(void): ClapTrap() {
	std::stringstream index;

	index << ++FragTrap::_droidNb;
	this->setName("Droid " + index.str());
	this->setHitPoints(FRAG_INIT_HP);
	this->setEnergyPoints(FRAG_INIT_EP);
	this->setAttackDamage(FRAG_INIT_AD);
	_constructorMsg("Default");
}

FragTrap::FragTrap(std::string const& name): ClapTrap(name) {
	this->setHitPoints(FRAG_INIT_HP);
	this->setEnergyPoints(FRAG_INIT_EP);
	this->setAttackDamage(FRAG_INIT_AD);
	_constructorMsg("Named");
}

FragTrap::FragTrap(FragTrap const& ft): ClapTrap() {
	*this = ft;
	_constructorMsg("Copy");
}

FragTrap::~FragTrap(void) {
	std::cout << CYAN << FRAG << this->getName()
			<< " destroyed" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& ft) {
	if (this != &ft) {
		this->_name = ft.getName();
		this->_hitPoints = ft.getHitPoints();
		this->_energyPoints = ft.getEnergyPoints();
		this->_attackDamage = ft.getAttackDamage();
	}
	std::cout << GREY << FRAG << this->getName()
			<< " copied" << RESET << std::endl;
	return (*this);
}

void	FragTrap::highFiveGuys(void) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << GREY << FRAG << this->getName()
				<< " unable to give a high five message: hit points = "
				<< hitPoints << RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << GREY << FRAG << this->getName()
				<< " unable to give a high five message: energy points = "
				<< energyPoints << RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0)
	std::cout << YELLOW << this->getName() << ": High five guys!!!" << std::endl;
}

void FragTrap::_constructorMsg(std::string const& type) {
	std::cout << CYAN << FRAG << this->getName()
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

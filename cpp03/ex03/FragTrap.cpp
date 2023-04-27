/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:09:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int FragTrap::_droidNb = 0;

FragTrap::FragTrap(void): ClapTrap() {
	std::stringstream index;

	index << ++FragTrap::_droidNb;
	this->setName("Droid " + index.str());
	this->setHitPoints(FRAG_INIT_HPPP);
	this->setEnergyPoints(FRAG_INIT_EP);
	this->setAttackDamage(FRAG_INIT_AD);
	this->setType(FRAG);
	_constructorMsg("Default");
}

FragTrap::FragTrap(std::string const& name): ClapTrap(name) {
	this->setHitPoints(FRAG_INIT_HPPP);
	this->setEnergyPoints(FRAG_INIT_EP);
	this->setAttackDamage(FRAG_INIT_AD);
	this->setType(FRAG);
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
		this->_HPPitPoints = ft.getHitPoints();
		this->_energyPoints = ft.getEnergyPoints();
		this->_attackDamage = ft.getAttackDamage();
		this->_type = ft.getType();
	}
	std::cout << GREY << this->getType() << this->getName()
			<< " copied" << RESET << std::endl;
	return (*this);
}

void	FragTrap::highFiveGuys(void) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << GREY << this->getType()  << this->getName()
				<< " unable to give a high five message: hit points = "
				<< hitPoints << RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << GREY << this->getType()  << this->getName()
				<< " unable to give a high five message: energy points = "
				<< energyPoints << RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0)
		std::cout << YELLOW << this->getType() << this->getName()
				<< ": High five guys!!!" << std::endl;
}

void FragTrap::_constructorMsg(std::string const& type) {
	std::cout << CYAN << FRAG << this->getName()
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

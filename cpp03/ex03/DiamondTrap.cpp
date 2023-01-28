/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:56:16 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/28 18:49:51 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int DiamondTrap::_diamondNb = 0;

DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap() {
	std::stringstream index;

	index << ++DiamondTrap::_diamondNb;
	this->setName("Destroyer_" + index.str());
	ClapTrap::setName(this->_name + "_clap_name");
	this->setHitPoints(FRAG_INIT_HP);
	this->setEnergyPoints(SCAV_INIT_EP);
	this->setAttackDamage(FRAG_INIT_AD);
	this->setType(DIAMOND);
	_constructorMsg("Default");
}

DiamondTrap::DiamondTrap(std::string const& name): ScavTrap(), FragTrap(), _name(name) {
	ClapTrap::_name = name + "_clap_name";
	FragTrap::_hitPoints = FRAG_INIT_HP;
	ScavTrap::_energyPoints = SCAV_INIT_EP;
	FragTrap::_attackDamage = FRAG_INIT_AD;
	this->setType(DIAMOND);
	_constructorMsg("Named");
}

DiamondTrap::DiamondTrap(DiamondTrap const& d): ClapTrap(), ScavTrap(), FragTrap() {
	*this = d;
	_constructorMsg("Copy");
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << LIGHT_PURPLE << DIAMOND << this->_name
			<< " destroyed" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& d) {
	if (this != &d) {
		this->_name = d.getName();
		ClapTrap::_name = d.ClapTrap::getName();
		this->_hitPoints = d.getHitPoints();
		this->_energyPoints = d.getEnergyPoints();
		this->_attackDamage = d.getAttackDamage();
		this->_type = d.getType();
		std::cout << GREY << DIAMOND << this->getName()
				<< " copied" << RESET << std::endl;
	}
	return (*this);
}

void DiamondTrap::_constructorMsg(std::string const& type) {
	std::cout << LIGHT_PURPLE << DIAMOND << this->_name
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << GREY << DIAMOND << this->getName()
				<< " unable to say who it is: hit points = "
				<< hitPoints << RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << GREY << DIAMOND << this->getName()
				<< " unable to say who it is: energy points = "
				<< energyPoints << RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0)
		std::cout << LIGHT_PURPLE << "Hello! My name is " << this->_name
				<< ", also known as " << ClapTrap::getName()
				<< RESET << std::endl;
}

std::string DiamondTrap::getName(void) const {
	return (this->_name);
}

void DiamondTrap::setName(std::string const& name) {
	this->_name = name;
}

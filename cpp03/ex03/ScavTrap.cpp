/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:23:58 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int ScavTrap::_sentinelNb = 0;

ScavTrap::ScavTrap(void): ClapTrap() {
	std::stringstream index;

	index << ++ScavTrap::_sentinelNb;
	this->setName("Sentinel " + index.str());
	this->setHitPoints(SCAV_INIT_HPPP);
	this->setEnergyPoints(SCAV_INIT_EP);
	this->setAttackDamage(SCAV_INIT_AD);
	this->setType(SCAV);
	_constructorMsg("Default");
}

ScavTrap::ScavTrap(std::string const& name): ClapTrap(name) {
	this->setHitPoints(SCAV_INIT_HPPP);
	this->setEnergyPoints(SCAV_INIT_EP);
	this->setAttackDamage(SCAV_INIT_AD);
	this->setType(SCAV);
	_constructorMsg("Named");
}

ScavTrap::ScavTrap(ScavTrap const& st): ClapTrap() {
	*this = st;
	_constructorMsg("Copy");
}

ScavTrap::~ScavTrap(void) {
	std::cout << CYAN << SCAV << this->getName()
			<< " destroyed" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& st) {
	if (this != &st) {
		this->_name = st.getName();
		this->_HPPitPoints = st.getHitPoints();
		this->_energyPoints = st.getEnergyPoints();
		this->_attackDamage = st.getAttackDamage();
		this->_type = st.getType();
	}
	std::cout << GREY << SCAV << this->getName()
			<< " copied" << RESET << std::endl;
	return (*this);
}

void	ScavTrap::guardGate(void) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << GREY << this->getType() << this->getName()
				<< " unable to enter in gate keeper mode: hit points = "
				<< hitPoints << RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << GREY << this->getType() << this->getName()
				<< " unable to enter in gate keeper mode: energy points = "
				<< energyPoints << RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0)
		std::cout << YELLOW << this->getType() << this->getName()
				<< " is in gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const& target) {
	ClapTrap::attack(target);
}

void ScavTrap::_constructorMsg(std::string const& type) {
	std::cout << CYAN << SCAV << this->getName()
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

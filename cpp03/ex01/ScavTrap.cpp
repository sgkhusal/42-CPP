/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:23:58 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/26 23:52:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int ScavTrap::_sentinel_nb = 0;

ScavTrap::ScavTrap(void): ClapTrap() {
	std::string index;

	++ScavTrap::_sentinel_nb;
	index.push_back(ScavTrap::_sentinel_nb + 48);
	this->setName("Sentinel " + index);
	this->setHitPoints(SCAV_TRAP_INIT_HP);
	this->setEnergyPoints(SCAV_TRAP_INIT_EP);
	this->setAttackDamage(SCAV_TRAP_INIT_AD);
	_constructor_msg("Default");
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name) {
	this->setHitPoints(SCAV_TRAP_INIT_HP);
	this->setEnergyPoints(SCAV_TRAP_INIT_EP);
	this->setAttackDamage(SCAV_TRAP_INIT_AD);
	_constructor_msg("Named");
}

ScavTrap::ScavTrap(ScavTrap const& st): ClapTrap() {
	*this = st;
	_constructor_msg("Copy");
}

ScavTrap::~ScavTrap(void) {
	std::cout << CYAN << "ScavTrap " << this->getName()
			<< " destroyed" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& st) {
	if (this != &st) {
		this->_name = st.getName();
		this->_hitPoints = st.getHitPoints();
		this->_energyPoints = st.getEnergyPoints();
		this->_attackDamage = st.getAttackDamage();
	}
	std::cout << GREY << "ScavTrap " << this->getName()
			<< " copied" << RESET << std::endl;
	return (*this);
}

void	ScavTrap::guardGate(void) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << ORANGE << "ScavTrap " << this->getName()
				<< " unable to enter in gate keeper mode: hit points = "
				<< hitPoints << RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << ORANGE << "ScavTrap " << this->getName()
				<< " unable to enter in gate keeper mode: energy points = "
				<< energyPoints << RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0)
		std::cout << YELLOW << "ScavTrap " << this->getName()
				<< " is in gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << ORANGE << "ScavTrap " << this->getName()
				<< " unable to attack " << target
				<< ": hit points = " << hitPoints
				<< RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << ORANGE << "ScavTrap " << this->getName()
				<< " unable to attack " << target
				<< ": energy points = " << energyPoints
				<< RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0) {
		this->setEnergyPoints(energyPoints - 1);
		std::cout << YELLOW << "ScavTrap " << this->getName() << " attacks "
				<< target << " causing " << this->getAttackDamage()
				<< " points of damage!" << RESET << std::endl;
	}
}

void ScavTrap::_constructor_msg(std::string type) {
	std::cout << CYAN << "ScavTrap " << this->getName()
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

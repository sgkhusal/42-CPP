/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:23 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int ClapTrap::_robotNb = 0;

ClapTrap::ClapTrap(void): _HPPitPoints(CLAP_INIT_HPPP),
							_energyPoints(CLAP_INIT_EP),
							_attackDamage(CLAP_INIT_AD) {
	std::stringstream index;

	index << ++ClapTrap::_robotNb;
	this->setName("Robot " + index.str());
	_constructorMsg("Default");
}

ClapTrap::ClapTrap(std::string const& name): _name(name),
											_HPPitPoints(CLAP_INIT_HPPP),
											_energyPoints(CLAP_INIT_EP),
											_attackDamage(CLAP_INIT_AD) {
	_constructorMsg("Named");
}

ClapTrap::ClapTrap(ClapTrap const& ct) {
	*this = ct;
	_constructorMsg("Copy");
}

ClapTrap::~ClapTrap(void) {
	std::cout << BLUE << CLAP << this->getName()
			<< " destroyed" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& ct) {
	if (this != &ct) {
		this->_name = ct.getName();
		this->_HPPitPoints = ct.getHitPoints();
		this->_energyPoints = ct.getEnergyPoints();
		this->_attackDamage = ct.getAttackDamage();
		std::cout << GREY << CLAP << this->getName()
				<< " copied" << RESET << std::endl;
	}
	return (*this);
}

void ClapTrap::attack(std::string const& target) {
	attack_type(target, CLAP);
}

void	ClapTrap::attack_type(std::string const& target,
							std::string const& type) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << GREY << type << this->getName() << " unable to attack "
				<< target << ": hit points = " << hitPoints
				<< RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << GREY << type << this->getName() << " unable to attack "
				<< target << ": energy points = " << energyPoints
				<< RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0) {
		this->_energyPoints--;
		std::cout << YELLOW << type << this->getName() << " attacks "
				<< target << " causing " << this->getAttackDamage()
				<< " points of damage!" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if ((int)amount >= 0) {
		this->_HPPitPoints -= (int)amount;
		std::cout << ORANGE << this->getName()
				<< " attacked with damage amount of " << amount
				<< ", resulting in a total of " << this->getHitPoints()
				<< " health points" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << GREY << this->getName()
				<< " unable to be repaired: hit points = " << hitPoints
				<< RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << GREY << this->getName()
				<< " unable to be repaired: energy points = " << energyPoints
				<< RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0 && (int)amount >= 0) {
		this->_HPPitPoints += amount;
		this->_energyPoints--;
		std::cout << GREEN << this->getName()
				<< " repaired with " << amount
				<< " health points, resulting in a total of "
				<< this->getHitPoints() << " health points" << RESET << std::endl;
	}
}

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

int ClapTrap::getHitPoints(void) const {
	return (this->_HPPitPoints);
}

int ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void ClapTrap::setName(std::string const& name) {
	this->_name = name;
}

void ClapTrap::setHitPoints(int const hitPoints) {
	if (hitPoints >= 0)
		this->_HPPitPoints = hitPoints;
	else
		this->_HPPitPoints = 0;
}

void ClapTrap::setEnergyPoints(int const energyPoints) {
	if (energyPoints >= 0)
		this->_energyPoints = energyPoints;
	else
		this->_energyPoints = 0;
}

void ClapTrap::setAttackDamage(int const attackDamage) {
	if (attackDamage >= 0)
		this->_attackDamage = attackDamage;
	else
		this->_attackDamage = 0;
}

void ClapTrap::_constructorMsg(std::string const& type) {
	std::cout << BLUE << CLAP << this->getName()
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

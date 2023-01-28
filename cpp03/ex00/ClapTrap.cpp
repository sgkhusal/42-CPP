/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:23 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/28 08:12:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int ClapTrap::_robotNb = 0;

ClapTrap::ClapTrap(void): _hitPoints(INIT_HP),
							_energyPoints(INIT_EP),
							_attackDamage(INIT_AD) {
	std::stringstream index;

	index << ++ClapTrap::_robotNb;
	this->setName("Robot " + index.str());
	_constructorMsg("Default");
}

ClapTrap::ClapTrap(std::string const name): _name(name),
											_hitPoints(INIT_HP),
											_energyPoints(INIT_EP),
											_attackDamage(INIT_AD) {
	_constructorMsg("Named");
}

ClapTrap::ClapTrap(ClapTrap const& ct) {
	*this = ct;
	_constructorMsg("Copy");
}

ClapTrap::~ClapTrap(void) {
	std::cout << BLUE << this->getName()
			<< " destroyed" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& ct) {
	if (this != &ct) {
		this->_name = ct.getName();
		this->_hitPoints = ct.getHitPoints();
		this->_energyPoints = ct.getEnergyPoints();
		this->_attackDamage = ct.getAttackDamage();
		std::cout << GREY << this->getName()
				<< " copied" << RESET << std::endl;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << GREY << this->getName() << " unable to attack "
				<< target << ": hit points = " << hitPoints
				<< RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << GREY << this->getName() << " unable to attack "
				<< target << ": energy points = " << energyPoints
				<< RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0) {
		this->_energyPoints--;
		std::cout << YELLOW << this->getName() << " attacks "
				<< target << " causing " << this->getAttackDamage()
				<< " points of damage!" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= (int)amount;
	std::cout << ORANGE << this->getName()
			<< " attacked with damage amount of " << amount
			<< ", resulting in a total of " << this->getHitPoints()
			<< " hit points" << RESET << std::endl;
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
	if (hitPoints > 0 && energyPoints > 0) {
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << GREEN << this->getName()
				<< " repaired with " << amount
				<< " hit points, resulting in a total of "
				<< this->getHitPoints() << " hit points" << RESET << std::endl;
	}
}

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

int ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void ClapTrap::setName(std::string const name) {
	this->_name = name;
}

void ClapTrap::setHitPoints(int const hitPoints) {
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int const energyPoints) {
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int const attackDamage) {
	this->_attackDamage = attackDamage;
}

void ClapTrap::_constructorMsg(std::string type) {
	std::cout << BLUE << this->getName()
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:23 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/23 17:54:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int ClapTrap::_robot_nb = 0;

ClapTrap::ClapTrap(void): _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::string index;
	
	++ClapTrap::_robot_nb;
	index.push_back(ClapTrap::_robot_nb + 48);
	this->setName("Robot " + index);
	this->_constructor_called("Default");
}

ClapTrap::ClapTrap(ClapTrap const& ct) {
	*this = ct;
	this->_constructor_called("Copy");
}

ClapTrap::ClapTrap(std::string const name): _name(name), 
											_hitPoints(10), 
											_energyPoints(10), 
											_attackDamage(0) {
	this->_constructor_called("Named");
}

ClapTrap::~ClapTrap(void) {
	std::cout << ORANGE << "ClapTrap " << this->getName() 
			<< " destroyed" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& ct) {
	if (this != &ct) {
		this->setName(ct.getName());
		this->setHitPoints(ct.getHitPoints());
		this->setEnergyPoints(ct.getEnergyPoints());
		this->setAttackDamage(ct.getAttackDamage());
	}
	std::cout << GREY << "ClapTrap " << this->getName() << " copied" << RESET << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << RED << "ClapTrap " << this->getName() << " unable to attack " 
				<< target << ": hit points = " << hitPoints 
				<< RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << RED << "ClapTrap " << this->getName() << " unable to attack " 
				<< target << ": energy points = " << energyPoints 
				<< RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0) {
		this->_energyPoints--;
		std::cout << PURPLE << "ClapTrap " << this->getName() << " attacks " 
				<< target << " causing " << this->getAttackDamage() 
				<< " points of damage!" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
	std::cout << RED << "ClapTrap " << this->getName() << " attacked with damage amount of " 
			<< amount << ", resulting in a total of " << this->getHitPoints() 
			<< " hit points" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	int	hitPoints = this->getHitPoints();
	int energyPoints = this->getEnergyPoints();

	if (hitPoints <= 0)
		std::cout << RED << "ClapTrap " << this->getName()  
				<< " unable to be repaired: hit points = " << hitPoints  
				<< RESET << std::endl;
	if (energyPoints <= 0)
		std::cout << RED << "ClapTrap " << this->getName()  
				<< " unable to be repaired: energy points = " << energyPoints 
				<< RESET << std::endl;
	if (hitPoints > 0 && energyPoints > 0) {
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << GREEN << "ClapTrap " << this->getName() 
				<< " repaired with " << amount
				<< " hit points, resulting in a total of " << this->getHitPoints() 
				<< " hit points" << RESET << std::endl;
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

void ClapTrap::_constructor_called(std::string type) {
	std::cout << BLUE << "ClapTrap " << this->getName() 
			<< " created in " << type << " constructor" 
			<< RESET << std::endl;
}
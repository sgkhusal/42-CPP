/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:56:16 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/26 23:19:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int DiamondTrap::_diamond_nb = 0;

DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap() {
	std::string index;

	++DiamondTrap::_diamond_nb;
	index.push_back(DiamondTrap::_diamond_nb + 48);
	this->_name = "Diamond " + index;
	/* this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20); */
	_constructor_msg("Default");
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << LIGHT_PURPLE << "DiamondTrap " << this->_name
			<< " destroyed" << RESET << std::endl;
}

void DiamondTrap::_constructor_msg(std::string type) {
	std::cout << LIGHT_PURPLE << "DiamondTrap " << this->_name
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

/* void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
} */

std::string DiamondTrap::getName(void) const {
	return (this->_name);
}

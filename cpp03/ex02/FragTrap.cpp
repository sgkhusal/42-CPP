/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:09:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/25 22:34:59 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int FragTrap::_droid_nb = 0;

FragTrap::FragTrap(void): ClapTrap() {
	std::string index;

	++FragTrap::_droid_nb;
	index.push_back(FragTrap::_droid_nb + 48);
	this->setName("Droid " + index);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	_constructor_msg("Default");
}

FragTrap::FragTrap(FragTrap const& st): ClapTrap() {
	*this = st;
	_constructor_msg("Copy");
}

FragTrap::FragTrap(std::string const name): ClapTrap(name) {
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	_constructor_msg("Named");
}

FragTrap::~FragTrap(void) {
	std::cout << CYAN << "FragTrap " << this->getName()
			<< " destroyed" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& st) {
	if (this != &st) {
		this->setName(st.getName());
		this->setHitPoints(st.getHitPoints());
		this->setEnergyPoints(st.getEnergyPoints());
		this->setAttackDamage(st.getAttackDamage());
	}
	std::cout << GREY << "FragTrap " << this->getName() << " copied" << RESET << std::endl;
	return (*this);
}

//This member function displays a positive high fives request on the standard output
void	FragTrap::highFiveGuys(void) {
	std::cout << YELLOW << this->getName() << ": High five guys!!!" << std::endl;
}

void FragTrap::_constructor_msg(std::string type) {
	std::cout << CYAN << "FragTrap " << this->getName()
			<< " created in " << type << " constructor"
			<< RESET << std::endl;
}

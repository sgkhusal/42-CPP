/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:08:50 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 23:46:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void	HumanB::attack(void) {
	if (this->_weapon)
		std::cout << RED << this->_name << " attacks with their " \
				<< this->_weapon->getType() << RESET << std::endl;
	else
		std::cout << GREY << this->_name \
				<< " doesn't have a weapon so he can't attack " \
				<< RESET << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

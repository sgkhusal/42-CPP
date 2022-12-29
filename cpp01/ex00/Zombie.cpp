/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:39:23 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/29 19:07:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	return ;
}

Zombie::Zombie(std::string name) : _name(name) {
	return ;
}

Zombie::~Zombie(void) {
	std::cout << GREY << "Zombie " << _getZombieName() << " destroyed"
			<< RESET << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << _getZombieName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setZombieName(std::string name) {
	this->_name = name;
}

std::string	Zombie::_getZombieName(void) {
	return (this->_name);
}

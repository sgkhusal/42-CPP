/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:24:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 21:04:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	Zombie::totalZombies += 1;
	std::cout << GREY << Zombie::totalZombies << ": Zombie" << this->_name \
			<< " created" << RESET << std::endl;
	return ;
}

Zombie::~Zombie(void) {
	Zombie::totalZombies -= 1;
	std::cout << GREY << "Zombie " << this->_name << " destroyed" \
			<< RESET << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setZombieName(std::string name) {
	this->_name = name;
}

int	Zombie::totalZombies = 0;

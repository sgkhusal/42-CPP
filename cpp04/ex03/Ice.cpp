/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/24 23:47:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice") {}

Ice::Ice(Ice const& ice){
	*this = ice;
}

Ice::~Ice(void){}

Ice& Ice::operator=(Ice const& ice){ /////////////
	// if (this != &Ice) {
	// 	this->type = Ice.type;
	// }
	return (*this);
}

AMateria* Ice::clone() const {
    AMateria* ice = new Ice();
    return ice;
}

void Ice::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 11:15:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice") {}

Ice::Ice(Ice const& ice) {
	*this = ice;
}

Ice::~Ice(void) {}

Ice& Ice::operator=(Ice const& ice) { /////////////
	(void)ice;
	return (*this);
}

AMateria* Ice::clone(void) const {
    AMateria* ice = new Ice();
    return ice;
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at "<< target.getName() << " *"
            << std::endl;
}

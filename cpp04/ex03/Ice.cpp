/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/08 23:34:00 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice") {
    classDescription("Ice", "constructor");
}

Ice::Ice(Ice const& ice): AMateria(ice) {
    classDescription("Ice", "copy constructor");
	*this = ice;
}

Ice::~Ice(void) {
    classDescription("Ice", "destructor");
}

Ice& Ice::operator=(Ice const& ice) {
    classDescription("Ice", "assign operator");
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

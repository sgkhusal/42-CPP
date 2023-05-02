/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:05 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/02 00:29:09 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") {}

Cure::Cure(Cure const& cure) {
	*this = cure;
}

Cure::~Cure(void) {}

Cure& Cure::operator=(Cure const& cure) { /////////////
	(void)cure;
	return (*this);
}

AMateria* Cure::clone(void) const {
    AMateria* cure = new Cure();
    return cure;
}

void Cure::use(ICharacter& target) {
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *"
			<< RESET << std::endl;
}

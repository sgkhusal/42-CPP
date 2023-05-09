/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:05 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/08 23:34:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") {
	classDescription("Cure", "constructor");
}

Cure::Cure(Cure const& cure): AMateria(cure) {
	classDescription("Cure", "copy constructor");
	*this = cure;
}

Cure::~Cure(void) {
	classDescription("Cure", "destructor");
}

Cure& Cure::operator=(Cure const& cure) {
	classDescription("Cure", "assign operator");
	(void)cure;
	return (*this);
}

AMateria* Cure::clone(void) const {
    AMateria* cure = new Cure();
    return cure;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

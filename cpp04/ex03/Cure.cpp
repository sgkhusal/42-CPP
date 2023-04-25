/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:05 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/24 23:47:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") {}

Cure::Cure(Cure const& cure){
	*this = cure;
}

Cure::~Cure(void){}

Cure& Cure::operator=(Cure const& cure){ /////////////
	// if (this != &cure) {
	// 	this->type = cure.type;
	// }
	return (*this);
}

AMateria* Cure::clone() const {
    AMateria* cure = new Cure();
    return cure;
}

void Cure::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at "<< target.getName() << " *"
            << std::endl;
}

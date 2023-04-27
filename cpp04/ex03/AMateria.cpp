/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:20 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/26 23:34:23 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): type("Undefined") {}

AMateria::AMateria(std::string const & type): type(type) {}

AMateria::AMateria(AMateria const& materia){
	*this = materia;
}

AMateria::~AMateria(void){}

AMateria& AMateria::operator=(AMateria const& materia){
	if (this != &materia) {
		// if (materia.type == "cure") ////////////////////////////////
		// 	this = new Cure;
		this->type = materia.type;
		// como setar as ins
	}
	return (*this);
}

std::string	const & AMateria::getType(void) const {
	return this->type;
}

/////////////////
void AMateria::use(ICharacter& target) {
	std::cout << "Do something with " << target.getName() << std::endl;
}

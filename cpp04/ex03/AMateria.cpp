/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:20 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/08 23:12:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): type("undefined") {
	classDescription("AMateria", "constructor");
}

AMateria::AMateria(std::string const & type): type(type) {
	classDescription("AMateria", "constructor");
}

AMateria::AMateria(AMateria const& materia): type(materia.type) {
	classDescription("AMateria", "copy constructor");
	*this = materia;
}

AMateria::~AMateria(void){
	classDescription("AMateria", "destructor");
}

AMateria& AMateria::operator=(AMateria const& materia){
	classDescription("AMateria", "assign operator");
	(void)materia;
	return (*this);
}

std::string	const & AMateria::getType(void) const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << this->getType() << " do something with " << target.getName()
			<< std::endl;
}

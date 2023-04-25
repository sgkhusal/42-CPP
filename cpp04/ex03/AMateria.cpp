/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:20 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/24 23:35:35 by sguilher         ###   ########.fr       */
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
		this->type = materia.type;
	}
	return (*this);
}

std::string	const & AMateria::getType(void) const {
	return this->type;
}

/////////////////
void AMateria::use(ICharacter& target) {

}

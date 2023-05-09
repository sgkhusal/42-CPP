/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:45:39 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/09 00:08:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
# include "Cure.hpp" /////////

MateriaSource::MateriaSource(void) {
	classDescription("Character", "constructor");
    for (int i = 0; i < 4; i++)
        this->storage[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& materiaSource) {
	classDescription("Character", "copy constructor");
	*this = materiaSource;
}

MateriaSource::~MateriaSource(void) {
	classDescription("Character", "destructor");
}

MateriaSource& MateriaSource::operator=(MateriaSource const& materiaSource) {
	classDescription("Character", "assign operator");
	(void)materiaSource;
	// if (this != &MateriaSource) {
	// 	this->type = MateriaSource.type;
	// }
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia) {
	(void)materia;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	(void)type;
	return new Cure();
}

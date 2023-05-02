/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:45:39 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/02 00:19:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
# include "Cure.hpp" /////////

MateriaSource::MateriaSource(void): IMateriaSource() {
    for (int i = 0; i < 4; i++)
        this->storage[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& materiaSource) {
	*this = materiaSource;
}

MateriaSource::~MateriaSource(void) {}

MateriaSource& MateriaSource::operator=(MateriaSource const& materiaSource) {
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

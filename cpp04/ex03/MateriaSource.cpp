/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:45:39 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/12 23:26:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	classDescription("MateriaSource", "constructor");
	for (int i = 0; i < STORAGE_SIZE; i++)
		this->storage[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& materiaSource) {
	classDescription("MateriaSource", "copy constructor");
	for (int i = 0; i < STORAGE_SIZE; i++)
		this->storage[i] = NULL;
	*this = materiaSource;
}

MateriaSource::~MateriaSource(void) {
	classDescription("MateriaSource", "destructor");
	for (int i = 0; i < STORAGE_SIZE; i++) {
		if (this->storage[i])
			delete this->storage[i];
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const& materiaSource) {
	classDescription("MateriaSource", "assign operator");
	if (this != &materiaSource) {
		for (int i = 0; i < STORAGE_SIZE; i++) {
			if (this->storage[i])
				delete this->storage[i];
			if (materiaSource.storage[i])
				this->storage[i] = materiaSource.storage[i]->clone();
			else
				this->storage[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia) {
	int i = 0;
	while (i < STORAGE_SIZE) {
		if (this->storage[i])
			i++;
		else
			break;
	}
	if (i == STORAGE_SIZE) {
		std::cout << "All magic slots in the storage are full" << std::endl;
		return ;
	}
	this->storage[i] = materia;
	std::cout << "Learned " << this->storage[i]->getType() << " magic"
			<< std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < STORAGE_SIZE; i++) {
		if (this->storage[i]->getType() == type) {
			std::cout << "Magic " << type << " created" << std::endl;
			return this->storage[i]->clone();
		}
	}
	std::cout << "Can't create "<< type << ": magic unknown" << std::endl;
	return 0;
}

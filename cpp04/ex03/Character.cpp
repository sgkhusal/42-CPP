/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/09 01:30:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string Character::_charactersSample[30] = {
	"Harry Potter",
	"Hermione Granger",
	"Ronald Weasley",
	"Gina Weasley",
	"Fred Weasley",
	"George Weasley",
	"Luna Lovegood",
	"Albus Dumbledore",
	"Rubeos Hagrid",
	"Draco Malfoy",
	"Severo Snape",
	"Sirius Black",
	"Neville Longbottom",
	"Remus Lupin",
	"Minerva McGonagall",
	"Lucius Malfoy",
	"Voldemort",
	"Bellatrix Lestrange",
	"Duda Dursley",
	"Bilbo Baggins",
	"Frodo Baggins",
	"Pippin Took",
	"Merry Brandybuck",
	"Samwise Gamgee",
	"Gandalf",
	"Grogu",
	"Aragorn",
	"Legolas",
	"Gimli",
	"Boromir"
};

Character::Character(void) {
	classDescription("Character", "constructor");
	this->_name = Character::_charactersSample[rand() % 30];
	for (int i = 0; i < SLOTS; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const& name): _name(name) {
	classDescription("Character", "constructor");
	for (int i = 0; i < SLOTS; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const& character) {
	classDescription("Character", "copy constructor");
	for (int i = 0; i < SLOTS; i++)
		this->inventory[i] = NULL;
	*this = character;
}

Character::~Character(void) {
	classDescription("Character", "destructor");
	for (int i = 0; i < SLOTS; i++)
		delete this->inventory[i];
}

Character& Character::operator=(Character const& character) { ///////////
	classDescription("Character", "assign operator");
	if (this != &character) {
		this->_name = character.getName();
		for (int i = 0; i < SLOTS; i++) {
			if (this->inventory[i])
				delete this->inventory[i];
			if (character.inventory[i])
				this->inventory[i] = character.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	int i = 0;
	while (i < SLOTS) {
		if (this->inventory[i])
			i++;
		else
			break;
	}
	if (i == SLOTS) {
		std::cout << "All magic slots are full" << std::endl;
		return ;
	}
	this->inventory[i] = m;
	std::cout << "Equiped " << this->getName() << " with "
			<< this->inventory[i]->getType() << std::endl;
	// TODO: problema: qdo se passa uma materia que já está no inventário...
}

void Character::unequip(int idx) {
	if (0 <= idx && idx < SLOTS && this->inventory[idx]) {
			std::cout << "Unequiped " << this->inventory[idx]->getType()
					<< " from " << this->getName() << std::endl;
			this->inventory[idx] = NULL; /// TODO: tem que dar delete de alguma forma
			// The unequip() member function must NOT delete the Materia
	}
	else if (idx < 0 || idx >= SLOTS)
		std::cout << "Invalid slot number" << std::endl;
	else
		std::cout << this->getName() << " slot " << idx
				<< " already empty" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (0 <= idx && idx < SLOTS && this->inventory[idx])
		(*this->inventory[idx]).use(target);
	else if (idx < 0 || idx >= SLOTS)
		std::cout << "Invalid slot number" << std::endl;
	else
		std::cout << "Empty magic slot..." << std::endl;
}

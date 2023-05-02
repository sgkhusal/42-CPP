/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/02 00:06:37 by sguilher         ###   ########.fr       */
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

Character::Character(void): ICharacter() {
	this->_name = Character::_charactersSample[rand() % 30];
	for (int i = 0; i < SLOTS; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const& name): ICharacter() {
	this->_name = name;
	for (int i = 0; i < SLOTS; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const& character) {
	for (int i = 0; i < SLOTS; i++)
		this->inventory[i] = NULL;
	*this = character;
}

Character::~Character(void) {
	for (int i = 0; i < SLOTS; i++)
		delete this->inventory[i];
}

Character& Character::operator=(Character const& character) { ///////////
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
	if (i == SLOTS)
		return ;
	this->inventory[i] = m;
	// problema: qdo se passa uma materia que já está no inventário...
}

void Character::unequip(int idx) {
	if (0 <= idx < SLOTS)
		this->inventory[idx] = NULL; /// tem que dar delete
	// The unequip() member function must NOT delete the Materia
}

void Character::use(int idx, ICharacter& target) {
	if (0 <= idx < SLOTS && this->inventory[idx])
		(*this->inventory[idx]).use(target);
}

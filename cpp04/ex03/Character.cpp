/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/26 23:50:53 by sguilher         ###   ########.fr       */
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
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(std::string const& name): ICharacter() {
    this->_name = name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::Character(Character const& character) {
	*this = character;
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++)
        delete this->inventory[i];
}

Character& Character::operator=(Character const& character) { ///////////
	if (this != &character) {
		this->_name = character.getName();
        for (int i = 0; i < 4; i++) {
            delete this->inventory[i];
            this->inventory[i] = character.inventory[i];
        }
	}
	return (*this);
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {
    int i = 0;
    while (i < 4) {
        if (this->inventory[i])
            i++;
        else
            break;
    }
    if (i == 4)
        return ;
    this->inventory[i] = m; // tá certo isso?? acho que não
}

void Character::unequip(int idx) {
    this->inventory[idx] = NULL; ///
}

void Character::use(int idx, ICharacter& target) {
    if (this->inventory[idx])
        (*this->inventory[idx]).use(target);
        // (*this->inventory[idx]).AMateria::use(target);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:28:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/24 23:45:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): ICharacter() {}

Character::Character(Character const& character){
	*this = character;
}

Character::~Character(void){}

Character& Character::operator=(Character const& character){ /////////////
	if (this != &character) {
		this->_name = character.getName();
	}
	return (*this);
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m) {

}

void Character::unequip(int idx) {

}

void Character::use(int idx, ICharacter& target) {

}

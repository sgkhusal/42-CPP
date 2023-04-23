/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:45:50 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 18:39:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat"){
	specificDescriptionPrint("WrongCat", "constructor", LIGHT_PURPLE);
}

WrongCat::~WrongCat(void){
	specificDescriptionPrint("WrongCat", "destructor", LIGHT_PURPLE);
}

WrongCat::WrongCat(WrongCat const& wrongCat){
	specificDescriptionPrint("WrongCat", "copy constructor", LIGHT_PURPLE);
	*this = wrongCat;
}

WrongCat& WrongCat::operator=(WrongCat const& wrongCat){
	// specificDescriptionPrint("WrongCat", "operator=", GREY);
	if (this != &wrongCat) {
		this->_type = wrongCat._type;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << ORANGE << "Miaw miaw" << RESET << std::endl;
}
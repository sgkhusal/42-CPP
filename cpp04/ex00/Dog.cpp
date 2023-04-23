/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:50:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 18:12:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"){
	specificDescriptionPrint("Dog", "constructor", YELLOW);
}

Dog::~Dog(void){
	specificDescriptionPrint("Dog", "destructor", YELLOW);
}

Dog::Dog(Dog const& dog){
	specificDescriptionPrint("Dog", "copy constructor", YELLOW);
	*this = dog;
}

Dog& Dog::operator=(Dog const& dog){
	// specificDescriptionPrint("Dog", "operator=", GREY);
	if (this != &dog) {
		this->_type = dog._type;
	}
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << ORANGE << "Woof woof" << RESET << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:45:50 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/24 23:21:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): AAnimal("Cat"){
	specificDescriptionPrint("Cat", "constructor", GREEN);
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->ideas[i] = "Cats are gods";
}

Cat::~Cat(void){
	specificDescriptionPrint("Cat", "destructor", GREEN);
	delete this->_brain;
}

Cat::Cat(Cat const& cat): AAnimal("Cat") {
	specificDescriptionPrint("Cat", "copy constructor", GREEN);
	this->_brain = new Brain();
	*this = cat;
}

Cat& Cat::operator=(Cat const& cat){
	specificDescriptionPrint("Cat", "operator=", GREY);
	if (this != &cat) {
		this->type = cat.type;
		*(this->_brain) = *(cat.getBrain());
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << ORANGE << "Miaw miaw" << RESET << std::endl;
}

Brain*	Cat::getBrain(void) const {
	return this->_brain;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:45:50 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 20:43:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"){
	specificDescriptionPrint("Cat", "constructor", GREEN);
	this->brain = new Brain();
}

Cat::~Cat(void){
	specificDescriptionPrint("Cat", "destructor", GREEN);
	delete this->brain;
}

Cat::Cat(Cat const& cat){
	specificDescriptionPrint("Cat", "copy constructor", GREEN);
	*this = cat;
}

Cat& Cat::operator=(Cat const& cat){
	// specificDescriptionPrint("Cat", "operator=", GREY);
	if (!this->brain)
		this->brain = new Brain(); ////////////
	if (this != &cat) {
		this->_type = cat._type;
		// *(this->brain) = *(cat.brain);
		for(int i = 0; i < 100; i++)
			this->brain[i] = cat.brain[i];
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << ORANGE << "Miaw miaw" << RESET << std::endl;
}
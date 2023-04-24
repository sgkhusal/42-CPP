/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:50:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 20:19:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"){
	specificDescriptionPrint("Dog", "constructor", YELLOW);
	this->brain = new Brain();
}

Dog::~Dog(void){
	specificDescriptionPrint("Dog", "destructor", YELLOW);
	delete this->brain;
}

Dog::Dog(Dog const& dog){
	specificDescriptionPrint("Dog", "copy constructor", YELLOW);
	*this = dog;
}

Dog& Dog::operator=(Dog const& dog){
	// specificDescriptionPrint("Dog", "operator=", GREY);
	if (!this->brain)
		this->brain = new Brain(); ////////////
	if (this != &dog) {
		this->_type = dog._type;
		for(int i = 0; i < 100; i++)
			this->brain[i] = dog.brain[i];
	}
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << ORANGE << "Woof woof" << RESET << std::endl;
}
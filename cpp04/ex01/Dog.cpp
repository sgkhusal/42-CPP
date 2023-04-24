/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:50:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 22:16:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"){
	specificDescriptionPrint("Dog", "constructor", YELLOW);
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->ideas[i] = "Dog is man's best friend";
}

Dog::~Dog(void){
	specificDescriptionPrint("Dog", "destructor", YELLOW);
	delete this->_brain;
}

Dog::Dog(Dog const& dog){
	specificDescriptionPrint("Dog", "copy constructor", YELLOW);
	this->_brain = new Brain();
	*this = dog;
}

Dog& Dog::operator=(Dog const& dog){
	specificDescriptionPrint("Dog", "operator=", GREY);
	// if (!this->_brain)
	// 	this->_brain = new Brain(); ////////////
	if (this != &dog) {
		this->_type = dog._type;
		*(this->_brain) = *(dog.getBrain());
	}
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << ORANGE << "Woof woof" << RESET << std::endl;
}

Brain*	Dog::getBrain(void) const {
	return this->_brain;
}

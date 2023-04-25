/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:50:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/25 02:44:54 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"){
	specificDescriptionPrint("Dog", "constructor", YELLOW);
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->ideas[i] = "Play with me";
}

Dog::~Dog(void){
	specificDescriptionPrint("Dog", "destructor", YELLOW);
	delete this->_brain;
}

Dog::Dog(Dog const& dog): Animal(dog) {
	specificDescriptionPrint("Dog", "copy constructor", YELLOW);
	this->_brain = new Brain();
	*this = dog;
}

Dog& Dog::operator=(Dog const& dog){
	specificDescriptionPrint("Dog", "operator=", GREY);
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

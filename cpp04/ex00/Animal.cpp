/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:22 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/20 11:15:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void){
	this->_type = "animal";
	std::cout << BLUE << "Animal class constructor called" << RESET << std::endl;
}

Animal::~Animal(void){
	std::cout << BLUE << "Animal class destructor called" << RESET << std::endl;
}

Animal::Animal(Animal const& animal){
	*this = animal;
	std::cout << GREY << "Animal copy constructor called" << RESET << std::endl;
}

Animal& Animal::operator=(Animal const& animal){
	if (this != &animal) {
		this->_type = animal._type;
	}
	std::cout << GREY << "Animal operator= called" << RESET << std::endl;
	return (*this);
}

std::string	Animal::getType(void){
	return this->_type;
}

// precisa implementar a makeSound nesses exercícios para a Animal?
void	Animal::makeSound(void){
	std::cout << ORANGE << "Some undefined strange noise" << RESET << std::endl;
}
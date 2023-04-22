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

Animal::Animal(void): _type("Undefined") {
	genericDescriptionPrint("constructor", BLUE);
}

Animal::Animal(std::string type): _type(type) {
	genericDescriptionPrint("constructor", BLUE);
}

Animal::~Animal(void){
	genericDescriptionPrint("destructor", BLUE);
}

Animal::Animal(Animal const& animal){
	*this = animal;
	genericDescriptionPrint("copy constructor", GREY);
}

Animal& Animal::operator=(Animal const& animal){
	if (this != &animal) {
		this->_type = animal._type;
		std::cout << "Entramos aqui. Type: " << this->_type << std::endl;
	}
	genericDescriptionPrint("operator=", GREY);
	return (*this);
}

std::string	Animal::getType(void) const {
	return this->_type;
}

// precisa implementar a makeSound nesses exercícios para a Animal?
void	Animal::makeSound(void) const {
	std::cout << ORANGE << "Some undefined strange noise" << RESET << std::endl;
}

void	Animal::genericDescriptionPrint(
	std::string description,
	std::string color
	) {
	std::cout << color << "Animal class " << description
			<< " called for type " << this->getType() << RESET << std::endl;
}

void	Animal::specificDescriptionPrint(
	std::string class_name,
	std::string description,
	std::string color
	) {
	std::cout << color << class_name << " class " << description
			<< " called" << RESET << std::endl;
}
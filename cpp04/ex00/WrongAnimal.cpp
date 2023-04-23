/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:22 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 18:35:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("Undefined") {
	genericDescriptionPrint("constructor", CYAN);
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	genericDescriptionPrint("constructor", CYAN);
}

WrongAnimal::~WrongAnimal(void){
	genericDescriptionPrint("destructor", CYAN);
}

WrongAnimal::WrongAnimal(WrongAnimal const& wrongAnimal){
	*this = wrongAnimal;
	genericDescriptionPrint("copy constructor", CYAN);
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& wrongAnimal){
	if (this != &wrongAnimal) {
		this->_type = wrongAnimal._type;
	}
	// genericDescriptionPrint("operator=", GREY);
	return (*this);
}

std::string	WrongAnimal::getType(void) const {
	return this->_type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << ORANGE << "Some undefined strange noise" << RESET << std::endl;
}

void	WrongAnimal::genericDescriptionPrint(
	std::string description,
	std::string color
	) {
	std::cout << color << "WrongAnimal class " << description
			<< " called for type " << this->getType() << RESET << std::endl;
}

void	WrongAnimal::specificDescriptionPrint(
	std::string class_name,
	std::string description,
	std::string color
	) {
	std::cout << color << class_name << " class " << description
			<< " called" << RESET << std::endl;
}
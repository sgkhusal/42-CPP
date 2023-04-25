/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:22 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 22:17:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("Undefined") {
	genericDescriptionPrint("constructor", BLUE);
}

AAnimal::AAnimal(std::string const& type): type(type) {
	genericDescriptionPrint("constructor", BLUE);
}

AAnimal::~AAnimal(void){
	genericDescriptionPrint("destructor", BLUE);
}

AAnimal::AAnimal(AAnimal const& animal){
	*this = animal;
	genericDescriptionPrint("copy constructor", BLUE);
}

AAnimal& AAnimal::operator=(AAnimal const& animal){
	genericDescriptionPrint("operator=", GREY);
	if (this != &animal) {
		this->type = animal.type;
	}
	return (*this);
}

std::string	const& AAnimal::getType(void) const {
	return this->type;
}

void	AAnimal::genericDescriptionPrint(
	std::string description,
	std::string color
	) {
	std::cout << color << "AAnimal class " << description
			<< " called for type " << this->getType() << RESET << std::endl;
}

void	AAnimal::specificDescriptionPrint(
	std::string class_name,
	std::string description,
	std::string color
	) {
	std::cout << color << class_name << " class " << description
			<< " called" << RESET << std::endl;
}

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

Cat::Cat(void): Animal("Cat"){
	specificDescriptionPrint("Cat", "constructor", GREEN);
}

Cat::~Cat(void){
	specificDescriptionPrint("Cat", "destructor", GREEN);
}

Cat::Cat(Cat const& cat): Animal("Cat") {
	specificDescriptionPrint("Cat", "copy constructor", GREEN);
	*this = cat;
}

Cat& Cat::operator=(Cat const& cat){
	specificDescriptionPrint("Cat", "operator=", GREY);
	if (this != &cat) {
		this->type = cat.type;
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << ORANGE << "Miaw miaw" << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:45:50 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/20 11:50:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal(){
	this->_type = "cat";
	std::cout << GREEN << "Cat class constructor called" << RESET << std::endl;
}

Cat::~Cat(void){
	std::cout << GREEN << "Cat class destructor called" << RESET << std::endl;
}

Cat::Cat(Cat const& cat){
	*this = cat;
	std::cout << GREY << "Cat copy constructor called" << RESET << std::endl;
}

Cat& Cat::operator=(Cat const& cat){
	if (this != &cat) {
		this->_type = cat._type;
	}
	std::cout << GREY << "Cat operator= called" << RESET << std::endl;
	return (*this);
}

void	Cat::makeSound(void){
	std::cout << ORANGE << "Miaw miaw" << RESET << std::endl;
}
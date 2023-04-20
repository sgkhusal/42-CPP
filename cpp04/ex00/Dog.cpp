/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:50:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/20 11:51:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal(){
	this->_type = "Dog";
	std::cout << GREEN << "Dog class constructor called" << RESET << std::endl;
}

Dog::~Dog(void){
	std::cout << GREEN << "Dog class destructor called" << RESET << std::endl;
}

Dog::Dog(Dog const& dog){
	*this = dog;
	std::cout << GREY << "Dog copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(Dog const& dog){
	if (this != &dog) {
		this->_type = dog._type;
	}
	std::cout << GREY << "Dog operator= called" << RESET << std::endl;
	return (*this);
}

void	Dog::makeSound(void){
	std::cout << ORANGE << "Miaw miaw" << RESET << std::endl;
}
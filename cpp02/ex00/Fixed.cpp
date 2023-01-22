/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:16 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/20 16:22:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed(void): _rawBits(0) {
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	return ;
}

Fixed::Fixed(Fixed const& fixed) {
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = fixed;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << ORANGE << "Destructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(Fixed const& fixed) {
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	if (this != &fixed)
		this->_rawBits = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << GREY << "getRawBits member function called" << RESET << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
	return ;
}

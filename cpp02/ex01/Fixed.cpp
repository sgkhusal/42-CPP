/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:16 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/22 12:30:05 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;
const int Fixed::_float_conversion = 1 << Fixed::_fractional_bits;

Fixed::Fixed(void): _rawBits(0) {
	Fixed::_constructor_called("Default");
	return ;
}

Fixed::Fixed(Fixed const& fixed) {
	Fixed::_constructor_called("Copy");
	*this = fixed;
	return ;
}

Fixed::Fixed(int const integer) {
	Fixed::_constructor_called("Int");
	this->_rawBits = integer * Fixed::_float_conversion;
	std::cout << GREY << integer;
	_print_storage_value(this->getRawBits());
	return ;
}

Fixed::Fixed(float const f) {
	Fixed::_constructor_called("Float");
	this->_rawBits = (int)roundf(f * Fixed::_float_conversion);
	std::cout << GREY << f;
	_print_storage_value(this->getRawBits());
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
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
	return ;
}

float	Fixed::toFloat(void) const {
	return ((float)this->getRawBits() / (float)Fixed::_float_conversion);
}

int	Fixed::toInt(void) const {
	return (this->_rawBits >> Fixed::_fractional_bits);
}

void	Fixed::_print_storage_value(int raw) {
	std::cout << GREY << ": value set as an integer of value "
			<< raw << RESET << std::endl;
}

void	Fixed::_constructor_called(std::string type) {
	std::cout << GREEN << type << " constructor called" << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& o, Fixed const& fixed) {
	o << fixed.toFloat();
	return (o);
}

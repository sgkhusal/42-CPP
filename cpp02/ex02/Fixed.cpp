/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:16 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/22 16:18:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;
const int Fixed::_float_conversion = 1 << Fixed::_fractional_bits;

Fixed::Fixed(void): _rawBits(0) { }

Fixed::Fixed(Fixed const& fixed) {
	*this = fixed;
	return ;
}

Fixed::Fixed(int const integer) {
	this->_rawBits = integer * Fixed::_float_conversion;
	return ;
}

Fixed::Fixed(float const f) {
	this->_rawBits = (int)roundf(f * Fixed::_float_conversion);
	return ;
}

Fixed::~Fixed(void) { }

Fixed& Fixed::operator=(Fixed const& b) {
	if (this != &b)
		this->_rawBits = b.getRawBits();
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

std::ostream& operator<<(std::ostream& o, Fixed const& fixed) {
	o << fixed.toFloat();
	return (o);
}

bool Fixed::operator>(Fixed const& b) const {
	if (this->getRawBits() > b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const& b) const {
	if (this->getRawBits() < b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const& b) const {
	if (this->getRawBits() >= b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const& b) const {
	if (this->getRawBits() <= b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const& b) const {
	if (this->getRawBits() == b.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const& b) const {
	if (this->getRawBits() != b.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(Fixed const& b) const {
	return (Fixed(this->toFloat() + b.toFloat()));
}

Fixed Fixed::operator-(Fixed const& b) const {
	return (Fixed(this->toFloat() - b.toFloat()));
}

Fixed Fixed::operator*(Fixed const& b) const {
	return (Fixed(this->toFloat() * b.toFloat()));
}

Fixed Fixed::operator/(Fixed const& b) const {
	return (Fixed(this->toFloat() / b.toFloat()));
}

// ++a
Fixed& Fixed::operator++(void) {
	this->_rawBits += 1;
	return (*this);
}

Fixed& Fixed::operator--(void) {
	this->_rawBits -= 1;
	return (*this);
}

// a++
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_rawBits++;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_rawBits--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a <= b ? a : b);
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b) {
	return (a <= b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a >= b ? a : b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b) {
	return (a >= b ? a : b);
}

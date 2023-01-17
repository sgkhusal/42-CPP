/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:39:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/17 00:27:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"

Integer::Integer(int const n): _n(n) {
	std::cout << "Constructor called with value " << n << std::endl;
}

Integer::~Integer(void) {
	std::cout << "Destructor called with value " << this->getValue() << std::endl;
}

int Integer::getValue(void) const {
	return (this->_n);
}

Integer& Integer::operator=(Integer const & rhs) {
	std::cout << "Assignation operator called from " << this->getValue()
			<< " to " << rhs.getValue() << std::endl;
	this->_n = rhs.getValue();
	return (*this);
}

Integer Integer::operator+(Integer const & rhs) const {
	std::cout << "Addition operator called with " << this->getValue() << " and "
			<< rhs.getValue() << std::endl;
	return (Integer(this->getValue() + rhs.getValue()));
}

std::ostream& operator<<(std::ostream& o, Integer const& rhs) {
	o << rhs.getValue();
	return (o);
}

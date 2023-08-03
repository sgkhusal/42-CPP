/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:17:46 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/02 23:50:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t n) {
	this->_numbers.reserve(n);
	if (DEBUG)
		std::cout << GREY
				<< "Span created with capacity " << this->_numbers.capacity()
				<< " and size " << this->_numbers.size()
				<< RESET << std::endl;
}

Span::Span(Span const &span) {
	*this = span;
}

Span::~Span(void) { }

Span const &Span::operator=(Span const &span) {
	if (this != &span)
		this->_numbers = span.getSpan();
	return *this;
}

std::vector<int> Span::getSpan(void) const {
	return this->_numbers;
}

void Span::addNumber(int number) {
	if (this->_numbers.size() == this->_numbers.capacity())
		throw FullSpanException();
	this->_numbers.push_back(number);
	if (DEBUG)
		std::cout << GREY << number << " added - span size: "
				<< this->_numbers.size() << RESET << std::endl;
}

size_t Span::shortestSpan(void) const {
	if (this->_numbers.size() < 2)
		throw NoSpanException();
	return 2;
	// calculate span
}

size_t Span::longestSpan(void) const {
	if (this->_numbers.size() < 2)
		throw NoSpanException();
	return this->_numbers.size();
	// int min_value = std::min()
	// calculate span
}

const char *Span::FullSpanException::what() const throw() {
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "span not found: Span size must be greater than one";
}

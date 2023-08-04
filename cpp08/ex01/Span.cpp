/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:17:46 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/04 01:59:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t n) {
	this->_capacity = n;
	if (DEBUG)
		std::cout << GREY
				<< "Span created with capacity " << this->_capacity
				<< " and size " << this->_span.size() << RESET << std::endl;
}

Span::Span(Span const &span) {
	*this = span;
}

Span::Span(void) { }
Span::~Span(void) { }

Span const &Span::operator=(Span const &span) {
	if (this != &span) {
		this->_span = span.getSpan();  // verify if multiset copy is deep
		this->_capacity = span.capacity();
	}
	return *this;
}

multiset_itr Span::backIterator(void) const {
	return --(this->_span.end());  // check
}

std::multiset<int> Span::getSpan(void) const {
	return this->_span;
}

size_t Span::capacity(void) const {
	return this->_capacity;
}

void Span::addNumber(int number) {
	if (this->_span.size() == this->_capacity)
		throw FullSpanException();

	multiset_itr it = this->_span.insert(number);

	if (DEBUG)
		std::cout << GREY << *it << " added - span size: "
				<< this->_span.size() << RESET << std::endl;
}

size_t Span::shortestSpan(void) const {
	if (this->_span.size() < 2)
		throw NoSpanException();

	multiset_itr begin = this->_span.begin();
	int span = std::abs(*begin - *(++begin)); // check result

	multiset_itr it = begin;
	multiset_itr back = this->backIterator();
	int tmp;
	while (it != back) {
		tmp = abs(*it - *(++it));
		span = std::min(span, tmp);
	}

	return span;
}

size_t Span::longestSpan(void) const {
	if (this->_span.size() < 2)
		throw NoSpanException();

	return *(this->backIterator()) - *(this->_span.begin());
}

const char *Span::FullSpanException::what() const throw() {
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "span not found: Span size must be greater than one";
}

std::ostream& operator<<(std::ostream& o, Span const& s) {
	multiset_itr it;
	multiset_itr back = s.backIterator();

	for (it = s.getSpan().begin(); it != back; it++)
		o << *it << " ";
	o << *back;
	return o;
}
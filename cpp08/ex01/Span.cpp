/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:17:46 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/04 18:12:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t n) {
	this->_capacity = n;
	if (DEBUG)
		std::cout << GREY
				<< "Span created with capacity " << this->capacity()
				<< " and size " << this->size() << RESET << std::endl;
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

size_t Span::size(void) const {
	return this->_span.size();
}

size_t Span::capacity(void) const {
	return this->_capacity;
}

multiset_itr Span::begin(void) const {
	return this->_span.begin();
}

multiset_itr Span::end(void) const {
	return this->_span.end();
}

multiset_itr Span::backIterator(void) const {
	if (this->size() == 1)
		return this->begin();
	return --(this->_span.end());
}

std::multiset<int> Span::getSpan(void) const {
	return this->_span;
}

void Span::addNumber(int number) {
	if (this->size() == this->capacity())
		throw FullSpanException();

	multiset_itr it = this->_span.insert(number);

	if (DEBUG)
		std::cout << GREY << *it << " added - span size: "
				<< this->size() << RESET << std::endl;
}

size_t Span::shortestSpan(void) const {
	if (this->size() < 2)
		throw NoSpanException();

	multiset_itr begin = this->begin();
	int span = std::abs(*begin - *(++begin));

	multiset_itr it = begin;
	multiset_itr back = this->backIterator();
	int tmp;
	while (it != back) {
		tmp = abs(*it - *(++it));
		span = std::min(span, tmp);
		if (span == 0)
			return span;
	}

	return span;
}

size_t Span::longestSpan(void) const {
	if (this->size() < 2)
		throw NoSpanException();

	return *(this->backIterator()) - *(this->begin());
}

const char *Span::FullSpanException::what() const throw() {
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "Span size must be greater than one";
}

std::ostream& operator<<(std::ostream& o, Span const& s) {
	multiset_itr it, back;

	if (s.size() == 0) {
		o << "Empty span";
		return o;
	}

	back = s.backIterator();
	for (it = s.begin(); it != back; it++)
		o << *it << " ";
	o << *back;

	return o;
}
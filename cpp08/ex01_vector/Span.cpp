/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:17:46 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/04 18:45:52 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t n) {
	this->_span.reserve(n);
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
		this->_span = span.getSpan();
	}
	return *this;
}

size_t Span::size(void) const {
	return this->_span.size();
}

size_t Span::capacity(void) const {
	return this->_span.capacity();
}

const_vector_itr Span::begin(void) const {
	return this->_span.begin();
}

const_vector_itr Span::end(void) const {
	return this->_span.end();
}

vector_itr Span::begin(void) {
	return this->_span.begin();
}

vector_itr Span::end(void) {
	return this->_span.end();
}

const_vector_itr Span::backIterator(void) const {
	if (this->size() == 1)
		return this->begin();
	return --(this->_span.end());
}

std::vector<int> Span::getSpan(void) const {
	return this->_span;
}

void Span::addNumber(int number) {
	if (this->size() == this->capacity())
		throw FullSpanException();

	this->_span.push_back(number);

	if (DEBUG)
		std::cout << GREY << number << " added - size: "
				<< this->size() << RESET << std::endl;
}

size_t Span::shortestSpan(void) const {
	std::vector<int> copy;
	const_vector_itr begin, back, it;
	int span, tmp;

	if (this->size() < 2)
		throw NoSpanException();

	copy = this->_span;
	std::sort(copy.begin(), copy.end());

	begin = copy.begin();
	span = std::abs(*begin - *(++begin));

	it = begin;
	back = --(copy.end());
	while (it != back) {
		tmp = abs(*it - *(++it));
		span = std::min(span, tmp);
		if (span == 0)
			return span;
	}

	return span;
}

size_t Span::longestSpan(void) const {
	const_vector_itr min, max;

	if (this->size() < 2)
		throw NoSpanException();

	min = std::min_element(this->begin(), this->end());
	max = std::max_element(this->begin(), this->end());

	return *max - *min;
}

const char *Span::FullSpanException::what() const throw() {
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw() {
	return "Span size must be greater than one";
}

std::ostream& operator<<(std::ostream& o, Span const& s) {
	const_vector_itr it, back;

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
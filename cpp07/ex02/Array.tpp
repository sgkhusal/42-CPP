/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:53 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/29 20:48:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template< typename T >
Array<T>::Array(void): _array(NULL), _size(0) {
	_printDescription("Default constructor called");
	this->_array = new T[0];
}

template< typename T >
Array<T>::Array(size_t n): _array(NULL), _size(n) {
	_printDescription("Unsigned int constructor called");
	this->_array = new T[n](); // verificar se o () é válido para qualquer tipo
}

template< typename T >
Array<T>::Array(Array<T> const& array): _array(NULL) {
	_printDescription("Copy constructor called");
	*this = array;
}

template< typename T >
Array<T>::~Array(void) {
	_printDescription("Destructor called");
	if (this->_array)
		delete[] this->_array;
}

template< typename T >
Array<T> const& Array<T>::operator=(Array<T> const& array) {
	_printDescription("Array assigned operator called");
	if (this != &array) {
		if (this->_array)
			delete[] this->_array;
		this->_size = array.size();
		this->_array = new T[this->_size];
		for (size_t i = 0; i < this->_size; i++)
			this->_array[i] = array[i];
	}
	return *this;
}

template< typename T > //////////////////////////////////////////////////////////
T const& Array<T>::operator=(T const& value) {
	_printDescription("T assigned operator called");
	return value;
}

template< typename T >
T& Array<T>::operator[](size_t idx) {
	_printDescription("[] operator called");
	if (idx >= this->_size) // verificar se funciona para size = 0 e valores negativos
		throw Array<T>::IndexOutOfBounds();
	return this->_array[idx];
}

template< typename T >
T const& Array<T>::operator[](size_t idx) const {
	_printDescription("const [] operator called");
	if (idx >= this->_size) // verificar se funciona para size = 0 e valores negativos
		throw Array<T>::IndexOutOfBounds();
	return this->_array[idx];
}

template< typename T >
size_t  Array<T>::size(void) const {
	return this->_size;
}

template< typename T >
const char* Array<T>::IndexOutOfBounds::what() const throw() {
	return "Index out of bounds";
}

template< typename T >
void Array<T>::_printDescription(std::string const& description) {
	if (DEBUG)
		std::cout << GREY << description << RESET << std::endl;
}

template< typename T >
std::ostream& operator<<(std::ostream& o, Array<T> const& p) {
	o << "Array of size " << p.size() << ": ";
	for (size_t i = 0; i < p.size(); i++)
		o << p[i] << " ";
	return o;
}

template< >
std::ostream& operator<<(std::ostream& o, Array<char> const& c) {
	o << "Array of size " << c.size() << ": ";
	for (size_t i = 0; i < c.size(); i++) {
		if(c[i])
			o << c[i] << " ";
		else
			o << "|" << c[i] << "| ";
	}
	return o;
}

template< >
std::ostream& operator<<(std::ostream& o, Array<std::string> const& s) {
	o << "Array of size " << s.size() << ": ";
	for (size_t i = 0; i < s.size(); i++)
		o << "|" << s[i] << "| ";
	return o;
}

template< >
std::ostream& operator<<(std::ostream& o, Array<bool> const& b) {
	o << "Array of size " << b.size() << ": ";
	for (size_t i = 0; i < b.size(); i++) {
		if(b[i])
			o << "true  ";
		else
			o << "false ";
	}
	return o;
}

#endif

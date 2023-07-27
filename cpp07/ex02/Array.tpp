/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:53 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/27 00:46:30 by sguilher         ###   ########.fr       */
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
Array<T>& Array<T>::operator=(Array<T> const& array) {
	_printDescription("Assigned operator called");
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

template< typename T >
T& Array<T>::operator[](size_t idx) {
	_printDescription("[] operator called");
	if (idx >= this->_size) // verificar se funciona para size = 0 e valores negativos
		throw Array<T>::IndexOutOfBounds();
	return this->_array[idx];
}

// template< typename T >
// T*      array(void) const;
// template< typename T >
// T Array<T>::getElement(size_t idx) const {
// 	return this->_array[idx];
// }
// template< typename T >
// void    setArray();  // ver se vou precisar
// template< typename T >
// void    setElementArray(size_t const idx, T value);

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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:53 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/20 12:23:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template< typename T >
Array<T>::Array(void): _array(NULL), _size(0) {
	if (DEBUG)
		std::cout << GREY << "Default constructor called" << RESET << std::endl;
	this->_array = new T[0];  // precisa disso?
}

template< typename T >
Array<T>::~Array(void) {
	if (DEBUG)
		std::cout << GREY << "Destructor called" << RESET << std::endl;
}

// template< typename T >
// Array(Array const& array) {
	
// }

// template< typename T >
// Array& operator=(Array const& array) {}

// template< typename T >
// Array(size_t n) {}
// template< typename T >
// T& operator[](size_t idx);

// template< typename T >
// T*      array(void) const;
// template< typename T >
// T       getElement(size_t idx) const;
// template< typename T >
// void    setArray();  // ver se vou precisar
// template< typename T >
// void    setElementArray(size_t const idx, T value);

// template< typename T >
// size_t  size(void) const;

// template< typename T >
// const char* Array<T>::IndexOutOfBounds::what() const throw() {

// }

#endif

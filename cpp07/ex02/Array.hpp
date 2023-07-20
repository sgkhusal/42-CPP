/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:56 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/20 12:23:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstring>
# include <iostream>

# define BLUE	"\033[38;5;75m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

# ifndef DEBUG
    #define DEBUG false
# endif

template< typename T >
class Array {
	public:
		Array<T>(void);
		~Array(void);
		Array(Array const& array);
		Array& operator=(Array const& array);

		Array(size_t n);
		T& operator[](size_t idx);

		T*	array(void) const;
		T	  getElement(size_t idx) const;
		void	setArray();  // ver se vou precisar
		void	setElementArray(size_t const idx, T value);

		size_t  size(void) const;

		class IndexOutOfBounds: public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		T*   _array;
		size_t _size;

};

# include "Array.tpp"

#endif

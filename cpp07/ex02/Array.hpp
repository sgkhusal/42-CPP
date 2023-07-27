/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:56 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/27 13:05:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstring>
# include <iostream>

# define BLUE	"\033[38;5;75m"
# define ORANGE	"\033[0;38;5;166m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

# ifndef DEBUG
    #define DEBUG false
# endif

template< typename T >
class Array {
	public:
		Array<T>(void);
		Array(size_t n);
		Array(Array<T> const& array);
		~Array(void);
		
		Array<T> const& operator=(Array<T> const& array);
		T const& operator=(T const& value);
		T& operator[](size_t idx);
		// T const& operator[](size_t idx);
		// Array<T>& operator[](size_t idx);

		// T*		array(void) const;
		// T		getElement(size_t idx) const;
		// void	setArray();  // ver se vou precisar
		// void	setElementArray(size_t const idx, T value);

		size_t  size(void) const;

		class IndexOutOfBounds: public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		T*   _array;
		size_t _size;

		static void _printDescription(std::string const& description);
};

# include "Array.tpp"

#endif

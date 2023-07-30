/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:56 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/29 21:40:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstring>
# include <iostream>

# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
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
		T& operator[](size_t idx);
		T const& operator[](size_t idx) const;

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

template< typename T >
std::ostream& operator<<(std::ostream& o, Array<T> const& p);

# include "Array.tpp"

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:09:44 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/02 22:08:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iterator>
# include <iostream>

# define BLUE	"\033[38;5;75m"
# define ORANGE	"\033[0;38;5;166m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

namespace ex00 {

template<typename T>
typename T::iterator easyfind(T const& container, int number);

class NumberNotFound: public std::exception {
	public:
		virtual const char* what() const throw();
};

template<typename T>
void test(T const& container, int number);

} // namespace ex00

# include "easyfind.tpp"

#endif
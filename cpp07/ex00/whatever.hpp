/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:14:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/16 00:08:00 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# define BLUE	"\033[38;5;75m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

template<typename T>
void swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T const& min(T const&a, T const& b) {
	return a < b ? a : b;
}

template<typename T>
T const& max(T const& a, T const& b) {
	return a > b ? a : b;
}

template<typename T>
void test(T& a, T& b) {
	static int n = 0;

	n++;
	std::cout << BLUE << "Test " << n << ": (" << a << ", " << b << ")"
			<< GREY << std::endl;
	std::cout << "a pointer: " << &a << std::endl;
	std::cout << "b pointer: " << &b << std::endl;
	::swap( a, b );
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b )
			<< " | pointer: " << &(::min( a, b )) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b )
			<< " | pointer: " << &(::max( a, b )) << std::endl;
	std::cout << RESET << std::endl;
}

#endif

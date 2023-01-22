/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/22 16:26:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << PURPLE << "********* Comparison operators *********"
			<< RESET << std::endl;
	std::cout << YELLOW << "a = " << a << " and b = " << b << std::endl;
	std::cout << GREY << "a < b: " << (a < b ? "true" : "false") << std::endl;
	std::cout << GREY << "a > b: " << (a > b ? "true" : "false") << std::endl;
	std::cout << GREY << "a <= b: " << (a <= b ? "true" : "false") << std::endl;
	std::cout << GREY << "a >= b: " << (a >= b ? "true" : "false") << std::endl;
	std::cout << GREY << "a == b: " << (a == b ? "true" : "false") << std::endl;
	std::cout << GREY << "a != b: " << (a != b ? "true" : "false") << std::endl;

	std::cout << std::endl;
	std::cout << PURPLE << "********* Arithmetic operators *********"
			<< RESET << std::endl;
	a = Fixed(1.5f);
	Fixed	c(0.5f);
	std::cout << YELLOW << "a = " << a << " and c = " << c << std::endl;
	std::cout << GREY << "a + c = " << a + c << std::endl;
	std::cout << GREY << "a - c = " << a - c << std::endl;
	std::cout << GREY << "a * c = " << a * c << std::endl;
	std::cout << GREY << "a / c = " << a / c << std::endl;
	std::cout << std::endl;
	return (0);
}

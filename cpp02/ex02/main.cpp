/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/22 16:49:06 by sguilher         ###   ########.fr       */
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
	Fixed const c(8.388607f);
	std::cout << YELLOW << "Others: c = " << c << std::endl;
	std::cout << GREY << "c > c: " << (c > c ? "true" : "false") << std::endl;
	std::cout << GREY << "c < c: " << (c < c ? "true" : "false") << std::endl;
	std::cout << GREY << "c >= c: " << (c >= c ? "true" : "false") << std::endl;
	std::cout << GREY << "c <= c: " << (c <= c ? "true" : "false") << std::endl;
	std::cout << GREY << "c == c: " << (c == c ? "true" : "false") << std::endl;
	std::cout << GREY << "c != c: " << (c != c ? "true" : "false") << std::endl;

	std::cout << std::endl;
	std::cout << PURPLE << "********* Arithmetic operators *********"
			<< RESET << std::endl;
	a = Fixed(1.5f);
	Fixed const d(0.5f);
	std::cout << YELLOW << "a = " << a << " and d = " << d << std::endl;
	std::cout << GREY << "a + d = " << a + d << std::endl;
	std::cout << GREY << "a - d = " << a - d << std::endl;
	std::cout << GREY << "a / d = " << a / d << RESET << std::endl;
	Fixed e = Fixed(0);
	std::cout << YELLOW << "a = " << a << " and e = " << 0 << std::endl;
	std::cout << GREY << "a * d = " << a * e << std::endl;
	std::cout << GREY << "a / d = " << a / e << RESET << std::endl;
	std::cout << std::endl;
	return (0);
}

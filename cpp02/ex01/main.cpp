/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/22 12:29:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void	additional_integer_tests(int integer, std::string description) {
	Fixed		fixed;
	static int	n = 1;

	std::cout << YELLOW << "2." << n << ". Testing " << description
			<< RESET << std::endl;
	fixed = Fixed(integer);
	std::cout << "fixed is " << fixed << std::endl;
	std::cout << "fixed is " << fixed.toInt() << " as integer" << std::endl;
	std::cout << std::endl;
	n++;
}

static void	additional_float_tests(float f) {
	Fixed		fixed;
	static int	n = 1;

	std::cout << YELLOW << "1." << n << ". " << f << RESET << std::endl;
	fixed = Fixed(f);
	std::cout << "fixed is " << fixed << std::endl;
	std::cout << "fixed is " << fixed.toInt() << " as integer" << std::endl;
	std::cout << std::endl;
	n++;
}

static void	additional_tests(void) {
	std::cout << PURPLE << "********* Additional tests *********"
			<< RESET << std::endl;
	std::cout << std::endl;
	std::cout << YELLOW << "1. Testing float rounding" << RESET << std::endl;
	additional_float_tests(1234.4391f);
	additional_float_tests(8.388607);
	additional_float_tests(-65536.5);
	additional_integer_tests(-1,
					"a negative number conversion: n = -1");
	additional_integer_tests(8388607,
				"integer positive limit overflow: n >= 2 ^ 23 - 1 = 8388607");
	additional_integer_tests(8388608,
				"integer first positive overflow: n >= 2 ^ 23 = 8388608");
	additional_integer_tests(-8388608,
				"integer negative limit overflow: n <= - 2 ^ 23 = -8388608");
	additional_integer_tests(-8388609,
				"integer first negative overflow: -8388609");
	additional_integer_tests(16777216,
				"integer overflow: n >= 2 ^ 24 = 16777216");
}

int	main(void) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl;
	additional_tests();
	return (0);
}

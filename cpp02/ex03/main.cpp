/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/22 22:46:31 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void test_bsp(Point const a, Point const b, Point const c,
						Point const p, bool expected) {
	static int n = 1;

	std::cout << GREY << "A = (" << a.getX() << ", " << a.getY() << "), "
			<< "B = (" << b.getX() << ", " << b.getY() << "), "
			<< "C = (" << c.getX() << ", " << c.getY() << "), "
			<< "P = (" << p.getX() << ", " << p.getY() << "): ";
	if (bsp(a, b, c, p) == expected)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << RED << "KO" << RESET << std::endl;
	n++;
}

int	main(void) {
	Point	a(0, 0);
	Point	b(10, 30);
	Point	c(20, 0);

	std::cout << std::endl;
	std::cout << PURPLE << "******************** bsp tests ********************"
			<< RESET << std::endl << std::endl;
	std::cout << YELLOW << "Point inside" << std::endl;
	test_bsp(a, b, c, Point(10, 15), true);
	test_bsp(a, b, c, Point(10, 0), true);
	test_bsp(a, b, c, Point(15, 15), true);
	test_bsp(Point(0, -10), b, c, Point(5, -5), true);
	test_bsp(Point(7, 7), Point(11, 1), Point(2, 2), Point(7, 3), true);
	std::cout << std::endl << YELLOW << "Point outside" << std::endl;
	test_bsp(a, b, c, Point(15, 15.002f), false);
	test_bsp(a, b, c, Point(30, 15), false);
	test_bsp(Point(0, -10), b, c, Point(15, -15), false);
	test_bsp(Point(0, 10), b, c, Point(15, -5), false);
	std::cout << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:15:13 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/02 21:04:48 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	std::string type = "int";

	test(a, b, type);
	a = b;
	test(a, b, type);

	std::string c = "chaine1";
	std::string d = "chaine2";
	type = "std::string";

	test(c, d, type);
	c = d;
	test(c, d, type);

	float e = 3.14f, f = 4.2f;
	type = "float";
	test(e, f, type);
	e = f;
	test(e, f, type);

	int const g = 42;
	int const h = 21;
	std::cout << BLUE << "Test const - 1: (" << g << ", " << h << ")"
			<< GREY << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
	std::cout << RESET << std::endl;

	return 0;
}

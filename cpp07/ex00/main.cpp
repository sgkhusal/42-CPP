/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:15:13 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/24 20:56:32 by sguilher         ###   ########.fr       */
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

	return 0;
}

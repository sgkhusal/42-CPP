/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:30:49 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/09 21:41:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

void printTypeGenerated(std::string const& name) {
	std::cout << "Creating an object of class " << name << "..." << std::endl;
}

Base* generate(void) {
	static bool seed = false;
	int n;

	if (!seed) {
		srand(time(NULL));
		seed = true;
	}
	n = rand() % 3;
	switch (n)
	{
		case 0:
			printTypeGenerated("A");
			return new A;
		case 1:
			printTypeGenerated("B");
			return new B;
		default:
			printTypeGenerated("C");
			return new C;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer to class type 'A'" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer to class type 'B'" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer to class type 'C'" << std::endl;
	else
		std::cerr << ORANGE
			<< "Pointer is not a pointer to a class derived from Base class"
			<< RESET << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference to class type 'A'" << std::endl;
		return ;
	}
	catch (std::exception &e) {
		if (DEBUG)
			std::cerr << ORANGE << "Exception - A: " << e.what() << RESET << std::endl;
	}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference to class type 'B'" << std::endl;
		return ;
	}
	catch (std::exception &e) {
		if (DEBUG)
			std::cerr << ORANGE << "Exception - B: " << e.what() << RESET << std::endl;
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference to class type 'C'" << std::endl;
	}
	catch (std::exception &e) {
		if (DEBUG)
			std::cerr << ORANGE << "Exception - C: " << e.what() << std::endl;
		std::cerr << ORANGE
				<< "Error: reference is not to a class derived from Base class"
				<< RESET << std::endl;
	}
}

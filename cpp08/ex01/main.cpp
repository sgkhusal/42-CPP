/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:17:53 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/04 02:13:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

#define SIZE 10000

void printTitle(std::string const& title) {
	std::cout << std::endl << BLUE << title << RESET << std::endl;
}

void	printException(std::exception const& e) {
	std::cout << ORANGE << "Exception: " << e.what() << RESET << std::endl;
}

int main(void) {
	printTitle("PDF test:");
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// std::cout << sp << std::endl;
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

	Span span = Span(SIZE);
	// std::cout << span << std::endl;

	printTitle("shortestSpan test - empty span");
	try {
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}
	printTitle("longestSpan test - empty span");
	try {
		std::cout << span.longestSpan() << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}

	printTitle("addNumber - negative integer: -100");
	span.addNumber(-100);
	// std::cout << span << std::endl;

	printTitle("shortestSpan test - span size = 1");
	try {
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}
	printTitle("longestSpan test - span size = 1");
	try {
		std::cout << span.longestSpan() << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}

	printTitle("addNumber - negative integer: -10");
	span.addNumber(-10);
	// std::cout << span << std::endl;
	std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << span.longestSpan() << std::endl;

	std::vector<int> v;
	srand(time(NULL));
	for (int i = 10; i > 0; i--)
		v.push_back(rand() % 100);
	span.addNumber(v.begin(), --(v.end()));
	// std::cout << span << std::endl;
	std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << span.longestSpan() << std::endl;

	printTitle("Fill all span - size = 10.000"); //
	for (size_t i = 12; i < SIZE; i++) {
		span.addNumber(i);
	}
	// std::cout << span << std::endl;
	std::cout << "shortestSpan: " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << span.longestSpan() << std::endl;

	printTitle("addNumber with Span full");
	try {
		span.addNumber(1);
	}
	catch (std::exception const& e) {
		printException(e);
	}

	return 0;
}
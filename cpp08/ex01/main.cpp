/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:17:53 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/04 01:32:40 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

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

	Span isToMuch = Span(SIZE);
	// std::cout << isToMuch << std::endl;

	printTitle("shortestSpan test - empty span");
	try {
		std::cout << isToMuch.shortestSpan() << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}
	printTitle("longestSpan test - empty span");
	try {
		std::cout << isToMuch.longestSpan() << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}

	printTitle("addNumber - negative integer: -1");
	isToMuch.addNumber(-1);
	// std::cout << isToMuch << std::endl;

	printTitle("shortestSpan test - span size = 1");
	try {
		std::cout << isToMuch.shortestSpan() << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}
	printTitle("longestSpan test - span size = 1");
	try {
		std::cout << isToMuch.longestSpan() << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}

	printTitle("addNumber - negative integer: -1000");
	isToMuch.addNumber(-1000);
	// std::cout << isToMuch << std::endl;
	std::cout << "shortestSpan: " << isToMuch.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << isToMuch.longestSpan() << std::endl;

	// printTitle("addNumber - list of iterators");
	// std::multiset<int> multiSet = std::multiset<int>(10, -3);
	// isToMuch.addNumber(multiSet.begin(), --(multiSet.end()));
	// // std::cout << isToMuch << std::endl;
	// std::cout << "shortestSpan: " << isToMuch.shortestSpan() << std::endl;
	// std::cout << "longestSpan: " << isToMuch.longestSpan() << std::endl;

	printTitle("Fill all span - size = 10.000"); //
	for (size_t i = 2; i < SIZE; i++) {
		isToMuch.addNumber(i);
	}
	// std::cout << isToMuch << std::endl;
	std::cout << "shortestSpan: " << isToMuch.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << isToMuch.longestSpan() << std::endl;

	printTitle("addNumber with Span full");
	try {
		isToMuch.addNumber(1);
	}
	catch (std::exception const& e) {
		printException(e);
	}


	return 0;
}
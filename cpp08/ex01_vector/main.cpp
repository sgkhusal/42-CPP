/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:17:53 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/04 18:40:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <set>
#include <list>

#define SIZE 1000000

void printTitle(std::string const& title) {
	std::cout << std::endl << BLUE << title << RESET << std::endl;
}

void	printException(std::exception const& e) {
	std::cout << ORANGE << "Exception: " << e.what() << RESET << std::endl;
}

void	printSpan(Span const& s) {
	std::cout << GREY << s << std::endl;
	std::cout << "shortestSpan: " << s.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << s.longestSpan() << RESET << std::endl;
}

int main(void) {
	printTitle("PDF test:");
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	printSpan(sp);
	printTitle("addNumber with Span full");
	try {
		sp.addNumber(1);
	}
	catch (std::exception const& e) {
		printException(e);
	}

	printTitle("Test: print empty span");
	Span span = Span(SIZE);
	std::cout << GREY << span << std::endl;

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
	std::cout << GREY << span << std::endl;

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

	printTitle("addNumber - positive integer: 42");
	span.addNumber(42);
	printSpan(span);

	printTitle("addNumber - range of std::set<int> iterators");
	std::set<int> v;
	for (int i = 10; i > 0; i--)
		v.insert(i * i);
	span.addNumber(v.begin(), v.end());
	printSpan(span);

	printTitle("addNumber - range of std::list<int> iterators");
	std::list<int> l;
	for (int i = 9; i >= 0; i--)
		l.push_front(i * 10);
	span.addNumber(l.begin(), l.end());
	printSpan(span);

	printTitle("Fill all span - size = 1.000.000");
	srand(time(NULL));
	for (size_t i = 22; i < SIZE - 1; i++)
		span.addNumber(rand() % 1000000);
	span.addNumber(1000000);
	std::cout << GREY "shortestSpan: " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << span.longestSpan() << RESET << std::endl;

	printTitle("addNumber with Span full");
	try {
		span.addNumber(1);
	}
	catch (std::exception const& e) {
		printException(e);
	}

	printTitle("Construction by copy and assignment operator");
	{
		Span copy1(sp);
		Span copy2 = sp;
		std::cout << GREY << "original: " << sp << std::endl;
		std::cout << "copy1:    " << copy1 << std::endl;
		std::cout << "copy2:    " << copy2 << RESET << std::endl;
		bool ok = true;
		for(const_vector_itr it = sp.begin(), it1 = copy1.begin(), it2 = copy2.begin(); it != sp.end(); it++, it1++, it2++)
			if (*it != *it1 && *it != *it2)
				ok = false;
		if (ok)
			std::cout << GREEN << "OK" << RESET << std::endl;
		else
			std::cout << ORANGE << "KO" << RESET << std::endl;

		printTitle("Deep copy:");
		for (vector_itr it = sp.begin(), it1 = copy1.begin(); it != sp.end(); it++, it1++) {
			(*it)++;
			(*it1)--;
		}
		std::cout << GREY << "original: " << sp << std::endl;
		std::cout << "copy1:    " << copy1 << std::endl;
		std::cout << "copy2:    " << copy2 << RESET << std::endl;
		ok = true;
		for(const_vector_itr it = sp.begin(), it1 = copy1.begin(), it2 = copy2.begin(); it != sp.end(); it++, it1++, it2++)
			if (*it == *it1 || *it == *it2)
				ok = false;
		if (ok)
			std::cout << GREEN << "OK" << RESET << std::endl;
		else
			std::cout << ORANGE << "KO" << RESET << std::endl;
	}
	printTitle("Original still working after end of scope:");
	std::cout << GREY << "original: " << sp << RESET << std::endl;

	return 0;
}
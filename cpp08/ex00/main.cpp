/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:09:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/02 17:53:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <iostream>

void printTitle(std::string const& title) {
	std::cout << std::endl << BLUE << title << RESET << std::endl;
}

int main(void) {
	std::vector<int> v(1000, 1);
	v[500] = 100;
	printTitle("Test 1: vector: valid number:");
	ex00::test(v, 100);
	printTitle("Test 2: vector: invalid number:");
	ex00::test(v, 10);

	std::deque<int> d(100, 2);
	d.push_back(42);
	printTitle("Test 3: deque: valid number:");
	ex00::test(d, 42);
	printTitle("Test 4: deque: invalid number:");
	ex00::test(d, 1);

	std::list<int> l(100, 3);
	printTitle("Test 5: list: valid number:");
	ex00::test(l, 3);
	printTitle("Test 6: list: invalid number:");
	ex00::test(l, 2);
}

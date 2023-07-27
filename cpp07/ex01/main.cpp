/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:15:13 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/27 11:34:07 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "iter.hpp"

void printTitle(std::string const& title) {
	std::cout << BLUE << title << RESET << std::endl;
}

int main( void ) {
	int size = 10;
	int* numbers = new int[size];
	for (int i = 0; i < size; i++)
		numbers[i] = i;

	std::cout << std::endl;
	printTitle("Array of ints:");
	std::cout << GREY << "Before:" << std::endl;
	iter<int>(numbers, size, printElem);
	iter<int>(numbers, size, addOne);
	std::cout << std::endl << "After addOne: " << std::endl;
	iter<int>(numbers, size, printElem);
	iter<int>(numbers, size, reduceOne);
	std::cout << std::endl << "After reduceOne: " << std::endl;
	iter<int>(numbers, size, printElem);
	std::cout << RESET << std::endl << std::endl;

	int* numbers2 = new int[10]();
	printTitle("Pre initialized array of ints:");
	std::cout << GREY << "Before:" << std::endl;
	iter<int>(numbers2, size, printElem);
	iter<int>(numbers2, size, addOne);
	std::cout << std::endl << "After addOne: " << std::endl;
	iter<int>(numbers2, size, printElem);
	iter<int>(numbers2, size, reduceOne);
	std::cout << std::endl << "After reduceOne: " << std::endl;
	iter<int>(numbers2, size, printElem);
	std::cout << RESET << std::endl << std::endl;

	float* floats = new float[size];
	for (int i = 0; i < size; i++)
		floats[i] = float(i) / 10.0f;

	printTitle("Array of floats:");
	std::cout << GREY << "Before:" << std::endl;
	iter(floats, size, printElem);
	iter(floats, size, reduceOne);
	std::cout << std::endl << "After reduceOne: " << std::endl;
	iter(floats, size, printElem);
	iter(floats, size, addOne);
	std::cout << std::endl << "After addOne: " << std::endl;
	iter(floats, size, printElem);
	std::cout << RESET << std::endl << std::endl;

	char str[] = "Hello World";
	size = std::strlen(str);
	printTitle("char[]");
	std::cout << GREY << "Before: " << std::endl;
	iter(str, size, printElem);
	iter(str, size, addOne);
	std::cout << std::endl << "After addOne: " << std::endl;
	iter(str, size, printElem);
	iter(str, size, reduceOne);
	std::cout << std::endl << "After reduceOne: " << std::endl;
	iter(str, size, printElem);
	std::cout << RESET << std::endl << std::endl;

	std::string strings[] = {
		"Harry Potter",
		"Hermione Granger",
		"Ronald Weasley",
	};
	size = 3;
	printTitle("Array de strings");
	std::cout << GREY;
	iter(strings, size, printElem);
	std::cout << std::endl;
	iter(strings, size, printElem2);
	std::cout << RESET << std::endl;

	size = 10;
	int const const_numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printTitle("const array");
	std::cout << GREY;
	iter(const_numbers, size, printElem);
	std::cout << std::endl;
	iter(const_numbers, size, printElem2);
	std::cout << RESET << std::endl;

	size = 0;
	int* empty = new int[0];
	printTitle("Empty array:");
	std::cout << GREY;
	iter(empty, size, printElem);
	std::cout << RESET << std::endl;
	
	printTitle("Null pointer:");
	int* ptr = NULL;
	std::cout << GREY;
	iter(ptr, size, printElem);
	printTitle("Null pointer with size > 0:");
	std::cout << GREY;
	iter(ptr, 2, printElem);
	std::cout << RESET << std::endl;

	delete [] numbers;
	delete [] numbers2;
	delete [] floats;
	delete [] empty;

	return 0;

}


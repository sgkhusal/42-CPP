/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/29 21:58:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750

void printTitle(std::string const& title) {
	std::cout << std::endl << BLUE << title << RESET << std::endl;
}

void	printException(std::exception const& e) {
	std::cout << ORANGE << "Exception: " << e.what() << RESET << std::endl;
}

int main(void) {
	printTitle("Default constructor: creates an empty array");
	Array<int> a;
	std::cout << GREY << a << std::endl;

	printTitle(
		std::string("Unsigned int constructor: ")
		+ std::string("creates an array of n elements initialized by default")
	);
	size_t size = 10;
	Array<int> b(size);
	std::cout << GREY << b << std::endl;

	printTitle("Accessing index out of bounds: index = array size");
	try {
		std::cout << a[0] << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}
	try {
		std::cout << GREY << b[b.size()] << " ";
	}
	catch (std::exception const& e) {
		printException(e);
	}

	printTitle("Subscript Operator ([])");
	for (size_t i = 0; i < size; i++)
		b[i] = static_cast<int>(i);
	std::cout << GREY << b << std::endl;

	printTitle("Construction by copy and assignment operator");
	Array<int> copy1(b);
	Array<int> copy2 = b;
	std::cout << GREY << "original: " << b << std::endl;
	std::cout << "copy1:    " << copy1 << std::endl;
	std::cout << "copy2:    " << copy2 << RESET << std::endl;
	bool ok = true;
	for(size_t i = 0; i < b.size(); i++)
		if (copy1[i] != b[i] && copy2[i] != b[i])
			ok = false;
	if (ok)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << ORANGE << "KO" << RESET << std::endl;

	printTitle("Deep copy:");
	for (size_t i = 0; i < size; i++) {
		b[i]++;
		copy1[i]--;
	}
	std::cout << GREY << "original: " << b << std::endl;
	std::cout << "copy1:    " << copy1 << std::endl;
	std::cout << "copy2:    " << copy2 << RESET << std::endl;
	ok = true;
	for(size_t i = 0; i < b.size(); i++)
		if (copy1[i] == b[i] && copy2[i] == b[i])
			ok = false;
	if (ok)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << ORANGE << "KO" << RESET << std::endl;

	printTitle("Array const");
	Array<int> const const_array = b;
	std::cout << GREY << const_array << std::endl;

	printTitle("Array of floats");
	size = 20;
	Array<float> f(size);
	std::cout << GREY << f << std::endl;
	for (size_t i = 0; i < size; i++)
		f[i] = static_cast<float>(i) / 100;
	std::cout << GREY << f << std::endl;

	printTitle("Array of chars");
	size = 26;
	Array<char> c(size);
	std::cout << GREY << c << std::endl;
	for (size_t i = 0; i < size; i++)
		c[i] = static_cast<char>(i + 'A');
	std::cout << GREY << c << std::endl;

	printTitle("Array of std::strings");
	size = 3;
	Array<std::string> s(size);
	std::cout << GREY << s << std::endl;
	std::string s2[] = {
		"Harry Potter",
		"Hermione Granger",
		"Ronald Weasley",
	};
	for (size_t i = 0; i < size; i++)
		s[i] = s2[i];
	std::cout << GREY << s << std::endl;

	printTitle("Array of bools");
	size = 10;
	Array<bool> bools(size);
	std::cout << GREY << bools << std::endl;
	for (size_t i = 0; i < size; i++) {
		if (i % 2)
			bools[i] = true;
	}
	std::cout << GREY << bools << std::endl;

	std::cout << std::endl;

	printTitle("**************** 42 tests ****************");
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/27 13:04:12 by sguilher         ###   ########.fr       */
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
	printTitle("Testing default constructor: creates an empty array");
	Array<int> a;
	try {
		std::cout << a[0] << std::endl;
	}
	catch (std::exception const& e) {
		printException(e);
	}

	printTitle(
		std::string("Testing unsigned int constructor: ") 
		+ std::string("creates an array of n elements initialized by default")
	);
	size_t size = 10;
	Array<int> b(size);
	try {
		for (size_t i = 0; i < size + 1; i++) {
			std::cout << GREY << b[i] << " ";
			if (DEBUG)
				std::cout << std::endl;
		}
	}
	catch (std::exception const& e) {
		printException(e);
	}

	printTitle("Testing copy constructor: creates an empty array");
	
	std::cout << std::endl;

	printTitle("42 tests");
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
    delete [] mirror;//
    return 0;
}

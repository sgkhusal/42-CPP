/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:26:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/27 00:04:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void printTitle(std::string const& title) {
	std::cout << std::endl << BLUE << title << RESET << std::endl;
}

void	printException(std::exception& e) {
	std::cout << ORANGE << "Exception: " << e.what() << RESET << std::endl;
}

int main(void) {
	printTitle("Testing default constructor");
	Array<int> a;
	try {
		std::cout << a[0] << std::endl;
	}
	catch (std::exception& e) {
		printException(e);
	}

	printTitle("Testing unsigned int constructor");
	Array<int> b(10);
	try {
		for (size_t i = 0; i < 10; i++)
			std::cout << GREY << b[i] << " ";
	}
	catch (std::exception& e) {
		printException(e);
	}
	std::cout << std::endl;
    return 0;
}

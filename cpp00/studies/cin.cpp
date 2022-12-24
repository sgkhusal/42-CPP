/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cin.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:19:30 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/23 23:16:35 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str;
	int n;

	std::cout << "Give me a word: " << std::endl;
	std::cin >> str;
	std::cout << "You wrote: " << str << std::endl;
	std::cout << "Give me two words (with space between): " << std::endl;
	std::cin >> str;
	std::cout << "The first word is: " << str << std::endl;
	std::cin >> str;
	std::cout << "The second word is: " << str << std::endl;
	std::cout << "Give me a word: " << std::endl;
	std::cin.ignore(); // here it doesn't make anything
	std::cin >> str;
	std::cout << "You wrote: " << str << std::endl;
	std::cout << "Give me a phrase: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, str);
	std::cout << "You wrote: " << str << std::endl;
	std::cout << "Give me a phrase: " << std::endl;
	std::cin.ignore(); // here it ignores the first character
	std::getline(std::cin, str);
	std::cout << "You wrote (cutted phrase): " << str  << std::endl;

	std::cout << std::endl << "-------------------------------------------------------" << std::endl;
	std::cout << "Give me a number: " << std::endl;
	std::cin >> n;
	std::cout << "The number is: " << n << std::endl;
	std::cout << "Give me two numbers (with space between): " << std::endl;
	std::cin >> n;
	std::cout << "The first number is: " << n << std::endl;
	std::cin >> n;
	std::cout << "The second number is: " << n << std::endl;
	std::cout << "Give me a number: " << std::endl;
	std::cin.ignore(); // here it doesn't make anything
	std::cin >> n;
	std::cout << "The number is: " << n << std::endl;

	std::cout << std::endl << "-------------------------------------------------------" << std::endl;
	// std::cin.ignore() in a loop
	// std::cin.ignore(); // here is the write place
	for (int i = 0; i < 5; i++) {
		std::cout << "Enter a name: ";
		std::cin.ignore(); // here it takes one character from second name beyond
		std::getline(std::cin, str);
		std::cout << "The name is: " << str << std::endl;
	}

	n = 0;
	std::cout << std::endl << "-------------------------------------------------------" << std::endl;
	do {
		std::cout << "Enter a number (-1 = quit): ";
		std::cin >> n;
		if (std::cin.fail()) {
			std::cin.clear(); // needs to not enter in a loop
			std::cout << "Please enter numbers only." << std::endl;
			std::cin.ignore(10,'\n'); // clean only 10 charcters until a \n
		}
		else if (n != -1) {
			std::cout << "You entered " << n << std::endl;
		}
	}
	while (n != -1);
	std::cout << "All done." << std::endl;

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:13:13 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/06 02:05:33 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define GREY	"\033[38;5;244m"
#define RESET	"\033[0m"

int	main(void) {
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << std::endl;
	std::cout << "The memory address of the string is:     " << GREY \
			<< &string << RESET << std::endl;
	std::cout << "The memory address held by stringPTR is: " << GREY \
			<< stringPTR << RESET << std::endl;
	std::cout << "The memory address held by stringREF:    " << GREY \
			<< &stringREF << RESET << std::endl;//
	std::cout << std::endl;
	std::cout << "The value of the string variable is:  " << GREY \
			<< string << RESET << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << GREY \
			<< *stringPTR << RESET << std::endl;
	std::cout << "The value pointed to by stringREF is: " << GREY \
			<< stringREF << RESET << std::endl;
	std::cout << std::endl;
	return (0);
}

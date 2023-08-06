/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:05:33 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/06 17:13:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_utils.hpp"

void printTitle(std::string const& title) {
	std::cout << std::endl << BLUE << title << RESET << std::endl;
}

void printDescription(std::string const& description) {
	std::cout << PURPLE << description << std::endl << GREY;
}

void printSubDescription(std::string const& description) {
	std::cout << GREY << description << std::endl;
}

void printResult(bool ok) {
	if (ok)
		std::cout << GREEN "OK" RESET << std::endl << std::endl;
	else
		std::cout << ORANGE "KO" RESET << std::endl << std::endl;
}

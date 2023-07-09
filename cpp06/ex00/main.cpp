/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:47:39 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/09 01:10:21 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.hpp"

void	printErrorMessage(std::string const& exec, std::string const& msg) {
	std::cout << ORANGE << msg << std::endl
		<< "usage: " << exec << " [literal value to be converted]"
		<< RESET << std::endl;
}

int	main(int argc, char*argv[]) {
	if (argc == 1) {
		printErrorMessage(argv[0], "Missing parameter");
		return 1;
	}
	if (argc > 2) {
		printErrorMessage(argv[0], "To many arguments");
		return 1;
	}
	try {
		ScalarConverter::convert(argv[1]);
    }
    catch (std::exception& e) {
        std::cout << ORANGE << "Exception: " << e.what() << std::endl
			<< RESET << std::endl;
		return 1;
    }
	return 0;
}

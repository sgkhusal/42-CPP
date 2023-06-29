/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:47:39 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/29 12:57:36 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.hpp"

int	main(int argc, char*argv[]) {
	if (argc == 1) {
		std::cout << ORANGE << "Missing parameter" << std::endl
			<< "usage: " << argv[0] << " [value to be converted]" 
			<< RESET << std::endl;
		return 1;
	}
	if (argc > 2) {
		std::cout << ORANGE << "To many arguments" << std::endl
			<< "usage: " << argv[0] << " [value to be converted]" 
			<< RESET << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:56:58 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/05 16:09:23 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	harl;

	std::cout << std::endl;
	std::cout << "************************" << std::endl;
	std::cout << "   Harl messages test   " << std::endl;
	std::cout << "************************" << std::endl << std::endl;
	std::cout << DEBUG << "[ DEBUG MESSAGE ]" << RESET << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << INFO << "[ INFO MESSAGE ]" << RESET << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	std::cout << WARNING << "[ WARNING MESSAGE ]" << RESET << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	std::cout << ERROR << "[ ERROR MESSAGE ]" << RESET << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "*********************" << std::endl;
	std::cout << "  Invalid complains  " << std::endl;
	std::cout << "*********************" << std::endl << std::endl;
	harl.complain("Hello world");
	harl.complain("");
	harl.complain("42");
	return (0);
}

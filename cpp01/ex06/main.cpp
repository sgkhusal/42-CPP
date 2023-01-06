/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:56:58 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/05 21:23:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char* argv[]) {
	Harl		harl;

	if (argc != 2) {
		std::cerr << ERROR << "Invalid number of arguments" << RESET << std::endl;
		return (1);
	}
	return (harl.complain(argv[1]));
}

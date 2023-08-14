/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:30:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/14 00:45:11 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	BitcoinExchange btc;

	if (argc == 1) {
		std::cerr << "Error: missing file" << std::endl;
		return 1;
	}
	if (argc > 2) {
		std::cerr << "Error: to many args" << std::endl;
		return 1;
	}
	btc.run(argv[1]);
	return 0;
}
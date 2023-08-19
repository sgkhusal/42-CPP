/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:21 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/19 18:36:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << ORANGE << "Error: missing integer sequence to be sorted"
				<< std::endl;
		return 1;
	}
	try {
		PmergeMe p = PmergeMe(&argv[1]);
		p.sortV();
	} catch (std::exception const& e) {
		std::cout << ORANGE << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}
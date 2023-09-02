/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:21 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/02 20:35:54 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "PmergeMe.hpp"

void copiesTest(PmergeMe const& p);

int main(int argc, char *argv[]) {
	try {
		utils::checkInput(argc, &argv[0]);
	} catch (std::exception const& e) {
		std::cout << ORANGE << e.what() << RESET << std::endl;
		return 1;
	}

	PmergeMe p = PmergeMe(&argv[1]);

	p.sort();

	std::cout << std::endl;
	return 0;
}

void copiesTest(PmergeMe const& p) {
	/* Copy constructor and assign operator tests */
	PmergeMe p2;
	p2.sort();
	std::cout << std::endl;
	p2 = p;
	p2.sort();
	std::cout << std::endl;
	PmergeMe p3(p);
	p3.sort();
	std::cout << std::endl;
}
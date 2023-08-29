/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:21 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/29 00:35:23 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "PmergeMe.hpp"

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
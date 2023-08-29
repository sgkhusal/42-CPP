/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:15:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/28 23:29:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

namespace utils
{
unsigned int getNumber(std::string const str_nb) {
	std::stringstream	ss;
	unsigned int		nb;

	ss << str_nb;
	ss >> nb;

	return nb;
}

void checkInput(int argc, char *input[]) {
	int i = 1, j = 0;
	unsigned int nb;

	if (argc == 1) {
		throw std::runtime_error(
			"Error: missing integer sequence to be sorted"
		);
	}
	while (input[i]) {
		j = 0;
		while(input[i][j]) {
			if (!std::isdigit(input[i][j])) {
				throw std::runtime_error(
					"Error: invalid input: only accepts positive integers"
				);
			}
			j++;
		}
		nb = utils::getNumber(input[i]);
		if (nb > __INT_MAX__) {
			throw std::out_of_range(
				"Error: invalid input: only accepts positive integers"
			);
		}
		i++;
	}
}

void printDetails(int iteration, int size, int element_size, int pair_size) {
	if (DEBUG) {
		std::cout << GREY << "\n------------------------------------------\n"
			<< "iteration " << iteration
			<<  ":\n- element size: " << element_size
			<<  "\n- size: " << size << std::endl;
		if (size > 1)
			std::cout << "- pair size: " << pair_size << RESET << std::endl;
	}
}

void printElement(int nb) {
	std::cout << nb << " ";
}

} // namespace utils


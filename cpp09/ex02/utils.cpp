/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:15:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/27 23:02:49 by sguilher         ###   ########.fr       */
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

} // namespace utils


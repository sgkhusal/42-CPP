/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:15:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/27 16:17:52 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

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
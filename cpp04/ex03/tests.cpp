/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:06:56 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/01 20:57:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void	testDescription(std::string description) {
	std::cout << std::endl << YELLOW << description << RESET << std::endl;
}

// void	stepDescription(
// 	std::string class_name,
// 	std::string description,
// 	std::string color
// 	) {
// 	std::cout << color << class_name << " class " << description
// 			<< " called" << RESET << std::endl;
// }

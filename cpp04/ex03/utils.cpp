/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:06:56 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/08 23:25:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	testDescription(std::string description) {
	std::cout << std::endl << YELLOW << description << RESET << std::endl;
}

void	subTestDescription(std::string description) {
	std::cout << std::endl << ORANGE << description << RESET << std::endl;
}

void	classDescription(std::string class_name, std::string description) {
	std::cout << GREY << class_name << " class " << description
			<< " called" << RESET << std::endl;
}

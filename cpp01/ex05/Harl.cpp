/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:56:56 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/05 14:04:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	return ;
}

Harl::~Harl(void) {
	return ;
}

void	Harl::_debug(void) {
	std::cout << DEBUG \
			<< "I love having extra bacon for my "
			<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
			<< "I really do!" << RESET << std::endl;
}

void	Harl::_info(void) {
	std::cout << INFO \
			<< "I cannot believe adding extra bacon costs more money. " \
			<< "You didn’t put enough bacon in my burger! " \
			<< "If you did, I wouldn’t be asking for more!" << RESET \
			<< std::endl;
}

void	Harl::_warning(void) {
	std::cout << WARNING \
			<< "I think I deserve to have some extra bacon for free. "
			<< "I’ve been coming for years whereas you started working here "
			<< "since last month." << RESET << std::endl;
}

void	Harl::_error(void) {
	std::cout << ERROR \
			<< "This is unacceptable! I want to speak to the manager now."
			<< RESET << std::endl;
}

void	Harl::complain(std::string level) {
	int	i = 0;

	while(level.compare(this->_complainTable[i].level) && i < 4)
		i++;
	if (i == 4)
		return ;
	(this->*_complainTable[i].f)();
}

Harl::_t_line	Harl::_complainTable[4] = {
	{"DEBUG", &Harl::_debug},
	{"INFO", &Harl::_info},
	{"WARNING", &Harl::_warning},
	{"ERROR", &Harl::_error}
};

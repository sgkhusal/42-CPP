/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample7.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:04:14 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 22:13:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample7.class.hpp"

Sample7::Sample7(void)
{
	std::cout << "Constructor called" << std::endl;
	Sample7::_nbInst += 1;
	return ;
}

Sample7::~Sample7(void)
{
	std::cout << "Destructor called" << std::endl;
	Sample7::_nbInst -= 1;
	return ;
}

int	Sample7::getNbInst(void)
{
	return (Sample7::_nbInst);
}

int	Sample7::_nbInst = 0;

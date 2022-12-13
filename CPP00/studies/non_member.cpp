/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_member.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:39:21 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 22:42:34 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample7.class.hpp"

void	f0(void)
{
	Sample7	instance;

	std::cout << "Number of instances: " << Sample7::getNbInst() << std::endl;
	return ;
}

void	f1(void)
{
	Sample7	instance;

	std::cout << "Number of instances: " << Sample7::getNbInst() << std::endl;
	f0();
	return ;
}

int	main(void)
{
	std::cout << "Number of instances: " << Sample7::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instances: " << Sample7::getNbInst() << std::endl;
	return (0);
}

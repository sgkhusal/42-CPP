/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample1.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:46:45 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/07 21:35:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample1.class.hpp"

// this shouldn't be done
Sample1::Sample1(char p1, int p2, float p3)
{
	std::cout << "Constructed called" << std::endl;
	this->a1 = p1;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	this->a2 = p2;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	this->a3 = p3;
	std::cout << "this->a3 = " << this->a3 << std::endl;
	return;
};

Sample1::~Sample1(void)
{
	std::cout << "Destructer called" << std::endl;
	return;
}

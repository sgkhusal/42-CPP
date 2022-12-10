/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample3.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:57:35 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 15:40:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample3.class.hpp"

/*
* The initialization list initialize the variables
* initialize a variable is different from attribute a value to the variable!!
* This is very important in the case of const variables
*/
Sample3::Sample3(float const f) : pi(f), qd(42)
{
	std::cout << "Constructed called" << std::endl;
	return;
}

Sample3::~Sample3(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

/*
* The const in a function tells the compiler that the member function won't
* alter the current instance
* It means it don't have any assigned like "if x > bla, y = 0"
*/
void Sample3::bar(void) const
{
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;
	// you can't do this in a const member function:
	//this->qd = 0;
	return;
}

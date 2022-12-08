/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:19:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/07 18:37:52 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	this->foo = 42; // this is a pointer to the object that was created
	std::cout << "this->foo = " << this->foo << std::endl;
	this->bar();
	return; // return is optional in constructors and destructors
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

// to define a member function, you need to use the scope resolution operator
void	Sample::bar(void)
{
	std::cout << "Member function bar called" << std::endl;
	return;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample6.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:43:49 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 20:50:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample6.class.hpp"

Sample6::Sample6(int v) : _foo(v)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample6::~Sample6(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Sample6::getFoo(void) const
{
	return (this->_foo);
}

int	Sample6::compare(Sample6 *other) const
{
	if (this->getFoo() < other->getFoo())
		return (-1);
	else if (this->getFoo() > other->getFoo())
		return (1);
	return (0);
	//return (this->getFoo() == other->getFoo());
}

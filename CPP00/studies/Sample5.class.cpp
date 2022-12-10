/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample5.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:22:48 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 17:42:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample5.class.hpp"

Sample5::Sample5(void)
{
	std::cout << "Constructor called" << std::endl;
	this->setFoo(0);
	std::cout << "this->getFoo(): " << this->getFoo() << std::endl;
	return ;
}

Sample5::~Sample5(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Sample5::getFoo(void) const
{
	return (this->_foo);
}

void	Sample5::setFoo(int v)
{
	if (v >= 0)
		this->_foo = v;
		// works with _foo = v also, without the this
	return ;
}

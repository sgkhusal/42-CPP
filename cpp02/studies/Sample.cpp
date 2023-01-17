/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:43:33 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/17 00:51:54 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample(void): _foo(0) {
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Sample::Sample(int const n): _foo(n) {
	std::cout << "Parametric Constructor called" << std::endl;
	return ;
}

Sample::Sample(Sample const& src) {
	std::cout << "Copy constructer called" << std::endl;
	*this = src;
	return ;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Sample& Sample::operator=(Sample const& rhs) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_foo = rhs.getFoo();
	return (*this);
}

int Sample::getFoo(void) const {
	return (this->_foo);
}

std::ostream& operator<<(std::ostream& o, Sample const& t) {
	o << t.getFoo();
	return (o);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:57:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/13 19:11:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact Constructor called" << std::endl; /* remove */
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact Constructor called" << std::endl; /* remove */
	return ;
}

void	Contact::set_name(std::string name)
{
	std::cout << "set_name called for: " << name << std::endl; /* remove */
	this->_name = name;
	return ;
}

std::string	Contact::get_name(void)
{
	return (this->_name);
}

void	Contact::set_last_name(std::string last_name)
{
	std::cout << "set_last_name called for: " << last_name << std::endl; /* remove */
	this->_last_name = last_name;
	return ;
}

std::string	Contact::get_last_name(void)
{
	return (this->_last_name);
}

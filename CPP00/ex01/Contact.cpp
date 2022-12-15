/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:57:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/14 19:27:27 by sguilher         ###   ########.fr       */
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

void	Contact::set_nickname(std::string nickname)
{
	std::cout << "set_nickname called for: " << nickname << std::endl; /* remove */
	this->_nickname = nickname;
	return ;
}

std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

void	Contact::set_phone_number(std::string phone_number)
{
	std::cout << "set_phone_number called for: " << phone_number << std::endl; /* remove */
	this->_phone_number = phone_number;
	return ;
}

std::string	Contact::get_phone_number(void) // talvez não precise
{
	return (this->_phone_number);
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	std::cout << "set_darkest_secret called for: " << darkest_secret << std::endl; /* remove */
	this->_darkest_secret = darkest_secret;
	return ;
}

std::string	Contact::get_darkest_secret(void) // talvez não precise
{
	return (this->_darkest_secret);
}


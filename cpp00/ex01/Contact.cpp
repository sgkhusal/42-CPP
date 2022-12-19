/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:57:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/19 15:11:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) // precisa inicializar os campos como nulos??
{
	return ;
}

Contact::~Contact(void) // precisaria ter o destructor??
{
	return ;
}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
	return ;
}

std::string	Contact::getFirstName(void)
{
	return (this->_firstName);
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
	return ;
}

std::string	Contact::getLastName(void)
{
	return (this->_lastName);
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
	return ;
}

std::string	Contact::getNickname(void)
{
	return (this->_nickname);
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
	return ;
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
	return ;
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}

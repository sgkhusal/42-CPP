/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:57:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/24 03:19:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "Contact.hpp"
#include "texts.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

std::string	Contact::getFirstName(void) {
	return (this->_firstName);
}

void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

std::string	Contact::getLastName(void) {
	return (this->_lastName);
}

void	Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

std::string	Contact::getNickname(void) {
	return (this->_nickname);
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	for (size_t i = 0; i < phoneNumber.size(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			Texts::warning("Invalid phone number. It accepts only numbers");
			_getInfo("phone number:", &Contact::setPhoneNumber);
			return ;
		}
	}
	if (phoneNumber.size() < 8 || phoneNumber.size() > 11)
	{
		Texts::warning("Invalid phone number size");
		_getInfo("phone number:", &Contact::setPhoneNumber);
		return ;
	}
	this->_phoneNumber = phoneNumber;
}

std::string	Contact::getPhoneNumber(void) {
	return (this->_phoneNumber);
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

std::string	Contact::getDarkestSecret(void) {
	return (this->_darkestSecret);
}

void	Contact::getContactInfosFromUser(void) {
	std::cout << std::endl;
	Texts::instruction("Enter the contact data:");
	_getInfo("first name:", &Contact::setFirstName);
	_getInfo("last name:", &Contact::setLastName);
	_getInfo("nickname:", &Contact::setNickname);
	_getInfo("phone number:", &Contact::setPhoneNumber);
	_getInfo("darkest secret:", &Contact::setDarkestSecret);
}

void	Contact::_getInfo(const char* info, fptr setter)
{
	std::string	var;

	Texts::instruction(info);
	std::getline(std::cin, var);
	(this->*setter)(var);
}

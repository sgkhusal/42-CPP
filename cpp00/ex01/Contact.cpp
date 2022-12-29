/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:57:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/29 02:37:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string	Contact::getFirstName(void) {
	return (this->_firstName);
}

std::string	Contact::getLastName(void) {
	return (this->_lastName);
}

std::string	Contact::getNickname(void) {
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) {
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) {
	return (this->_darkestSecret);
}

void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void	Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	for (size_t i = 0; i < phoneNumber.size(); i++) {
		if (!isdigit(phoneNumber[i]))
		{
			Texts::warning("Invalid phone number. It accepts only numbers");
			_getInfo("phone number:", &Contact::setPhoneNumber);
			return ;
		}
	}
	if (phoneNumber.size() < 8 || phoneNumber.size() > 14) {
		Texts::warning("Invalid phone number size");
		_getInfo("phone number:", &Contact::setPhoneNumber);
		return ;
	}
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
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
	std::string	value;

	Texts::instruction(info);
	std::getline(std::cin, value);
	if (!value.empty())
		_cleanInput(&value);
	if (value.empty()) {
		_getInfo(info, setter);
		return ;
	}
	(this->*setter)(value);
}

void	Contact::_cleanInput(std::string *value) {

	size_t		cut1;
	size_t		cut2;

	cut1 = 0;
	while ((*value)[cut1] && ((*value)[cut1] == ' ' || (*value)[cut1] == '\t'))
		cut1++;
	cut2 = value->length() - 1;
	while (cut2 > cut1 && ((*value)[cut2] == ' ' || (*value)[cut2] == '\t'))
		cut2--;
	if (cut1 != 0 || cut2 != value->length() - 1)
		*value = value->substr(cut1, cut2 - cut1 + 1);
}

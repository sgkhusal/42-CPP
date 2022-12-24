/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:57:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/23 23:45:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
	_getInfo("first name:", this->_firstName);
	_getInfo("last name:", this->_lastName);
	_getInfo("nickname:", this->_nickname);
	_getInfo("phone number:", this->_phoneNumber);
	_getInfo("darkest secret:", this->_darkestSecret);
}

void	Contact::_getInfo(const char* info, std::string& var)
{
	Texts::instruction(info);
	std::getline(std::cin, var);
}

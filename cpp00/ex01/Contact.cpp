/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:57:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/22 00:24:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

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

void	Contact::getContactInfoFromUser(void) {
	std::cout << "Enter the contact data:" << std::endl;
	std::cout << "    first name: " << std::endl;
	std::getline(std::cin, this->_firstName);
	std::cout << "     last name: " << std::endl;
	std::getline(std::cin, this->_lastName);
	std::cout << "      nickname: " << std::endl;
	std::getline(std::cin, this->_nickname);
	std::cout << "  phone number: " << std::endl;
	std::getline(std::cin, this->_nickname);
	std::cout << "darkest secret: " << std::endl;
	std::getline(std::cin, this->_phoneNumber);
}

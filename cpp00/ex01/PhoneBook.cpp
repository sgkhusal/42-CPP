/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:59:44 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/26 12:07:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "texts.hpp"

PhoneBook::PhoneBook(void) : _qty(0), _older_contact(0) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::addContact(void) {

	int			index;
	Contact		contact;

	contact.getContactInfosFromUser();
	index = _defineContactIndex();
	this->_contacts[index].setFirstName(contact.getFirstName());
	this->_contacts[index].setLastName(contact.getLastName());
	this->_contacts[index].setNickname(contact.getNickname());
	this->_contacts[index].setPhoneNumber(contact.getPhoneNumber());
	this->_contacts[index].setDarkestSecret(contact.getDarkestSecret());
	Texts::success("Contact successfully saved");
}

int	PhoneBook::_defineContactIndex(void) {
	int	index;

	if (this->_qty < 8)
	{
		this->_qty++;
		index = this->_qty - 1;
	}
	else
	{
		index = this->_older_contact;
		this->_older_contact++;
		if (this->_older_contact == 8)
			this->_older_contact = 0;
	}
	return (index);
}

void	PhoneBook::searchContactList(void) {
	int			userIndex;

	if (this->_qty == 0)
	{
		Texts::warning("The contact's list is empty");
		return ;
	}
	_printContactList();
	Texts::instruction("Select the contact index:");
	userIndex = -1;
	while (userIndex < 0 || userIndex > this->_qty - 1)
	{
		std::cin >> userIndex;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(__INT_MAX__, '\n');
			userIndex = -1;
		}
		if (userIndex < 0 ||  userIndex > this->_qty - 1)
			Texts::warning("Select a valid contact index:");
	}
	_printContactInfo(userIndex);
	std::cin.ignore();
}

void	PhoneBook::_printContactList(void) {
	int	i;

	std::cout << GREY;
	std::cout << "              CONTACTS TABLE" << std::endl;
	std::cout << "______________________________________________" << std::endl;
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
	i = 0;
	while (i < this->_qty)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		_printListFormat(_contacts[i].getFirstName());
		std::cout << "|";
		_printListFormat(_contacts[i].getLastName());
		std::cout << "|";
		_printListFormat(_contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << "______________________________________________" << std::endl;
	std::cout << RESET << std::endl;
}

void	PhoneBook::_printListFormat(std::string info) {
	if (info.length() > 10)
		std::cout << info.substr(0,9) + '.';
	else
		std::cout << std::setw(10) << info;
}

void	PhoneBook::_printContactInfo(int index) {
	std::cout << std::endl;
	_printInfo("    first name: ", _contacts[index].getFirstName());
	_printInfo("     last name: ", _contacts[index].getLastName());
	_printInfo("      nickname: ", _contacts[index].getNickname());
	_printInfo("  phone number: ", _contacts[index].getPhoneNumber());
	_printInfo("darkest secret: ", _contacts[index].getDarkestSecret());
}

void	PhoneBook::_printInfo(const char *key, std::string value) {
	std::cout << ORANGE << key << value << RESET << std::endl;
}

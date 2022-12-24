/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:59:44 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/24 02:34:14 by sguilher         ###   ########.fr       */
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
	this->_contacts[index].setPhoneNumber(contact.getPhoneNumber()); // precisa ter validação dos dados??
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
	/* Display the saved contacts as a list of 4 columns: index, first name, last
	name and nickname */
	/* Each column must be 10 characters wide. A pipe character (’|’) separates
	them. The text must be right-aligned. If the text is longer than the column,
	it must be truncated and the last displayable character must be replaced by a
	dot (’.’) */
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
	i = 0;
	while (i < this->_qty)
	{
		std::cout << std::setw(10) << i << "|";
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

void	PhoneBook::_printInfo(const char *name, std::string info) {
	std::cout << ORANGE << name << info << RESET << std::endl;
}

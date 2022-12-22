/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:59:44 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/22 00:58:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _qty(0), _older_contact(0) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::addContact(void) {

	int			index;
	Contact		contact;

	contact.getContactInfoFromUser();
	index = _defineContactIndex();
	this->_contacts[index] = contact;
	/* this->_contacts[index].setFirstName(contact.getFirstName);
	this->_contacts[index].setLastName(contact.getLastName);
	this->_contacts[index].setNickname(contact.getNickname);
	this->_contacts[index].setPhoneNumber(contact.getNickname); // precisa ter validação dos dados??
	this->_contacts[index].setDarkestSecret(contact.getDarkestSecret); */
	std::cout << "-------- Contact saved successfully --------" << std::endl;
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
	std::string	str;
	int			userIndex;

	if (this->_qty == 0)
	{
		std::cout << "The contact's list is empty" << std::endl;
		return ;
	}
	std::cout << "Select the contact index:" << std::endl;
	_printContactList();
	userIndex = -1;
	while (userIndex < 0 || userIndex > this->_qty - 1)
	{
		// Prompt the user again for the index of the entry to display.
		std::getline(std::cin, str);
		// pegar o índice e transformar - lidar com erros e usuário inválido
		userIndex = str[0];
		/* If the index is out of range or wrong, define a relevant behavior. */
		if (userIndex > this->_qty - 1)
			std::cout << "Select a valid contact index:" << std::endl;
	}
	// Otherwise, display the contact information, one field per line
	_printContactInfo(userIndex);
}

void	PhoneBook::_printContactList(void) {
	int	i;
	/* Display the saved contacts as a list of 4 columns: index, first name, last
	name and nickname */
	/* Each column must be 10 characters wide. A pipe character (’|’) separates
	them. The text must be right-aligned. If the text is longer than the column,
	it must be truncated and the last displayable character must be replaced by a
	dot (’.’) */
	std::cout << "    Index |First name| Last name| Nickname" << std::endl;
	i = 0;
	while (i < this->_qty)
	{
		std::cout << "        " << i << " | " << _contacts[i].getFirstName();
		std::cout << " | " << _contacts[i].getLastName() << " | ";
		std::cout << _contacts[i].getNickname() << std::endl;
		i++;
	}
}

void	PhoneBook::_printContactInfo(int index) {
	std::cout << "contact " << index << ":" << std::endl; // tira?
	std::cout << "    first name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "     last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "      nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "  phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

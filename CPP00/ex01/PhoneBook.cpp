/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:59:44 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/14 20:52:35 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _qty(0), _older_contact(0)
{
	std::cout << "PhoneBook Constructor called" << std::endl; /* remove */
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called" << std::endl; /* remove */
	return ;
}

void	PhoneBook::addContact(void)
{
	Contact		contact;
	std::string	str;

	std::cout << "Add contact function" << std::endl; /* remove */
	std::cout << "Name: " << std::endl;
	std::cin >> str; // cuidado que pega uma palavra por vez!!
	contact.set_name(str);
	std::cout << "Name: " << contact.get_name() << std::endl;
}

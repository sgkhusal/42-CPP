/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:59:44 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/13 19:01:41 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
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

	std::cout << "Add contact function" << std::endl;
	std::cout << "Name: " << std::endl;
	std::cin >> str; // cuidado que pega uma palavra por vez!!
	contact.setName(str);
	std::cout << "Name: " << contact.getName() << std::endl;
}

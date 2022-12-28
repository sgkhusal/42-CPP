/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:36:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/28 19:05:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Texts.hpp"

PhoneBook::t_actions	getUserAction(void) {
	std::string	userAction;

	std::getline(std::cin, userAction);
	if (userAction.empty())
		return (PhoneBook::NONE);
	if (userAction.compare("ADD") == 0)
		return (PhoneBook::ADD);
	if (userAction.compare("SEARCH") == 0)
		return (PhoneBook::SEARCH);
	if (userAction.compare("EXIT") == 0)
		return (PhoneBook::EXIT);
	Texts::warning("Invalid command");
	Texts::putActionsMenu();
	return (PhoneBook::NONE);
}

int	main(void)
{
	PhoneBook	phoneBook;
	PhoneBook::t_actions	userAction;

	Texts::welcome();
	Texts::putActionsMenu();
	userAction = PhoneBook::NONE;
	while (userAction != PhoneBook::EXIT)
	{
		Texts::selectCommand();
		userAction = getUserAction();
		if (userAction == PhoneBook::ADD)
			phoneBook.addContact();
		if (userAction == PhoneBook::SEARCH)
			phoneBook.searchContactList();
		if (userAction == PhoneBook::EXIT)
			Texts::goodbye();
	}
	return (0);
}

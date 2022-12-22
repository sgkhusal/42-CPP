/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:36:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/22 00:47:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

typedef enum e_actions {
	NONE,
	ADD,
	SEARCH,
	EXIT
}				t_actions;

void	putActionsMenu(void) {
	std::cout << std::endl;
	// colocar um testinho legal
	std::cout << "Select a command:" << std::endl;
	std::cout << "* ADD: saves a new contact" << std::endl;
	std::cout << "* SEARCH: displays a specific contact" << std::endl;
	std::cout << "* EXIT: quits My PhoneBook. All data will be lost." << std::endl;
	std::cout << std::endl;
}

t_actions	getUserAction(void) {
	std::string	userAction;

	std::getline(std::cin, userAction);
	if (userAction.compare("ADD") == 0)
		return (ADD);
	if (userAction.compare("SEARCH") == 0)
		return (SEARCH);
	if (userAction.compare("EXIT") == 0)
		return (EXIT);
	std::cout << "Invalid command." << std::endl; /////
	putActionsMenu();
	return (NONE);
}

int	main(void)
{
	PhoneBook	phoneBook;
	t_actions	userAction;

	std::cout << std::endl;
	std::cout << "********* Welcome to My Phonebook *********" << std::endl;
	putActionsMenu();
	while (userAction != EXIT)
	{
		userAction = NONE;
		userAction = getUserAction();
		if (userAction == ADD)
			phoneBook.addContact();
		if (userAction == SEARCH)
			phoneBook.searchContactList();
		if (userAction == EXIT)
			std::cout << "Goodbye" << std::endl; ///////
	}
	return (0);
}

// input pode ser um enter!!

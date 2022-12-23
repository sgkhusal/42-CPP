/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:36:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/23 17:42:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "texts.hpp"

typedef enum e_actions {
	NONE,
	ADD,
	SEARCH,
	EXIT
}				t_actions;

t_actions	getUserAction(void) {
	std::string	userAction;

	std::getline(std::cin, userAction);
	if (userAction.empty()) //////
		return (NONE);
	if (userAction.compare("ADD") == 0)
		return (ADD);
	if (userAction.compare("SEARCH") == 0)
		return (SEARCH);
	if (userAction.compare("EXIT") == 0)
		return (EXIT);
	warning("Invalid command");
	putActionsMenu();
	return (NONE);
}

int	main(void)
{
	PhoneBook	phoneBook;
	t_actions	userAction;

	welcome();
	putActionsMenu();
	userAction = NONE;
	while (userAction != EXIT)
	{
		selectCommand();
		userAction = getUserAction();
		if (userAction == ADD)
			phoneBook.addContact();
		if (userAction == SEARCH)
			phoneBook.searchContactList();
		if (userAction == EXIT)
			goodbye();
	}
	return (0);
}

// input pode ser um enter!!

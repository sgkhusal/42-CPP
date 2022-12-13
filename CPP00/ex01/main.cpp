/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:36:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/13 01:13:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	str;

	while (1)
	{
		std::cin >> str;
		// if str == EXIT -> end
		// ADD, SEARCH
		// Any other input is discarded
		std::cout << "You wrote: " << str << std::endl;
		phoneBook.addContact();
	}
	return (0);
}

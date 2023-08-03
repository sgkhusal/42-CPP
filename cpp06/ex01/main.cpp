/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:47:39 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/02 21:11:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void) {
	std::cout << std::endl << ORANGE << "CPP06 - ex01\n" << RESET << std::endl;

	time_t t = time(NULL);
	Data user = {
		.first_name = "Harry",
		.last_name = "Potter",
		.email = "harry.potter@hogwarts.com",
		.birth_date = *localtime(&t),
	};
	user.setBirthDate(1980, 7, 31);
	std::cout << BLUE << "Initial user data:" << RESET << std::endl;
	std::cout << user << std::endl;

	uintptr_t ptr_data;
	ptr_data = Serializer::serialize(&user);
	std::cout << "user ptr: " << &user << std::endl;
	std::cout << "Serialized ptr: " << ptr_data << std::endl << std::endl;

	Data* returned_data;
	returned_data = Serializer::deserialize(ptr_data);
	std::cout << BLUE << "Returned user data:" << RESET << std::endl;
	std::cout << *returned_data << std::endl;
	std::cout << BLUE << "Original user data:" << RESET << std::endl;
	std::cout << user << std::endl;

	std::cout << ORANGE << "Change birthday:" << RESET << std::endl;
	returned_data->setBirthDate(1988, 8, 14);
	std::cout << BLUE << "Returned user data:" << RESET << std::endl;
	std::cout << *returned_data << std::endl;
	std::cout << BLUE << "Original user data:" << RESET << std::endl;
	std::cout << user << std::endl;

	return 0;
}

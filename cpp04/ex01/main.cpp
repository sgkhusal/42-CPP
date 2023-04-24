/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:12:43 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 20:58:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int i;
	int n = 10;
	Animal* animals[n];

	for (i = 0; i < n / 2; i++)
		animals[i] = new Dog();
	for (i = 5; i < n; i++)
		animals[i] = new Cat();

	std::cout << std::endl
			<< "----------------------- Checking animals -----------------------"
			<< std::endl;
	for (i = 0; i < n; i++){
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << std::endl
			<< "----------------------- Deleting animals -----------------------"
			<< std::endl;
	for (i = 0; i < n; i++)
		delete animals[i];

	return 0;
}
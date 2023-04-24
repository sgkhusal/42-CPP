/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:12:43 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 22:42:40 by sguilher         ###   ########.fr       */
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
	// animals[0]->getBrain()->ideas[0]; an instance of Animal doesn't have a brain

	std::cout << std::endl
			<< "----------------------- Deleting animals -----------------------"
			<< std::endl;
	for (i = 0; i < n; i++)
		delete animals[i];

	std::cout << std::endl
			<< "----------------------- Other tests -----------------------"
			<< std::endl;
	Cat* cat = new Cat;
	std::cout << "1----------------------------------" << std::endl;
	Cat cat2 = *cat;
	std::cout << "2----------------------------------" << std::endl;
	Cat cat3;
	std::cout << "3----------------------------------" << std::endl;
	cat2 = cat3;
	std::cout << "4----------------------------------" << std::endl;
	std::cout << cat2.getType() << " is thinking: "
			<< cat2.getBrain()->ideas[0] << std::endl;
	delete cat;
	std::cout << std::endl << "----------------------------------" << std::endl;
	Dog dog;
	Dog dog2;
	dog = dog2;
	std::cout << dog.getType() << " is thinking: "
			<< dog.getBrain()->ideas[0] << std::endl;

	std::cout << std::endl
			<< "----------------------- Deleting stack -----------------------"
			<< std::endl;

	return 0;
}

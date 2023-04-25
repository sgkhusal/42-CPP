/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:12:43 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/24 04:59:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal animal;

	delete j; //should not create a leak
	delete i;

	// compilation error: an instance of Animal doesn't have a brain
	// i->getBrain()->ideas[0];

	std::cout << std::endl
			<< "---------------------- Array of animals ----------------------"
			<< std::endl;

	int n = 10;
	int m = n / 2;
	Animal* animals[n];

	for (int i = 0; i < m; i++)
		animals[i] = new Dog();
	for (int i = m; i < n; i++) {
		animals[i] = new Cat();
	}

	std::cout << std::endl
			<< "---------------------- Checking animals ----------------------"
			<< std::endl;
	for (int i = 0; i < n; i++){
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << std::endl
			<< "---------------------- Deleting animals ----------------------"
			<< std::endl;
	for (int i = 0; i < n; i++)
		delete animals[i];

	std::cout << std::endl
			<< "------------------------- Other tests -------------------------"
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

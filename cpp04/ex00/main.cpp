/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:12:43 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/20 11:13:31 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << std::endl
			<< "-------------------------- PDF tests --------------------------"
			<< std::endl;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();

	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl
			<< "--------------------- Wrong classes tests ---------------------"
			<< std::endl;

	
	std::cout << std::endl
			<< "----------------------- Testing copies -----------------------"
			<< std::endl;
	Dog dog2;
	Dog dog_copy(dog2);
	// Dog dog3(*dog);
	Cat cat2;
	Cat cat3 = cat2;
	// cat3 = *cat;
	Animal animal1 = *dog;
	Animal animal2(*cat);

	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:12:43 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 20:14:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl
			<< "-------------------------- PDF tests --------------------------"
			<< std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << ":" << std::endl;
	meta->makeSound();
	std::cout << j->getType() << ":" << std::endl;
	j->makeSound();
	std::cout << i->getType() << ":" << std::endl;
	i->makeSound(); //will output the cat sound!

	std::cout << std::endl
			<< "--------------------- Wrong classes tests ---------------------"
			<< std::endl;
	const WrongCat* k = new WrongCat();
	std::cout << k->getType() << ":" << std::endl;
	k->makeSound();
	const WrongAnimal* l = new WrongCat();
	std::cout << l->getType() << ":" << std::endl;
	l->makeSound(); //will output the wrong cat sound!

	std::cout << std::endl
			<< "----------------------- Testing copies -----------------------"
			<< std::endl;

	Dog dog;
	Dog dog_copy(dog);
	std::cout << dog_copy.getType() << ":" << std::endl;
	dog_copy.makeSound();

	Dog* dog2 = new Dog();
	Dog dog2_copy(*dog2);
	std::cout << dog2_copy.getType() << ":" << std::endl;
	dog2_copy.makeSound();
	// Dog dog3(*j); // doesn't work because not every animal is a dog

	Cat cat;
	Cat cat_copy = cat;
	std::cout << cat_copy.getType() << ":" << std::endl;
	cat_copy.makeSound();

	Cat* cat2 = new Cat();
	Cat cat2_copy = *cat2;
	std::cout << cat2_copy.getType() << ":" << std::endl;
	cat2_copy.makeSound();
	// Cat cat3 = *i; // doesn't work because not every animal is a cat

	Animal animal1 = *j;
	std::cout << animal1.getType() << ":" << std::endl;
	animal1.makeSound();

	Animal animal2(*i);
	std::cout << animal2.getType() << ":" << std::endl;
	animal2.makeSound();

	Animal animal3 = Animal(dog);
	std::cout << animal3.getType() << ":" << std::endl;
	animal3.makeSound();

	Animal* animal4 = &dog;
	std::cout << animal4->getType() << ":" << std::endl;
	animal4->makeSound();

	Animal animal5 = cat;
	std::cout << animal5.getType() << ":" << std::endl;
	animal5.makeSound();

	Animal* animal6 = cat2;
	std::cout << animal6->getType() << ":" << std::endl;
	animal6->makeSound();

	std::cout << std::endl
			<< "----------------------- Deleting heap -----------------------"
			<< std::endl;

	delete meta;
	delete j;
	delete i;
	delete k;
	delete l;

	delete dog2;
	delete cat2;

	std::cout << std::endl
			<< "----------------------- Deleting stack -----------------------"
			<< std::endl;

	return 0;
}
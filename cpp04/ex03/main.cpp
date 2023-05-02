/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:45:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/02 00:21:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "utils.hpp"


void	pdfTest(void) {
	testDescription("---------------------- PDF tests ----------------------");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	materiaTests(void) {
	testDescription("---------------------- Amateria tests ----------------------");

	AMateria*	cure = new Cure();
	AMateria*	ice = new Ice();
	ICharacter* character1 = new Character();
	ICharacter* character2 = new Character();

	std::cout << BLUE << "Type: " << GREY << cure->getType() << RESET
			<< std::endl;
	cure->use(*character1);
	std::cout << BLUE << "Type: " << GREY << ice->getType() << RESET
			<< std::endl;
	ice->use(*character2);

	testDescription("testing clones:");
	AMateria* clone1;
	clone1 = cure->clone();
	std::cout << BLUE << "Clone1 type: " << GREY << clone1->getType() << RESET
			<< std::endl;
	clone1->use(*character1);
	AMateria* clone2;
	clone2 = ice->clone();
	std::cout << BLUE << "Clone2 type: " << GREY << clone2->getType() << RESET
			<< std::endl;
	clone2->use(*character2);

	delete cure;
	delete ice;
	delete clone1;
	delete clone2;
	delete character1;
	delete character2;
}

void characterTests(void) {
	testDescription("---------------------- ICharacter tests ----------------------");
	subTestDescription("Instanciate an random character:");
	ICharacter* i = new Character();
	std::cout << BLUE << "Name: " << GREY << i->getName() << std::endl;

	subTestDescription("Instanciate Yoda:");
	ICharacter* yoda = new Character("Yoda");
	std::cout << BLUE << "Name: " << GREY << yoda->getName() << std::endl;
	subTestDescription("Equip and use AMateria Cure:");
	yoda->equip(new Cure());
	yoda->use(0, *i);
	subTestDescription("Unequip an empty slot");
	yoda->unequip(2);
	subTestDescription("Equip all slots");
	yoda->equip(new Cure());
	yoda->equip(new Cure());
	yoda->equip(new Cure());
	subTestDescription("Equip with full slots and use all slots:");
	yoda->equip(new Ice());
	yoda->equip(new Ice());
	yoda->use(0, *i);
	yoda->use(1, *i);
	yoda->use(2, *i);
	yoda->use(3, *i);
	subTestDescription("Unequip one slot");
	yoda->unequip(2);
	subTestDescription("Equip again and use it:");
	yoda->equip(new Ice());
	yoda->use(2, *i);
	subTestDescription("Unequip an inexistent slot");
	yoda->unequip(5);
	subTestDescription("Unequip one slot and try to use it");
	yoda->unequip(0);
	yoda->use(0, *i);

	delete i;
	delete yoda;
	// check leaks for unused materias
}

// void materiaSourceTests(void) {

// }

int	main(void) {
	materiaTests();
	characterTests();
	// falta testar o operator= e o copy constructor dessas classes
	// materiaSourceTests();
	pdfTest();
	return 0;
}

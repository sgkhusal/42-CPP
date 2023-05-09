/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:45:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/08 23:50:19 by sguilher         ###   ########.fr       */
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

	// AMateria	materia; // error compilation: can't instanciate an abstract class
	subTestDescription("AMateria pointers with cure and ice types");
	AMateria*	cure = new Cure();
	AMateria*	materia1 = cure; // doesn't call constructor (pointer!)
	AMateria*	ice = new Ice();
	AMateria*	materia2 = ice;
	ICharacter* character1 = new Character();
	ICharacter* character2 = new Character();
	ICharacter* character3 = new Character();

	std::cout << BLUE << "Type: " << GREY << cure->getType() << RESET
			<< std::endl;
	cure->use(*character1);
	std::cout << BLUE << "Type: " << GREY << materia1->getType() << RESET
			<< std::endl;
	materia1->use(*character2);
	std::cout << BLUE << "Type: " << GREY << ice->getType() << RESET
			<< std::endl;
	ice->use(*character1);
	std::cout << BLUE << "Type: " << GREY << materia2->getType() << RESET
			<< std::endl;
	materia2->use(*character2);

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

	subTestDescription("testing copy constructor and assign operator for Cure");
	Cure cure2;
	Cure cure3 = Cure(cure2);
	Cure cure4;
	cure4 = cure2;
	std::cout << BLUE << "Type: " << GREY << cure2.getType() << RESET
			<< std::endl;
	cure2.use(*character1);
	std::cout << BLUE << "Type: " << GREY << cure3.getType() << RESET
			<< std::endl;
	cure3.use(*character2);
	std::cout << BLUE << "Type: " << GREY << cure4.getType() << RESET
			<< std::endl;
	cure4.use(*character3);

	subTestDescription("testing copy constructor and assign operator for Ice");
	Ice ice2;
	Ice ice4 = Ice(ice2);
	Ice ice5 = ice2;
	std::cout << BLUE << "Type: " << GREY << ice2.getType() << RESET
			<< std::endl;
	ice2.use(*character1);
	std::cout << BLUE << "Type: " << GREY << ice4.getType() << RESET
			<< std::endl;
	ice4.use(*character2);
	std::cout << BLUE << "Type: " << GREY << ice5.getType() << RESET
			<< std::endl;
	ice5.use(*character3);

	subTestDescription("deleting heap memory");
	delete cure;
	delete ice;
	delete clone1;
	delete clone2;
	delete character1;
	delete character2;
	delete character3;

	subTestDescription("calling destructors for stack memory");
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

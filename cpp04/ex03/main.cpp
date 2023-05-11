/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:45:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/11 12:36:02 by sguilher         ###   ########.fr       */
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
	src->learnMateria(new Ice()); // leak
	src->learnMateria(new Cure()); // leak
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
	// ICharacter icharacter; // error compilation: can't instanciate an interface
	subTestDescription("Instanciate an random character:");
	ICharacter* i = new Character();
	std::cout << BLUE << "Name: " << GREY << i->getName() << std::endl;

	subTestDescription("Instanciate Yoda:");
	ICharacter* yoda = new Character("Yoda");
	std::cout << BLUE << "Name: " << GREY << yoda->getName() << std::endl;
	subTestDescription("Equip and use AMateria Cure:");
	AMateria *materia = new Cure();
	yoda->equip(materia); // leak - idx=0
	yoda->use(0, *i);
	subTestDescription("Try to equip the same AMateria again");
	yoda->equip(materia);
	subTestDescription("Use an empty slot");
	yoda->use(1, *i);
	subTestDescription("Unequip an empty slot");
	yoda->unequip(2);
	subTestDescription("Equip all slots");
	yoda->equip(new Cure());
	yoda->equip(new Cure()); // leak - idx=2
	yoda->equip(new Cure());
	subTestDescription("Equip half full slots and use all slots:");
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

	subTestDescription("* testing copy constructor Character - ensure deep copy: *");
	subTestDescription("- Instantiate one Character and equip 2 slots");
	Character j;
	std::cout << BLUE << "Name: " << GREY << j.getName() << std::endl;
	j.equip(new Ice()); // TODO: testar passando o endereço de uma instância - dá problema nos deletes??
	j.equip(new Ice());
	subTestDescription("Use copy constructor and assign operator");
	Character k = Character(j); // leak from Ice::clone() const (Ice.cpp:35)
	std::cout << BLUE << "Name: " << GREY << k.getName() << std::endl;
	subTestDescription("- Instantiate one Character and equip all slots and equip one more time");
	Character l;
	std::cout << BLUE << "Name: " << GREY << l.getName() << std::endl;
	l.equip(new Cure());
	l.equip(new Cure());
	l.equip(new Cure());
	l.equip(new Cure());
	l.equip(new Ice()); // leak - slots full
	subTestDescription("Use assign operator - must delete all AMaterias in l");
	l = j; // leak from Ice::clone() const (Ice.cpp:35)
	std::cout << BLUE << "Name: " << GREY << l.getName() << std::endl;
	subTestDescription("Use AMateria in the copied Characters");
	k.use(0, *i);
	l.use(1, j);
	k.use(2, *i); // empty slot
	l.use(3, *yoda); // empty slot
	subTestDescription("Equip one slot and use it - in copy from copy constructor");
	k.equip(new Cure());
	k.use(2, *yoda);
	subTestDescription("Try to use the slot in the original Character and in the copy from assign copy");
	j.use(2, *yoda);
	l.use(2, *yoda);
	subTestDescription("Unequip one slot and try to use it - in copy from copy constructor");
	k.unequip(0);
	k.use(0, *i);
	subTestDescription("Unequip another slot and try to use it - in copy from assign operator");
	l.unequip(1);
	l.use(1, *i);
	subTestDescription("In the copied Character the slots numbers still should work:");
	j.use(0, *i);
	j.use(1, *i);

	subTestDescription("deleting heap memory");
	delete i;
	delete yoda;
	// TODO: check leaks for unused materias

	subTestDescription("calling destructors for stack memory");
}

// void materiaSourceTests(void) {

// }

int	main(void) {
	materiaTests();
	characterTests();
	// TODO: materiaSourceTests();
	pdfTest();
	return 0;
}

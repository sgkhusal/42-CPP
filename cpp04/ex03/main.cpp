/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:45:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:56:28 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
// #include "ICharacter.hpp"
// #include "Character.hpp"
// #include "IMateriaSource.hpp"
// #include "MateriaSource.hpp"
#include "tests.hpp"


// void	pdfTest(void) {
// 	testDescription("---------------------- PDF tests ----------------------");

// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
	
// 	delete bob;
// 	delete me;
// 	delete src;
// }

void	materiaTests(void) {
	testDescription("---------------------- Amateria tests ----------------------");
	
	AMateria*	cure = new Cure();
	AMateria*	ice = new Ice();

	std::cout << BLUE << "Type: " << GREY << cure->getType() << std::endl;
	// cure->use();
	std::cout << BLUE << "Type: " << GREY << ice->getType() << std::endl;
	// ice->use();

	testDescription("testing clones:");
	AMateria* clone1; 
	clone1 = cure->clone();
	std::cout << BLUE << "Clone1 type: " << GREY << clone1->getType() << std::endl;
	// clone1->use();
	AMateria* clone2; 
	clone2 = ice->clone();
	std::cout << BLUE << "Clone2 type: " << GREY << clone2->getType() << std::endl;
	// clone2->use();

	delete cure;
	delete ice;
	delete clone1;
	delete clone2;
}

// void characterTests(void) {
// 	testDescription("---------------------- ICharacter tests ----------------------");
// 	ICharacter* vader = new Character("Darth Vader");
// 	ICharacter* i = new Character();

// 	std::cout << BLUE << "Name: " << GREY << vader->getName() << std::endl;
// 	std::cout << BLUE << "Name: " << GREY << i->getName() << std::endl;
// }

// void materiaSourceTests(void) {
	
// }

int	main(void) {
	// materiaTests();
	std::cout << "test" << std::endl;
	return 0;
}

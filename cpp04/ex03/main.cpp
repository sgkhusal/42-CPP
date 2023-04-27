/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:45:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 11:56:03 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AMateria.hpp"
// #include "Cure.hpp"
// #include "Ice.hpp"
#include "tests.hpp"


void	pdf_test(void) {
	testDescription("---------------------- PDF tests ----------------------");
}

// void	materia_tests(void) {
// 	testDescription("---------------------- Amateria tests ----------------------");
	
// 	AMateria*	cure = new Cure();
// 	AMateria*	ice = new Ice();

// 	std::cout << BLUE << "Type: " << GREY << cure->getType() << std::endl;
// 	// cure->use();
// 	std::cout << BLUE << "Type: " << GREY << ice->getType() << std::endl;
// 	// ice->use();

// 	testDescription("testing clones:");
// 	AMateria* clone1; 
// 	clone1 = cure->clone();
// 	std::cout << BLUE << "Clone1 type: " << GREY << clone1->getType() << std::endl;
// 	// clone1->use();
// 	AMateria* clone2; 
// 	clone2 = ice->clone();
// 	std::cout << BLUE << "Clone2 type: " << GREY << clone2->getType() << std::endl;
// 	// clone2->use();

// 	delete cure;
// 	delete ice;
// 	delete clone1;
// 	delete clone2;
// }


int	main(void) {
	// materia_tests();
	std::cout << "test" << std::endl;
	return 0;
}

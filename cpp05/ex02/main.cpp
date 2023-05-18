/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:20:17 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/18 12:26:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

void	testDescription(std::string const& description) {
	std::cout << std::endl << BLUE << description << RESET << std::endl;
}

void	printGeneralClass(const std::string class_name) {
	std::cout << std::endl << std::endl;
	std::cout << YELLOW;
	for (int i = 0; i < 50; i++)
		std::cout << "-";
	std::cout << " " << class_name << " tests ";
	for (int i = 0; i < 50; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void	printException(std::exception& e) {
	std::cout << ORANGE << "Exception: " << e.what() << RESET << std::endl;
}

void	bureaucratTests(void) {
	printGeneralClass("Bureaucrat");

	testDescription("Creating bureaucrats with valids grades");
	Bureaucrat* b2 = NULL;
	try {
		Bureaucrat b1 = Bureaucrat("Fulano", 1);
		std::cout << b1 << std::endl;
		b2 = new Bureaucrat("Beltrano", 75);
		std::cout << *b2 << std::endl;
		Bureaucrat b3 = Bureaucrat("Ciclano", 150);
		std::cout << b3 << std::endl;
		Bureaucrat b4;
		std::cout << b4 << std::endl;
		delete b2;
	}
	catch (std::exception& e) {
		printException(e);
		if (b2)
			delete b2;
	}

	testDescription(
		"Create a bureaucrat with invalid grade greater than max grade - 0"
	);
	try {
		Bureaucrat b = Bureaucrat("Too efficient for a Bureaucrat", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception& e) {
		printException(e);
	}

	testDescription(
		"Create a bureaucrat pointer with invalid grade smaller than min grade - 151"
	);
	Bureaucrat* bptr = NULL;
	try {
		bptr = new Bureaucrat("Worse than a Bureaucrat", 151);
		std::cout << bptr << std::endl;
		delete bptr;
	}
	catch (std::exception& e) {
		printException(e);
		if (bptr)
			delete bptr;
	}

	testDescription(
		"Create a bureaucrat with invalid grade greater than max grade - -1000"
	);
	try {
		Bureaucrat b3 = Bureaucrat(Bureaucrat("político", -1000));
	}
	catch (std::exception& e) {
		printException(e);
	}

	testDescription("Incrementing a grade 3 should give a grade 2 to the bureaucrat");
	Bureaucrat b = Bureaucrat("Cartório", 3);
	std::cout << b << std::endl;
	b.incrementGrade();
	std::cout << b << std::endl;
	if (b.getGrade() != 2)
		std::cout << ORANGE << "KO" << std::endl;
	else
		std::cout << GREEN << "OK" << std::endl;

	testDescription("Decrementing");
	b.decrementGrade();
	std::cout << b << std::endl;
	if (b.getGrade() != 3)
		std::cout << ORANGE << "KO" << std::endl;
	else
		std::cout << GREEN << "OK" << std::endl;

	// Deep copy tests, increment and decrement throw tests
	{
		testDescription("Using copy constructor and assign operator");
		Bureaucrat copy1 = Bureaucrat(b);
		Bureaucrat copy2;
		copy2 = b;

		testDescription("decrementGrade throw exception");
		std::cout << copy1 << std::endl;
		try {
			while (true) {
				copy1.decrementGrade();
			}
		}
		catch (std::exception& e) {
			printException(e);
		}
		std::cout << copy1 << std::endl;

		testDescription("incrementGrade throw exception");
		std::cout << copy2 << std::endl;
		try {
			while (true) {
				copy2.incrementGrade();
			}
		}
		catch (std::exception& e) {
			printException(e);
		}
		std::cout << copy2 << std::endl;

		testDescription(
			"Ensure deep copy: grade b must be different from copy1 and copy2"
		);
		std::cout << "original: "<< b << std::endl;
		std::cout << "copy1:    " << copy1 << std::endl;
		std::cout << "copy2:    " << copy2 << std::endl;
		if (b.getGrade() != copy1.getGrade() && b.getGrade() != copy2.getGrade())
			std::cout << GREEN << "OK" << RESET << std::endl << std::endl;
		else
			std::cout << ORANGE << "KO" << RESET << std::endl << std::endl;
	}

	testDescription("Deep copy - original still must work:");
	b.decrementGrade();
	std::cout << "original: "<< b << std::endl;
}

// void	formTestCase0(const std::string name, const int sign, const int execute) {
// 	try {
// 		Form b = Form(name, sign, execute);
// 		std::cout << b << std::endl;
// 	}
// 	catch (std::exception& e) {
// 		printException(e);
// 	}
// }

// void	formTestCase1(const std::string name, const int sign, const int execute) {
// 	Form* bptr = NULL;
// 	try {
// 		bptr = new Form(name, sign, execute);
// 		std::cout << bptr << std::endl;
// 		delete bptr;
// 	}
// 	catch (std::exception& e) {
// 		printException(e);
// 		if (bptr)
// 			delete bptr;
// 	}
// }

// void	formTests(void) {
// 	printGeneralClass("Form");

// 	testDescription("Creating forms with valids grades");
// 	Form f1 = Form("Form 1", 1, 150);
// 	std::cout << f1 << std::endl;
// 	Form* f2 = NULL;
// 	f2 = new Form("Form 2", 150, 1);
// 	std::cout << *f2 << std::endl;
// 	Form f3;
// 	std::cout << f3 << std::endl;
// 	delete f2;

// 	testDescription(
// 		"Create a form with invalid sign grade greater than max grade - 0"
// 	);
// 	formTestCase0("Form A", 0, 130);

// 	testDescription(
// 		"Create a form with invalid sign grade smaller than min grade - 151"
// 	);
// 	formTestCase0("Form B", 151, 100);

// 	testDescription(
// 		"Create a form pointer with invalid execute grade greater than max grade - 0"
// 	);
// 	formTestCase1("Form C", 10, 0);

// 	testDescription(
// 		"Create a form pointer with invalid execute grade smaller than min grade - 151"
// 	);
// 	formTestCase1("Form D", 50, 151);

// 	testDescription("Using copy constructor and assign operator");
// 	Form copy1 = Form(f1);
// 	Form copy2;
// 	copy2 = copy1;
// 	std::cout << copy2 << std::endl;

// 	Bureaucrat b1 = Bureaucrat("Umbridge", 2);
// 	Bureaucrat b2 = Bureaucrat("Leopold", 1);

// 	testDescription(
// 			"Ensure deep copy: form f1 and copy1 must not be signed, copy2 must be signed"
// 		);
// 	b1.signForm(copy1);
// 	b2.signForm(copy2);

// 	// bureaucrats sometimes sign the same form more than once...
// 	b2.signForm(copy2);
// 	b1.setGrade(1);
// 	b1.signForm(copy2);

// 	if (!f1.getIsSigned() && !copy1.getIsSigned() && copy2.getIsSigned())
// 		std::cout << GREEN << "OK" << RESET << std::endl << std::endl;
// 	else
// 		std::cout << ORANGE << "KO" << RESET << std::endl << std::endl;
// 	std::cout << f1 << std::endl;
// 	std::cout << copy1 << std::endl;
// 	std::cout << copy2 << std::endl;
// }

int main(void) {
	bureaucratTests();
	// formTests();
	return 0;
}

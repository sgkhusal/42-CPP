/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:20:17 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/08 19:59:33 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
		std::cout << "original: " << b << std::endl;
		std::cout << "copy1:    " << copy1 << std::endl;
		std::cout << "copy2:    " << copy2 << std::endl;
		if (b.getGrade() != copy1.getGrade() && b.getGrade() != copy2.getGrade())
			std::cout << GREEN << "OK" << RESET << std::endl << std::endl;
		else
			std::cout << ORANGE << "KO" << RESET << std::endl << std::endl;
	}

	testDescription("Deep copy - original still must work:");
	b.decrementGrade();
	std::cout << "original: " << b << std::endl;
}

void	formTestCase1(AForm* form) {
	Bureaucrat b1 = Bureaucrat("Bureaucrat 1", 146);
	Bureaucrat b2 = Bureaucrat("Bureaucrat 2", 25);
	Bureaucrat b3 = Bureaucrat("Bureaucrat 3", 5);

	try {
		testDescription("The form can't be executed if it is not signed");
		form->execute(b2);
	}
	catch (std::exception& e) {
		printException(e);
	}

	testDescription("The form can't be signed by a lower sign grade");
	b1.signForm(*form);

	testDescription("The form is signed");
	b2.signForm(*form);

	try {
		testDescription("The form can't be executed by a lower execute grade");
		form->execute(b1);
	}
	catch (std::exception& e) {
		std::cout << ORANGE << e.what() << ": " << b1 << " couldn’t execute "
			<< form->getName() << " because it is necessary at least a grade "
			<< form->getExecuteGrade() << " to execute it." << RESET << std::endl;
	}

	testDescription("The form is executed several times... Because bureaucrats are not very smart");
	form->execute(b3);
	form->execute(b3);
	form->execute(b3);
	form->execute(b3);
	form->execute(b3);
	form->execute(b3);

	delete form;
}

void	formTestCase0(AForm& form, AForm& copy1, AForm& copy2) {
	std::cout << copy2 << std::endl;

	Bureaucrat b1 = Bureaucrat("Umbridge", 146);
	Bureaucrat b2 = Bureaucrat("Leopold", 25);

	testDescription(
			"Ensure deep copy: form and copy1 must not be signed, copy2 must be signed"
		);
	b1.signForm(copy1);
	b2.signForm(copy2);

	if (!form.getIsSigned() && !copy1.getIsSigned() && copy2.getIsSigned())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << ORANGE << "KO" << RESET << std::endl;
	std::cout << form << std::endl;
	std::cout << copy1 << std::endl;
	std::cout << copy2 << std::endl;

	testDescription(
			"bureaucrats sometimes sign the same form more than once..."
		);
	b2.signForm(copy2);
	b1.setGrade(25);
	b1.signForm(copy2);
}

void	shrubberyTests(void) {
	printGeneralClass("ShrubberyCreationForm");

	testDescription("Creating a ShrubberyCreationForm");
	ShrubberyCreationForm s("garden");
	std::cout << s << std::endl;
	AForm* sptr = new ShrubberyCreationForm("home");
	std::cout << *sptr << std::endl;

	// deep copy tests
	testDescription("Using copy constructor and assign operator");
	ShrubberyCreationForm copy1 = ShrubberyCreationForm(s);
	ShrubberyCreationForm copy2;
	copy2 = copy1;
	formTestCase0(s, copy1, copy2);

	formTestCase1(sptr);

	testDescription("Let's execute another shrubbery create form...");
	copy2.execute(Bureaucrat("Intern", 100));
}

void	robotomyTests(void) {
	printGeneralClass("RobotomyRequestForm");

	testDescription("Creating a RobotomyRequestForm");
	RobotomyRequestForm r("Tim Man");
	std::cout << r << std::endl;
	AForm* rptr = new RobotomyRequestForm("Tim Man");

	// deep copy tests
	testDescription("Using copy constructor and assign operator");
	RobotomyRequestForm copy1 = RobotomyRequestForm(r);
	RobotomyRequestForm copy2;
	copy1 = copy2;
	formTestCase0(r, copy1, copy2);

	formTestCase1(rptr);
}

void	presidentialTests(void) {
	printGeneralClass("PresidentialPardonForm");

	testDescription("Creating a PresidentialPardonForm");
	PresidentialPardonForm p("Severo Snape");
	std::cout << p << std::endl;
	AForm* pptr = new PresidentialPardonForm("Severo Snape");

	// deep copy tests
	testDescription("Using copy constructor and assign operator");
	PresidentialPardonForm copy1 = PresidentialPardonForm(p);
	PresidentialPardonForm copy2;
	copy2 = copy1;
	formTestCase0(p, copy1, copy2);

	formTestCase1(pptr);
}

int main(void) {
	bureaucratTests();
	shrubberyTests();
	robotomyTests();
	presidentialTests();
	return 0;
}

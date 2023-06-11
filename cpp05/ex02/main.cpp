/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:20:17 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/11 01:58:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testDescription(std::string const& description);
void	printTitle(std::string const& title);
void	printException(std::exception& e);

void	bureaucratTests(void);
void	shrubberyTests(void);
void	robotomyTests(void);
void	presidentialTests(void);

void	testCase0(AForm& form, AForm& copy1, AForm& copy2);
void	testCase1(AForm& form);

int main(void) {
	// bureaucratTests();

	shrubberyTests();
	robotomyTests();
	presidentialTests();

	std::cout << std::endl;

	return 0;
}

void	shrubberyTests(void) {
	printTitle("Ex02 - ShrubberyCreationForm");

	testDescription("Creating a ShrubberyCreationForm");
	ShrubberyCreationForm s("home");
	std::cout << s << std::endl;
	AForm* sptr = new ShrubberyCreationForm("garden");
	std::cout << *sptr << std::endl;

	// deep copy tests
	testDescription("Using copy constructor and assign operator");
	ShrubberyCreationForm copy1 = ShrubberyCreationForm(s);
	ShrubberyCreationForm copy2;
	copy2 = copy1;
	testCase0(s, copy1, copy2);

	testCase1(*sptr);

	testDescription("Let's execute another shrubbery create form...");
	copy2.execute(Bureaucrat("Intern", 100));

	delete sptr;
}

void	robotomyTests(void) {
	printTitle("Ex02 - RobotomyRequestForm");

	testDescription("Creating a RobotomyRequestForm");
	RobotomyRequestForm r("Tim Man");
	std::cout << r << std::endl;
	AForm* rptr = new RobotomyRequestForm("Marvin");
	std::cout << *rptr << std::endl;

	// deep copy tests
	testDescription("Using copy constructor and assign operator");
	RobotomyRequestForm copy1 = RobotomyRequestForm(r);
	RobotomyRequestForm copy2;
	copy1 = copy2;
	testCase0(r, copy1, copy2);

	testCase1(*rptr);
	delete rptr;
}

void	presidentialTests(void) {
	printTitle("Ex02 - PresidentialPardonForm");

	testDescription("Creating a PresidentialPardonForm");
	PresidentialPardonForm p("Arthur Dent");
	std::cout << p << std::endl;
	AForm* pptr = new PresidentialPardonForm("Ford Prefect");
	std::cout << *pptr << std::endl;

	// deep copy tests
	testDescription("Using copy constructor and assign operator");
	PresidentialPardonForm copy1 = PresidentialPardonForm(p);
	PresidentialPardonForm copy2;
	copy2 = copy1;
	testCase0(p, copy1, copy2);

	testCase1(*pptr);
	delete pptr;
}

void	testCase0(AForm& form, AForm& copy1, AForm& copy2) {
	std::cout << "original: " << form << std::endl;
	std::cout << "copy1: " << copy1 << std::endl;
	std::cout << "copy2: " << copy2 << std::endl;

	Bureaucrat b1 = Bureaucrat("B1", 146);
	Bureaucrat b2 = Bureaucrat("B2", 25);

	testDescription(
			"Ensure deep copy: form and copy1 must not be signed, copy2 must be signed"
		);
	b1.signForm(copy1); // B1 can sign the form
	b2.signForm(copy2);
	std::cout << "original: "<< form << std::endl;
	std::cout << "copy1:    " << copy1 << std::endl;
	std::cout << "copy2:    " << copy2 << std::endl;
	if (!form.getIsSigned() && !copy1.getIsSigned() && copy2.getIsSigned())
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << ORANGE << "KO" << RESET << std::endl;

	testDescription(
			"bureaucrats sometimes sign the same form more than once..."
		);
	b2.signForm(copy2);
	b1.setGrade(25);
	b1.signForm(copy2);
}

void	testCase1(AForm& form) {
	Bureaucrat b1 = Bureaucrat("B1", 146);
	Bureaucrat b2 = Bureaucrat("B2", 25);
	Bureaucrat b3 = Bureaucrat("B3", 5);

	testDescription("The form can't be executed if it is not signed");
	b2.executeForm(form);

	testDescription("The form can't be signed by a lower sign grade");
	b1.signForm(form);

	testDescription("The form is signed");
	b2.signForm(form);

	testDescription("The form can't be executed by a lower execute grade");
	b1.executeForm(form);

	testDescription(
		"The form is executed several times because... well, they are bureaucrats!");
	b3.executeForm(form);
	b3.executeForm(form);
	b3.executeForm(form);
	b3.executeForm(form);
	b3.executeForm(form);
	b3.executeForm(form);
}

void	bureaucratTests(void) {
	printTitle("Ex00");

	testDescription("Creating bureaucrats with valids grades");

    Bureaucrat b1 = Bureaucrat("Fulano", 1);
    std::cout << b1 << std::endl;

    Bureaucrat*b2 = new Bureaucrat("Beltrano", 150);
    std::cout << *b2 << std::endl;
    delete b2;

    Bureaucrat b3;
    std::cout << b3 << std::endl;

    testDescription(
        "Create a bureaucrat with invalid grade greater than max grade - 0"
    );
    try {
        Bureaucrat b = Bureaucrat("Too efficient for a Bureaucrat", 0);
        std::cout << ORANGE << "KO" << std::endl;
    }
    catch (std::exception& e) {
        printException(e);
        std::cout << GREEN << "OK" << std::endl;
    }

    testDescription(
        "Create a bureaucrat ptr with invalid grade smaller than min grade - 151"
    );
    Bureaucrat* bptr = NULL;
    try {
        bptr = new Bureaucrat("Worse than a Bureaucrat", 151);
        std::cout << ORANGE << "KO" << std::endl;
        delete bptr;
    }
    catch (std::exception& e) {
        printException(e);
        std::cout << GREEN << "OK" << std::endl;
        if (bptr)
            delete bptr;
    }

    testDescription("Incrementing a grade 3 should give a grade 2 to the bureaucrat");
    Bureaucrat b = Bureaucrat("Cartório", 3);
    std::cout << "before: " << b << std::endl;
    b.incrementGrade();
    std::cout << "after : " << b << std::endl;
    if (b.getGrade() != 2)
        std::cout << ORANGE << "KO" << std::endl;
    else
        std::cout << GREEN << "OK" << std::endl;

    testDescription("Decrementing a grade 2 should give a grade 3 to the bureaucrat");
    b.decrementGrade();
    std::cout << "after : " << b << std::endl;
    if (b.getGrade() != 3)
        std::cout << ORANGE << "KO" << std::endl;
    else
        std::cout << GREEN << "OK" << std::endl;

    // Deep copy tests, increment and decrement throw tests
    {
        testDescription("Using copy constructor and assign operator in a new context");
        std::cout << "original: " << b << std::endl;
        Bureaucrat copy1 = Bureaucrat(b);
        std::cout << "copy1: " << copy1 << std::endl;
        Bureaucrat copy2;
        copy2 = b;
        std::cout << "copy2: " << copy2 << std::endl;

        testDescription("using decrementGrade method for copy1 until exception");
        try {
            while (true) {
                copy1.decrementGrade();
            }
        }
        catch (std::exception& e) {
            printException(e);
        }
        std::cout << "copy1: " << copy1 << std::endl;

        testDescription("using incrementGrade method for copy2 until exception");
        try {
            while (true) {
                copy2.incrementGrade();
            }
        }
        catch (std::exception& e) {
            printException(e);
        }
        std::cout << "copy2: " << copy2 << std::endl;

        testDescription(
            "Ensure deep copy: grade b must be different from copy1 and copy2"
        );
        std::cout << "original: "<< b << std::endl;
        std::cout << "copy1:    " << copy1 << std::endl;
        std::cout << "copy2:    " << copy2 << std::endl;
        if (b.getGrade() != copy1.getGrade() && b.getGrade() != copy2.getGrade())
            std::cout << GREEN << "OK" << RESET << std::endl;
        else
            std::cout << ORANGE << "KO" << RESET << std::endl;
    }

    testDescription("Deep copy - after ending context, original still must work:");
    b.decrementGrade();
    std::cout << "original: "<< b << std::endl << std::endl;
}

void	testDescription(std::string const& description) {
	std::cout << std::endl << BLUE << description << RESET << std::endl;
}

void	printTitle(std::string const& title) {
	std::cout << std::endl << std::endl;
	std::cout << YELLOW;
	for (int i = 0; i < 50; i++)
		std::cout << "-";
	std::cout << " " << title << " tests ";
	for (int i = 0; i < 50; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void	printException(std::exception& e) {
	std::cout << ORANGE << "Exception: " << e.what() << RESET << std::endl;
}

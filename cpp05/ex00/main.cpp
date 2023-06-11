/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:20:17 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/10 23:02:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	testDescription(std::string const& description);
void	printException(std::exception& e);

int main(void) {
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

    return 0;
}

void	testDescription(std::string const& description) {
	std::cout << std::endl << BLUE << description << RESET << std::endl;
}

void	printException(std::exception& e) {
	std::cout << ORANGE << "Exception: " << e.what() << RESET << std::endl;
}

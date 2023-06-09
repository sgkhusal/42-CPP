/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:50:21 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/08 22:45:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string Intern::formsList[TOTAL_FORMS_TYPES] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::fptr	Intern::formsReference[TOTAL_FORMS_TYPES] = {
	&Intern::_makeShrubberyCreationForm,
	&Intern::_makeRobotomyRequestForm,
	&Intern::_makePresidentialPardonForm,
};

Intern::Intern(void) { }

Intern::Intern(Intern const& intern) {
	*this = intern;
}

Intern::~Intern(void) { }

Intern& Intern::operator=(Intern const& intern) {
	(void)intern;
	return *this;
}

AForm* Intern::_makeShrubberyCreationForm(std::string const& target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::_makeRobotomyRequestForm(std::string const& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::_makePresidentialPardonForm(std::string const& target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const& form_type, std::string const& target) {
	int i = 0;
	AForm* form = NULL;

	while (i < TOTAL_FORMS_TYPES) {
		if (form_type == Intern::formsList[i]) {
			form = (this->*formsReference[i])(target);
			std::cout << GREEN << "Intern creates " << form->getName()
				<< RESET << std::endl;
			return form;
		}
		i++;
	}
	std::cout << ORANGE << "Error: " << form_type
		<< " form does not exist in the forms list" << RESET << std::endl;
	return NULL;
}

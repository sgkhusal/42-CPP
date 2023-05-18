/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:54:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/18 12:30:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): 
	AForm("Shrubbery Creation Form", SCF_SIGN, SCF_EXEC) {
	_description("canonical constructor", "ShrubberyCreationForm");
	this->_target = "undefined";
}

ShrubberyCreationForm::ShrubberyCreationForm(
	std::string const& target
): AForm("Shrubbery Creation Form", SCF_SIGN, SCF_EXEC) {
	_description("grade constructor", "ShrubberyCreationForm");
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	_description("destructor", "ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(
	ShrubberyCreationForm const& form):
		AForm("Shrubbery Creation Form", SCF_SIGN, SCF_EXEC) {
	_description("copy constructor", "ShrubberyCreationForm");
	*this = form;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const& form) {
	_description("assign operator", "ShrubberyCreationForm");
	if (this != &form)
		this->_target = form.getTarget();
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) {
	// You have to check that the form is signed and 
	// that the grade of the bureaucrat attempting to execute the form 
	// is high enough. Otherwise, throw an appropriate exception.
	
	// Create a file <target>_shrubbery in the working directory, 
	// and writes ASCII trees inside it
	(void)executor;
}

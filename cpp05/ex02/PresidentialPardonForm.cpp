/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:54:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/22 10:40:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("Shrubbery Creation Form", PPF_SIGN, PPF_EXEC) {
	_description("canonical constructor", "PresidentialPardonForm");
	this->_target = "undefined";
}

PresidentialPardonForm::PresidentialPardonForm(
	std::string const& target
): AForm("Shrubbery Creation Form", PPF_SIGN, PPF_EXEC) {
	_description("grade constructor", "PresidentialPardonForm");
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	_description("destructor", "PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const& form):
		AForm("Shrubbery Creation Form", PPF_SIGN, PPF_EXEC) {
	_description("copy constructor", "PresidentialPardonForm");
	*this = form;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
	PresidentialPardonForm const& form) {
	_description("assign operator", "PresidentialPardonForm");
	if (this != &form)
		this->_target = form.getTarget();
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return this->_target;
}

void	PresidentialPardonForm::formAction(void) {
	std::cout << BLUE << this->getTarget()
			<< " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

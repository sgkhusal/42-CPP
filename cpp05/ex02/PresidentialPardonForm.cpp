/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:54:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/11 00:41:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("Presidential Pardon Form", PPF_SIGN, PPF_EXEC) {
	_description("canonical constructor", "PresidentialPardonForm");
	this->_target = "undefined";
}

PresidentialPardonForm::PresidentialPardonForm(
	std::string const& target
): AForm("Presidential Pardon Form", PPF_SIGN, PPF_EXEC) {
	_description("grade constructor", "PresidentialPardonForm");
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	_description("destructor", "PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const& form):
		AForm("Presidential Pardon Form", PPF_SIGN, PPF_EXEC) {
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

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	this->_checkPermissionToExecute(executor);
	std::cout << GREEN << this->getTarget()
			<< " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

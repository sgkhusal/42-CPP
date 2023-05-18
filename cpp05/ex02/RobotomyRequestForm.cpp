/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:54:35 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/18 12:30:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): 
	AForm("Shrubbery Creation Form", RRF_SIGN, RRF_EXEC) {
	_description("canonical constructor", "RobotomyRequestForm");
	this->_target = "undefined";
}

RobotomyRequestForm::RobotomyRequestForm(
	std::string const& target
): AForm("Shrubbery Creation Form", RRF_SIGN, RRF_EXEC) {
	_description("grade constructor", "RobotomyRequestForm");
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	_description("destructor", "RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(
	RobotomyRequestForm const& form):
		AForm("Shrubbery Creation Form", RRF_SIGN, RRF_EXEC) {
	_description("copy constructor", "RobotomyRequestForm");
*this = form;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
	RobotomyRequestForm const& form) {
	_description("assign operator", "RobotomyRequestForm");
	if (this != &form)
		this->_target = form.getTarget();
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) {
	// Makes some drilling noises. 
	// Then, informs that <target> has been robotomized successfully 
	// 50% of the time. Otherwise, informs that the robotomy failed
	(void)executor;
}

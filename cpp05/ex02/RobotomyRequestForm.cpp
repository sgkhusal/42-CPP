/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:54:35 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/11 00:53:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("Robotomy Request Form", RRF_SIGN, RRF_EXEC) {
	_description("canonical constructor", "RobotomyRequestForm");
	this->_target = "undefined";
}

RobotomyRequestForm::RobotomyRequestForm(
	std::string const& target
): AForm("Robotomy Request Form", RRF_SIGN, RRF_EXEC) {
	_description("grade constructor", "RobotomyRequestForm");
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	_description("destructor", "RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(
	RobotomyRequestForm const& form):
		AForm("Robotomy Request Form", RRF_SIGN, RRF_EXEC) {
	_description("copy constructor", "RobotomyRequestForm");
	*this = form;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
	RobotomyRequestForm const& form) {
	_description("assign operator", "RobotomyRequestForm");
	if (this != &form) {
		this->_target = form.getTarget();
	}
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	this->_checkPermissionToExecute(executor);
	std::cout << "*** drilling noises ***" << std::endl;
	if ((rand() % 2) % 2)
		std::cout << GREEN << this->getTarget()
				<< " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << ORANGE << this->getTarget()
				<< " robotomy failed..." << RESET << std::endl;
}

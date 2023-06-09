/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:54:35 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/08 20:05:12 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("Robotomy Request Form", RRF_SIGN, RRF_EXEC) {
	_description("canonical constructor", "RobotomyRequestForm");
	this->_target = "undefined";
	this->_nbAction = 0;
}

RobotomyRequestForm::RobotomyRequestForm(
	std::string const& target
): AForm("Robotomy Request Form", RRF_SIGN, RRF_EXEC) {
	_description("grade constructor", "RobotomyRequestForm");
	this->_target = target;
	this->_nbAction = 0;
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
		this->_nbAction = form.getNbAction();
	}
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}

int	RobotomyRequestForm::getNbAction(void) const {
	return this->_nbAction;
}

void	RobotomyRequestForm::formAction(void) {
	this->_nbAction += 1;
	std::cout << "*** drilling noises ***" << std::endl;
	if (this->_nbAction % 2)
		std::cout << GREEN << this->getTarget()
				<< " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << ORANGE << this->getTarget()
				<< " robotomy failed..." << RESET << std::endl;
}

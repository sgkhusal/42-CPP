/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:25:13 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/10 21:48:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void):
	_name("Generic form"),
	_is_signed(false),
	_sign_grade(rand() % MIN_GRADE + 1),
	_execute_grade(
		_sign_grade > MAX_GRADE + 50 ? rand() % (_sign_grade - 50) + 1 : 50
	)
{
	_description("canonical constructor", "AForm");
}

AForm::AForm(
	std::string const name, int const sign_grade, int const execute_grade
):
	_name(name),
	_is_signed(false),
	_sign_grade(_checkGrade(sign_grade)),
	_execute_grade(_checkGrade(execute_grade))
{
	_description("grade constructor", "AForm");
}

AForm::~AForm(void) {
	_description("destructor", "AForm");
}

AForm::AForm(AForm const& Aform):
	_name(Aform.getName()),
	_is_signed(Aform.getIsSigned()),
	_sign_grade(_checkGrade(Aform.getSignGrade())),
	_execute_grade(_checkGrade(Aform.getExecuteGrade()))
{
	_description("copy constructor", "AForm");
}

AForm& AForm::operator=(AForm const& Aform) {
	_description("assign operator", "AForm");
	if (this != &Aform) {
		const_cast<std::string&>(this->_name) = Aform.getName();
		this->_is_signed = Aform.getIsSigned();
		const_cast<int&>(this->_sign_grade) = Aform.getSignGrade();
		const_cast<int&>(this->_execute_grade) = Aform.getExecuteGrade();
	}
	return *this;
}

std::string	AForm::getName(void) const {
	return this->_name;
}

bool	AForm::getIsSigned(void) const {
	return this->_is_signed;
}

int	AForm::getSignGrade(void) const {
	return this->_sign_grade;
}

int	AForm::getExecuteGrade(void) const {
	return this->_execute_grade;
}

void	AForm::beSigned(Bureaucrat const& b) {
	if (b.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->_is_signed = true;
}

int	AForm::_checkGrade(int const grade) {
	if (grade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw AForm::GradeTooLowException();
	return grade;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form: grade to high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form: grade to low";
}

const char* AForm::FormNotSignException::what() const throw() {
	return "This form can not be executed because it is not signed!";
}

void	AForm::_description(
	std::string const description, std::string const class_name
) {
	if (DEBUG)
		std::cout << GREY << "Class " << class_name << " " << description
		<< " called for " << this->getName() << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& o, AForm const& form) {
	o << form.getName()
		<< " | Form is signed: " << (form.getIsSigned() ? "yes" : "no")
		<< " | Sign grade: " << form.getSignGrade()
		<< " | Execute grade: " << form.getExecuteGrade();
	return o;
}

void	AForm::execute(Bureaucrat const& executor) {
	if (this->getIsSigned() == false)
		throw FormNotSignException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	this->formAction();
}

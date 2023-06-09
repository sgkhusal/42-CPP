/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:42:39 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/08 23:39:57 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):
	_name("Generic form"),
	_is_signed(false),
	_sign_grade(rand() % MIN_GRADE + 1),
	_execute_grade(
		_sign_grade > MAX_GRADE + 50 ? rand() % (_sign_grade - 50) + 1 : 50
	)
{
	_description("canonical constructor");
}

Form::Form(
	const std::string name, const int sign_grade, const int execute_grade
):
	_name(name),
	_is_signed(false),
	_sign_grade(_checkGrade(sign_grade)),
	_execute_grade(_checkGrade(execute_grade))
{
	_description("grade constructor");
}

Form::~Form(void) {
	_description("destructor");
}

Form::Form(Form const& form):
	_name(form.getName()),
	_is_signed(form.getIsSigned()),
	_sign_grade(_checkGrade(form.getSignGrade())),
	_execute_grade(_checkGrade(form.getExecuteGrade()))
{
	_description("copy constructor");
}

Form& Form::operator=(Form const& form) {
	_description("assign operator");
	if (this != &form) {
		const_cast<std::string &>(this->_name) = form.getName();
		this->_is_signed = form.getIsSigned();
		const_cast<int &>(this->_sign_grade) = form.getSignGrade();
		const_cast<int &>(this->_execute_grade) = form.getExecuteGrade();
	}
	return *this;
}

std::string	Form::getName(void) const {
	return this->_name;
}

bool	Form::getIsSigned(void) const {
	return this->_is_signed;
}

int	Form::getSignGrade(void) const {
	return this->_sign_grade;
}

int	Form::getExecuteGrade(void) const {
	return this->_execute_grade;
}

void	Form::beSigned(Bureaucrat const& b) {
	if (b.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	this->_is_signed = true;
}

int	Form::_checkGrade(const int grade) {
	if (grade < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Form::GradeTooLowException();
	return grade;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form: grade to high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: grade to low";
}

void	Form::_description(const std::string description) {
	if (DEBUG)
		std::cout << GREY << this->getName() << " " << description
			<< " called" << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& o, Form const& form) {
	o << form.getName()
		<< " | Form is signed: " << (form.getIsSigned() ? "yes" : "no")
		<< " | Sign grade: " << form.getSignGrade()
		<< " | Execute grade: " << form.getExecuteGrade();
	return o;
}

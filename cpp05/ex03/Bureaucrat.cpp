/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:20:25 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/08 23:09:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
	_name("Bureaucrat with no name"),  _grade(rand() % MIN_GRADE + 1) {
	_description("canonical constructor");
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name) {
	_description("grade constructor");
	setGrade(grade);
}

Bureaucrat::~Bureaucrat(void) {
	_description("destructor");
}

Bureaucrat::Bureaucrat(Bureaucrat const& b) {
	_description("copy constructor");
	*this = b;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& b) {
	_description("assign operator");
	if (this != &b) {
		const_cast<std::string &>(this->_name) = b.getName();
		this->_grade = b.getGrade();
	}
	return *this;
}

std::string	Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::setGrade(const int grade) {
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade(void) {
	int new_grade = this->getGrade() - 1;
	if (new_grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = new_grade;
}

void	Bureaucrat::decrementGrade(void) {
	int new_grade = this->getGrade() + 1;
	if (new_grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = new_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high. Max grade is 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low. Min grade is 150";
}

void	Bureaucrat::_description(std::string description) {
	if (DEBUG)
		std::cout << GREY << this->getName() << " " << description << " called"
			<< RESET << std::endl;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& b) {
	o << b.getName() << " - bureaucrat grade " << b.getGrade();
	return o;
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName()
			<< std::endl;
	}
	catch (std::exception& e) {
		std::cout << ORANGE << e.what() << ": " << *this << " couldn’t sign "
			<< form.getName() << " because it is necessary at least a grade "
			<< form.getSignGrade() << " to sign it." << RESET << std::endl;
	}
}

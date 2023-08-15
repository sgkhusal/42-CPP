/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:39:02 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/15 10:35:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string const RPN::_validOperations = "+-/*";

RPN::RPN(std::string const input) {
	_checkInput(input);
	this->_input = input;
}

RPN::RPN(void) { }

RPN::~RPN(void) { }

RPN::RPN(RPN const& rpn) {
	*this = rpn;
}

RPN const& RPN::operator=(RPN const& rpn) {
	if (this != &rpn)
		this->_input = rpn.getExpression();
	return *this;
}

int RPN::executeRPN(void) {
	std::string::const_iterator it, end;
	std::stack<int>	stackOperation;
	int a, b;

	end = _input.end();
	for (it = _input.begin(); it != end; it++) {
		std::cout << *it << " ";
		if (*it == ' ')
			continue;
		else if (std::isdigit(*it))
			stackOperation.push(static_cast<int>(*it) - '0');
		else {
			if (stackOperation.size() < 2)
				throw ImpossibleOperation();
			b = stackOperation.top();
			stackOperation.pop();
			a = stackOperation.top();
			stackOperation.pop();
			stackOperation.push(_makeOperation(a, b, *it));
			std::cout << " = " << stackOperation.top() << std::endl;
		}
	}
	if (stackOperation.size() > 1 || stackOperation.size() == 0)
		throw ImpossibleOperation();
	return stackOperation.top();
}

int RPN::_makeOperation(int a, int b, char op) {
	// verificar a ordem de a e b
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '/')
		return a / b;
	if (op == '*')
		return a * b;
	throw ImpossibleOperation();
}

void RPN::_checkInput(std::string const input) {
	std::string::const_iterator it, end;

	// primeiro e segundo argumentos não podem ser operacões!!
	if (input.size() < 1)
		throw InvalidInput();
	end = input.end();
	for (it = input.begin(); it != end; it++) {
		if (
			!std::isdigit(input[0])
			&& _validOperations.find(input[0]) == std::string::npos
		)
			throw InvalidInput();
	}
}

std::string RPN::getExpression(void) const {
	return this->_input;
}

const char *RPN::InvalidInput::what() const throw() {
	return "Error: invalid input. RPN only accepts numbers 0 to 9"
		" and operators '+ - / *'";
}

const char *RPN::ImpossibleOperation::what() const throw() {
	return "Error: impossible operation";
}
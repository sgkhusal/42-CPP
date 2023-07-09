/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:08:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/09 00:59:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_str = "";
double		ScalarConverter::_check = 0.0;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const& scalar) {
	(void)scalar;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& scalar) {
	(void)scalar;
	return *this;
}

void ScalarConverter::convert(char const* value) {
	_str = static_cast<std::string>(value);
	std::stringstream ss;
	e_type type;

	type = _getType();

	if (type != CHAR) {
		ss << _str;
		ss >> _check;
	}

	switch(type)
	{
		case CHAR:
			_printType("CHAR");
			_convertChar();
			break;
		case INT:
			_printType("INT");
			_validateInteger();
			_convertInt();
			break;
		case FLOAT:
			_printType("FLOAT");
			_validateFloat();
			_convertFloat();
			break;
		case DOUBLE:
			_printType("DOUBLE");
			_convertDouble();
			break;
		case SPECIAL_CASE:
			_printType("SPECIAL CASE");
			_printSpecial();
			break;
		case INVALID:
			_printType("INVALID");
			throw NotSupportedTypeException();
	}
}

ScalarConverter::t_type ScalarConverter::_getType() {
	std::string::iterator it = _str.begin();
	std::size_t len = _str.length();
	bool has_dot = false;
	bool ends_with_f = false;

	if (_str == "-inff" || _str == "+inff" || _str == "nanf"
		|| _str == "-inf" || _str == "+inf" || _str == "nan")
		return SPECIAL_CASE;
	if (_str.empty())
		return CHAR;
	if (len == 1 && !std::isdigit(*it))
		return CHAR;

	if (*(_str.end() - 1) == 'f') {
		ends_with_f = true;
		_str.erase(len - 1);
		len--;
	}

	if (*it == '+' || *it == '-') {
		it++;
		len--;
		if (*it == '\0')
			return INVALID;
	}

	while (it != _str.end()) {
		if (!isdigit(*it)) {
			if (*it != '.' || (*it == '.' && has_dot))
				return INVALID;
			else if (*it == '.')
				has_dot = true;
		}
		it++;
	}

	if (has_dot) {
		if (ends_with_f)
			return FLOAT;
		return DOUBLE;
	}
	if (ends_with_f)
		return INVALID;
	return INT;
}

void ScalarConverter::_validateInteger(void) {
	if (_intOverflow())
		throw IntOverflowException();
}

void ScalarConverter::_validateFloat(void) {
	if (_check == INFINITY || _check == -INFINITY)
		return ;
	if (_floatOverflow())
		throw FloatOverflowException();
}

int ScalarConverter::_getPrecision(t_type const type) {
	int precision = PRECISION;

	if (type == FLOAT || type == DOUBLE) {
		precision = _str.length() - 1 - _str.find('.');
	}
	return precision ? precision : PRECISION;
}

void ScalarConverter::_convertChar(void) {
	char c = _str[0];

	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	if (isgraph(c))
		std::cout << std::setw(9) << "char: '" << c << "'" << std::endl;
	else
		std::cout << std::setw(23) << "char: Non displayable" << std::endl;
	std::cout << std::setw(8) << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(PRECISION);
	std::cout << std::setw(8) << "float: " << f << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(PRECISION);
	std::cout << std::setw(8) << "double: " << d << std::endl;
}

void ScalarConverter::_convertInt(void) {
	std::stringstream ss;
	int i;

	ss << _str;
	ss >> i;

	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	_printConversions(c, i, f, d, PRECISION);
}

void ScalarConverter::_convertFloat(void) {
	std::stringstream ss;
	int precision;
	float f;

	ss << _str;
	ss >> f;

	int i = static_cast<int>(f);
	char c = static_cast<char>(f);
	double d = static_cast<double>(f);

	precision = _getPrecision(FLOAT);
	_check = d;

	if (f == INFINITY || f == -INFINITY) {
		std::cout << std::setw(18) << "char: impossible" << std::endl;
		std::cout << std::setw(18) << "int: impossible" << std::endl;
		std::cout << std::setw(8) << "float: " << f << "f" << std::endl;
		std::cout << std::setw(8) << "double: " << d << std::endl;
	}
	else
		_printConversions(c, i, f, d, precision);
}

void ScalarConverter::_convertDouble(void) {
	std::stringstream ss;
	int precision;
	double max;
	double d;

	ss << _str;
	ss >> d;

	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	precision = _getPrecision(DOUBLE);
	max = std::numeric_limits<double>::max();

	if (d == INFINITY || d == -INFINITY || ((d == max || d == -max ) && !MAC)) {
		if (d == max)
			d = INFINITY;
		else if (d == -max)
			d = -INFINITY;
		std::cout << std::setw(18) << "char: impossible" << std::endl;
		std::cout << std::setw(18) << "int: impossible" << std::endl;
		std::cout << std::setw(8) << "float: " << f << "f" << std::endl;
		std::cout << std::setw(8) << "double: " << d << std::endl;
	}
	else
		_printConversions(c, i, f, d, precision);
}

void ScalarConverter::_printConversions(char c, int i, float f, double d, int precision) {
	_printChar(c);
	_printInt(i);
	_printFloat(f, precision);
	_printDouble(d, precision);
}

void ScalarConverter::_printChar(char c) {
	if (_charOverflow())
		std::cout << std::setw(18) << "char: impossible" << std::endl;
	else if (isgraph(c))
		std::cout << std::setw(9) << "char: '" << c << "'" << std::endl;
	else
		std::cout << std::setw(23) << "char: Non displayable" << std::endl;
}

void ScalarConverter::_printInt(int i) {
	if (_intOverflow())
			std::cout << std::setw(18) << "int: impossible" << std::endl;
	else
	std::cout << std::setw(8) << "int: " << i << std::endl;
}

void ScalarConverter::_printFloat(float f, int precision) {
	if (_floatOverflow())
			std::cout << std::setw(18) << "float: impossible" << std::endl;
	else {
		std::cout << std::fixed;
		std::cout.precision(precision);
		std::cout << std::setw(8) << "float: " << f << "f" << std::endl;
	}
}

void ScalarConverter::_printDouble(double d, int precision) {
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << std::setw(8) << "double: " << d << std::endl;
}

void ScalarConverter::_printSpecial(void) {
	std::stringstream ss;
	float f;
	double d;

	if (_str == "-inff" || _str == "+inff" || _str == "nanf") {
		_str.erase(_str.length() - 1, 1);
		ss << _str;
		ss >> f;
		d = static_cast<double>(f);
	}
	else {
		ss << _str;
		ss >> d;
		f = static_cast<float>(d);
	}

	std::cout << std::setw(8) << "char: " << "impossible" << std::endl;
	std::cout << std::setw(8) << "int: " << "impossible" << std::endl;
	if (MAC) {
		std::cout << std::setw(8) << "float: " << f << "f" << std::endl;
		std::cout << std::setw(8) << "double: " << d << std::endl;
	}
	else {
		std::cout << std::setw(8) << "float: " << _str << "f" << std::endl;
		std::cout << std::setw(8) << "double: " << _str << std::endl;
	}
}

bool ScalarConverter::_charOverflow() {
	return (_check > (double)(std::numeric_limits<char>::max())
		|| _check < (double)(std::numeric_limits<char>::min()));
}

bool ScalarConverter::_intOverflow() {
	return (_check > (double)(std::numeric_limits<int>::max())
		|| _check < (double)(std::numeric_limits<int>::min()));
}

bool ScalarConverter::_floatOverflow() {
	float max = std::numeric_limits<float>::max();

	return (_check > (double)(max) || _check < -(double)(max) - 1.0);
}

const char* ScalarConverter::NotSupportedTypeException::what() const throw() {
	return "Type not supported";
}

const char* ScalarConverter::IntOverflowException::what() const throw() {
	return "Input exceeds the maximum or minimum integer limits supported";
}

const char* ScalarConverter::FloatOverflowException::what() const throw() {
	return "Input exceeds the maximum or minimum float limits supported";
}

void ScalarConverter::_printType(std::string const& type) {
	if (DEBUG)
		std::cout << BLUE << type << RESET << std::endl;
}

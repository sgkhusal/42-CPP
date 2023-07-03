/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/03 10:20:34 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// std::string ScalarConverter::_specialDoubles[3] = {"-inf", "+inf", "nan"};
// std::string ScalarConverter::_specialFloats[3] = {"-inff", "+inff", "nanf"};

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const& scalar) {
    (void)scalar;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& scalar) {
    (void)scalar;
    return *this;
}

void ScalarConverter::convert(char const* value) { // check if use char* or std::string
    e_type type;

    type = _getType(value);
    switch(type)
    {
        case CHAR:
            _convertChar(value);
            break;
        case INT:
            _convertInt(value);
            break;
        case FLOAT:
            _convertFloat(value);
            break;
        case DOUBLE:
            _convertDouble(value);
            break;
        case SPECIAL_CASE:
            _printSpecial(value);
            break;
        default:
            throw NotSupportedTypeException();
    }
}

// std::cout.precision(5);

ScalarConverter::t_type ScalarConverter::_getType(char const* value) {
    std::string const& str = value;

    if (_isSpecial(str))
        return SPECIAL_CASE;
    if (_isChar(str))
        return CHAR;
    if (_isInt(value))
        return INT;
    if (_isDouble(value))
        return DOUBLE;
    if (_isFloat(value))
        return FLOAT;
    return INVALID;
}

bool ScalarConverter::_isSpecial(std::string const& str) {
    if (str == "-inff" || str == "+inff" || str == "nanf"
        || str == "-inf" || str == "+inf" || str == "nan")
        return true;
    return false;
}

bool ScalarConverter::_isChar(std::string const& str) {
    if (str == "c")
        return true;

    // std::string const& str = value;
    int len = str.length();
    if (str.empty())  // check - \0 ?
        return true;
    if (len == 1) {
        if (!std::isdigit(str[0])) {
            std::cout << "It's a char: " << str << std::endl;
        }  // char
            return true;
    }
    return false;
}

bool ScalarConverter::_isInt(std::string const& str) {
    // int - only numbers and - at first parameter;
    if (str == "123")
        return true;
    return false;
}

bool ScalarConverter::_isFloat(std::string const& str) {
    // float - numbers, -, . and f
    if (str == "42.0f")
        return true;
    return false;
}

bool ScalarConverter::_isDouble(std::string const& str) {
    // double - numbers , - and .
    if (str == "42.4221")
        return true;
    return false;
}

void ScalarConverter::_convertChar(char const* value) {
    // char c = value[0]; // não válido para o ç por exemplo!
    std::stringstream ss;
    char c;

    ss << value;
    ss >> c;

    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    // se caminho feliz
    ScalarConverter::_printConversions(c, i, f, d);
}

void ScalarConverter::_convertInt(char const* value) {
    int i = std::atoi(value);

    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    // se caminho feliz
    ScalarConverter::_printConversions(c, i, f, d);
}

void ScalarConverter::_convertFloat(char const* value) {
    std::string str = static_cast<std::string>(value);
    str.erase(str.length() - 1, 1);

    std::stringstream ss;
    float f;

    ss << value;
    ss >> f;

    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    double d = static_cast<double>(f);

    // se caminho feliz
    ScalarConverter::_printConversions(c, i, f, d);
}

void ScalarConverter::_convertDouble(char const* value) {
    // double d = std::atoi(value); ////////////////
    std::stringstream ss;
    double d;

    ss << value;
    ss >> d;

    int i = static_cast<int>(d);
    char c = static_cast<char>(d);
    float f = static_cast<float>(d);

    // se caminho feliz
    _printConversions(c, i, f, d);
}

void ScalarConverter::_printSpecial(char const* value) {
    std::string str = static_cast<std::string>(value);

    if (str == "-inff" || str == "+inff" || str == "nanf")
        str.erase(str.length() - 1, 1);
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << str << "f" << std::endl;
    std::cout << "double: " << str << std::endl;
}

void ScalarConverter::_printConversions(char c, int i, float f, double d) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

const char* ScalarConverter::NotSupportedTypeException::what() const throw() {
	return "Type not supported";
}

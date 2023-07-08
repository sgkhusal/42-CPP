/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/08 18:18:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_str = "";

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
    e_type type;

    type = _getType();
    switch(type)
    {
        case CHAR:
            _convertChar();
            break;
        case INT:
            _validateInteger();
            _convertInt();
            break;
        case FLOAT:
            _validateFloat();
            _convertFloat();
            break;
        case DOUBLE:
            _convertDouble();
            break;
        case SPECIAL_CASE:
            _printSpecial();
            break;
        default:
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
        return INVALID;
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
        if (*it == '\0')  // +f -f
            return INVALID;
    }

    while (it != _str.end()) {
        if (!isdigit(*it)) {
            if (*it != '.' || (*it == '.' && has_dot))
                return INVALID; // -123h456f 123.456oif 7.8.9
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
        return INVALID;  //  +42f -42f 42f
    return INT;
}

void ScalarConverter::_validateInteger(void) {
    std::stringstream ss;
    double check;

    ss << _str;
    ss >> check;
    if (check > (double)(std::numeric_limits<int>::max())
        || check < (double)(std::numeric_limits<int>::min()))
        throw IntOverflowException();
}

void ScalarConverter::_validateFloat(void) {
    std::stringstream ss;
    double check;

    ss << _str;
    ss >> check;
    if (check > (double)(std::numeric_limits<float>::max())
        || check < (double)(std::numeric_limits<float>::min()))
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
    std::stringstream ss;
    char c;

    ss << _str;
    ss >> c;

    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    _printConversions(c, i, f, d, PRECISION);
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

    _printConversions(c, i, f, d, precision);
}

void ScalarConverter::_convertDouble(void) {
    std::stringstream ss;
    int precision;
    double d;

    ss << _str;
    ss >> d;

    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    precision = _getPrecision(DOUBLE);

    _printConversions(c, i, f, d, precision);
}

void ScalarConverter::_printConversions(char c, int i, float f, double d, int precision) {
    std::stringstream ss;
    double check;

    ss << _str;
    ss >> check;

    _printChar(c, check);
    _printInt(i, check);
    _printFloat(f, check, precision);
    _printDouble(d, precision);
}

void ScalarConverter::_printChar(char c, double check) {
    if (check > (double)(std::numeric_limits<char>::max())
        || check < (double)(std::numeric_limits<char>::min()))
        std::cout << "char: overflow - impossible" << std::endl;
    else if (isprint(c) && !isspace(c)) // isgraph
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl << int(c) << std::endl;
}

void ScalarConverter::_printInt(int i, double check) {
    if (check > (double)(std::numeric_limits<int>::max())
        || check < (double)(std::numeric_limits<int>::min()))
            std::cout << "int: overflow - impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
}

void ScalarConverter::_printFloat(float f, double check, int precision) {
    if (((check > (double)(std::numeric_limits<float>::max())
        || check < (double)(std::numeric_limits<float>::min())) && check != INFINITY)) { // verificar esse INFINITY
            std::cout << "float: overflow - impossible" << std::endl;
    }
    else {
        if (precision > FLOAT_PRECISION)
            precision = FLOAT_PRECISION;
        std::cout << std::fixed;
        std::cout.precision(precision);
        std::cout << "float: " << f << "f" << std::endl;
    }
}

void ScalarConverter::_printDouble(double d, int precision) {
    if (precision > DOUBLE_PRECISION)
        precision = DOUBLE_PRECISION;
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "double: " << d << std::endl;
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

    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/04 23:30:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// std::string ScalarConverter::_specialDoubles[3] = {"-inf", "+inf", "nan"};
// std::string ScalarConverter::_specialFloats[3] = {"-inff", "+inff", "nanf"};
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
            _convertInt();
            break;
        case FLOAT:
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
        ||_str == "-inf" || _str == "+inf" || _str == "nan")
        return SPECIAL_CASE;
    if (_str.empty())
        return CHAR;  ///////////// INVALID?
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
        if (*it == '\0') // +f -f
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
            return FLOAT; // 12.f -12.f 42.42f
        return DOUBLE;  //  +12. 12. -78.90008
    }
    if (ends_with_f)
        return INVALID;  //  +12f -12f 12f
    return INT;
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
    int precision;
    char c;

    ss << ScalarConverter::_str;
    ss >> c;

    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    precision = _getPrecision(CHAR);

    _printChar(c);
    _printInt(i);
    std::cout.precision(precision);
    _printFloat(f);
    std::cout.precision(precision);
    _printDouble(d);
}

void ScalarConverter::_convertInt(void) {
    std::stringstream ss;
    int precision;
    int i;

    ss << ScalarConverter::_str;
    ss >> i;

    // if (*it == '+')
    //     _str.erase(len - 1);

    // verificar o tamanho, overflow
    // std::numeric_limits<int>::max()

    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    precision = _getPrecision(INT);

    _printChar(c);
    _printInt(i);
    std::cout.precision(precision);
    _printFloat(f);
    std::cout.precision(precision);
    _printDouble(d);
}

void ScalarConverter::_convertFloat(void) {
    std::stringstream ss;
    int precision;
    float f;

    // ss.precision(precision);
    ss << ScalarConverter::_str;
    ss >> f;

    ss << f;
    ss >> _str;
    // checar overflow

    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    double d = static_cast<double>(f);

    precision = _getPrecision(FLOAT);

    _printChar(c);
    _printInt(i);
    std::cout.precision(precision);
    _printFloat(f);
    std::cout.precision(precision);
    _printDouble(d);
}

void ScalarConverter::_convertDouble(void) {
    std::stringstream ss;
    int precision;
    double d;

    ss << ScalarConverter::_str;
    ss >> d;
    // std::cout << _str << std::endl;
    // std::cout << d << std::endl;

    int i = static_cast<int>(d);
    char c = static_cast<char>(d);
    float f = static_cast<float>(d);

    precision = _getPrecision(DOUBLE);

    if (_str == "-inf" || _str == "+inf" || _str == "nan")
    _printChar(c);
    _printInt(i);
    std::cout.precision(precision);
    _printFloat(f);
    std::cout.precision(precision);
    _printDouble(d);
}

void ScalarConverter::_printSpecial(void) {
    std::stringstream ss;
    float f;
    double d;

    ss << ScalarConverter::_str;
    if (_str == "-inff" || _str == "+inff" || _str == "nanf") {
        ss >> f;
        d = static_cast<double>(f);
    }
    else {
        ss >> d;
        f = static_cast<float>(d);
    }

    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;

    // if (_str == "-inff" || _str == "+inff" || _str == "nanf")
    //     _str.erase(_str.length() - 1, 1);
    // std::cout << "char: " << "impossible" << std::endl;
    // std::cout << "int: " << "impossible" << std::endl;
    // std::cout << "float: " << _str << "f" << std::endl;
    // std::cout << "double: " << _str << std::endl;
}

void ScalarConverter::_printChar(char c) {
    if (isprint(c) && !isspace(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else if ((c < 0) || c > 127)
        std::cout << "char: not an ascii char" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::_printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::_printFloat(float f) {
    std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::_printDouble(double d) {
    std::cout << "double: " << d << std::endl;
}


const char* ScalarConverter::NotSupportedTypeException::what() const throw() {
	return "Type not supported";
}

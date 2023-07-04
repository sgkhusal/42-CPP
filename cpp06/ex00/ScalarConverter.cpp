/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/04 02:05:05 by sguilher         ###   ########.fr       */
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

void ScalarConverter::convert(char const* value) { // check if use char* or std::string
    e_type type;
    _str = static_cast<std::string>(value);

    // std::stringstream ss;
    // float f;

    // ss << "42.032";
    // ss >> f;
    // std::cout << f << std::endl;

    type = _getType();
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

ScalarConverter::t_type ScalarConverter::_getType() {
    std::string::iterator it = _str.begin();
    std::size_t len = _str.length();
    bool has_dot = false;
    bool ends_with_f = false;

    if (_str == "-inff" || _str == "+inff" || _str == "nanf"
        || _str == "-inf" || _str == "+inf" || _str == "nan")
        return SPECIAL_CASE;
    if (_str.empty() || (len == 1 && !std::isdigit(*it)))
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

void ScalarConverter::_convertChar(char const* value) {
    // char c = value[0]; // não válido para o ç por exemplo!
    std::stringstream ss;
    char c;

    ss << value;
    ss >> c;

    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    ScalarConverter::_printConversions(c, i, f, d);
}

void ScalarConverter::_convertInt(char const* value) {
    int i = std::atoi(value);

    // if (*it == '+')
    //     _str.erase(len - 1);

    // verificar o tamanho, overflow

    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    // se caminho feliz
    ScalarConverter::_printConversions(c, i, f, d);
}

void ScalarConverter::_convertFloat(char const* value) {
    int precision = _str.length() - 1 - _str.find('.');
    std::stringstream ss;
    float f;

    printf("%d\n", precision);
    ss.precision(precision ? precision : 1);
    ss << value;
    ss >> f;

    int i = static_cast<int>(f);
    char c = static_cast<char>(f);
    double d = static_cast<double>(f);

    // se caminho feliz
    std::cout.precision(precision ? precision : 1);
    ScalarConverter::_printConversions(c, i, f, d);
}

void ScalarConverter::_convertDouble(char const* value) {
    // double d = std::atoi(value); ////////////////
    int precision = _str.length() - 1 - _str.find('.');
    std::stringstream ss;
    double d;

    printf("%d\n", precision);
    ss.precision(precision ? precision : 1);

    ss << value;
    ss >> d;

    int i = static_cast<int>(d);
    char c = static_cast<char>(d);
    float f = static_cast<float>(d);

    // se caminho feliz
    std::cout.precision(precision ? precision : 1);
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
    _printChar(c);
    _printInt(i);
    _printFloat(f);
    _printDouble(d);
}

void ScalarConverter::_printChar(char c) {
    if (isprint(c) && !isspace(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else if ((c < 0) || c > 127)
        std::cout << "char: not an ascii char" << std::endl;  ////////
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

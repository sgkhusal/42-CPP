/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/29 13:01:31 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::~ScalarConverter(void) {}
ScalarConverter::ScalarConverter(ScalarConverter const& scalar) {
    (void)scalar;
}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const& scalar) {
    (void)scalar;
    return *this;
}

void ScalarConverter::convert(char const* literal) { // check if use char* or std::string
    std::string value = literal;
    int len = value.length();

    if (value.empty())  // check - \0 ?
        return ;
    if (len == 1) {
        if (!isdigit(value[0])) {
            std::cout << "It's a char: " << value << std::endl;
        }  // char
            return ;
    }
    // int - only numbers and - ;
    // double - numbers , - and .
    // float - numbers, -, . and f
    
    // invalid type error
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:10:11 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/28 22:19:33 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::~ScalarConverter(void) {}
ScalarConverter::ScalarConverter(ScalarConverter const& scalar) {}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const& scalar) {}

void ScalarConverter::convert(char const* literal) {
    std::string value = literal;

    if (value.empty())  // check
        return ;
    if (value.length() == 1) {
        if (!isdigit(value[0]))  // char
            return ;
    }
        return ;  // verify if char (different than number)
    // int - only numbers and - ;
    // double - numbers , - and .
    // float - numbers, -, . and f
}

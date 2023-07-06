/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:56:02 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/06 12:04:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cmath>
#include <cassert>

#define BLUE	"\033[38;5;75m"
#define GREY	"\033[38;5;244m"
#define RESET	"\033[0m"

int main(void) {
	std::cout << std::endl << BLUE << "Integer:" << std::endl << GREY;
    std::cout << "Minimum value: " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "Maximum value: " << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<int>::has_infinity << std::endl;
	std::cout << std::numeric_limits<int>::has_quiet_NaN << std::endl;
	
    std::cout << std::endl << BLUE << "Float:" << std::endl << GREY;
	std::cout << "Minimum value: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "Maximum value: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << std::numeric_limits<float>::has_infinity << std::endl;
	std::cout << std::numeric_limits<float>::has_quiet_NaN << std::endl;

	std::cout << std::endl << BLUE << "Double:" << std::endl << GREY;
	std::cout << "Minimum value: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "Maximum value: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << std::numeric_limits<double>::has_infinity << std::endl;
	std::cout << std::numeric_limits<double>::has_quiet_NaN << std::endl << RESET;


	//Asserts floating point compatibility at compile time
    //static_assert(std::numeric_limits<float>::is_iec559, "IEEE 754 required");

    //C99
    float negative_infinity1 = -INFINITY;
    float negative_infinity2 = -1 * INFINITY;

    float negative_infinity3 = -std::numeric_limits<float>::infinity();
    float negative_infinity4 = -1 * std::numeric_limits<float>::infinity();

    std::cout << std::isinf(negative_infinity1) << negative_infinity1 << std::endl;
    std::cout << std::isinf(negative_infinity2) << negative_infinity2 << std::endl;
    std::cout << std::isinf(negative_infinity3) << negative_infinity3 << std::endl;
    std::cout << std::isinf(negative_infinity4) << negative_infinity4 << std::endl;

	std::cout << static_cast<std::string>(negative_infinity1) << std::endl;

    return EXIT_SUCCESS;
}

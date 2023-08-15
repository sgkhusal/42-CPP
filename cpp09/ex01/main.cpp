/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:39:04 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/15 11:14:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int argc, char* argv[]) {
	int result;

	if (argc == 1) {
		std::cout << "Error: missing inverted Polish expression" << std::endl;
		return 1;
	}
	if (argc > 2) {
		std::cout << "Error: too many arguments" << std::endl;
		return 1;
	}
	try {
		RPN rpn = RPN(argv[1]);
		if (DEBUG)
			std::cout << GREY << "Result for operation: " << rpn.getExpression()
					<< std::endl;
		result = rpn.executeRPN();
		std::cout << RESET << result << std::endl;
	} catch (std::exception const& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
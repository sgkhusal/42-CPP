/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:33:54 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 13:37:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	int	numberOfBalls = 42;
	int*	ballsPtr = &numberOfBalls; // a pointer to an int
	int&	ballsRef = numberOfBalls; // a type referenced on an int
	// for references, we assign the variable directly and not it address
	// the reference will be pointing on this variable
	// from that moment, I can't change where my reference is pointing out because it is const
	// you can't do this:
	// int&	ballsRef2; // create a reference without assign a value
	// Since it is const, I can't make a point to anything else later
	// a reference can't be void

	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	// the * de-referenced the pointer to access numberOfBalls
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84;
	std::cout << numberOfBalls << std::endl;

	return (0);
}

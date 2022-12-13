/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:20:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/13 14:29:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample8.class.hpp"

int	main(void)
{
	Sample	instance; // on the stack
	Sample	*instancep = &instance; // on the stack - equals to C

	// Sample::*p -> a pointer to a member attribute in Sample class
	// a pointer that allowed me to take an adress of a member attribute at
	// Sample class
	int		Sample::*p = NULL; // a pointer to an integer member of Sample class
	p = &Sample::foo; // assigned the foo member to the pointer
	// we can't assigne this way: p = &instance.foo, only if *p is declare as int *p
	// print the instance.foo initial value
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	// assigne a new value to foo using the pointer:
	instance.*p = 21; // strange because there isn't *p in the class
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	std::cout << "Value storage in pointer *p: " << instance.*p << std::endl;

	// a pointer to a member function in class Sample:
	// it's important to attempt the type of return and inputs and if it is
	// const or not, otherwise it is not going to work
	void	(Sample::*f)(void) const;
	f = &Sample::bar; //assigned the bar member function to the function pointer
	// to execute the function we need to indicate what instance the pointer is part of
	(instance.*f)();
	(instancep->*f)();

	return (0);
}

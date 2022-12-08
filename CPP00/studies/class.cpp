/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:37:01 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/07 21:31:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"
#include "Sample1.class.hpp"
#include "Sample2.class.hpp"

int	main(void)
{
	Sample	sample_instance;

	//sample_instance.foo = 42;
	std::cout << "sample_instance.foo = " << sample_instance.foo << std::endl;
	sample_instance.bar();
	std::cout << std::endl;

	// Constructors with input
	Sample1	class1('a', 42, 42.42f);
	std::cout << std::endl;
	Sample2	class2('a', 24, 42.24f);
	return (0);
}

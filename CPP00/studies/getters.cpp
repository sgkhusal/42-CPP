/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:20:03 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 17:37:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample5.class.hpp"

int	main(void)
{
	Sample5	instance;

	instance.setFoo(42);
	std::cout << "instance..getFoo() = " << instance.getFoo() << std::endl;
	instance.setFoo(-42);
	std::cout << "instance..getFoo() = " << instance.getFoo() << std::endl;
	return (0);
}

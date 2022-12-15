/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:19:25 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 16:37:31 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample4.class.hpp"

// we can't use private atributes outside the class,
// otherwise it will not compile
int	main(void)
{
	Sample4	instance;

	instance.publicFoo = 42;
	std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;
	instance.publicBar();
	//instance._privateFoo = 42;
	//std::cout << "instance._privateFoo: " << instance._privateFoo << std::endl;
	//instance._privateBar();
	return 0;
}

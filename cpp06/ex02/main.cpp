/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:47:39 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/09 21:37:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include <unistd.h>

int	main(void) {
	Base *ptr;

	for (int i = 0; i < 10; i++) {
		std::cout << BLUE << "Random test " << i + 1 << GREY << std::endl;
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
		std::cout << RESET << std::endl;
		sleep(1);
	}

	std::cout << BLUE << "Testing an invalid pointer" << GREY << std::endl;
	ptr = new Base();
	identify(ptr);
	identify(*ptr);

	delete ptr;
	return 0;
}

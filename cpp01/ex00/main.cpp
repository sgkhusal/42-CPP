/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:34:43 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/29 19:12:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	putText(std::string text, std::string color) {
	std::cout << std::endl << color << text << RESET << std::endl;
}

int	main(void) {
	Zombie fred = Zombie("Frederico");
	Zombie *george = newZombie("George");

	putText("Zombie on stack:", ORANGE);
	fred.announce();

	putText("Zombie on heap: newZombie function:", ORANGE);
	george->announce();

	putText("randomChump function: another zombie on stack:", ORANGE);
	randomChump("Rony");

	putText("Delete zombie on heap:", RED);
	delete george;

	putText("End", RED);
	return (0);
}

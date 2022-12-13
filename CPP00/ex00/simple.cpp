/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:23:14 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/13 18:33:40 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	printStringInUppercase(char *character)
{
	while (*character)
	{
		std::cout << (char)toupper(*character);
		character++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*(++argv))
			printStringInUppercase(*argv);
		std::cout << std::endl;
	}
	return (0);
}

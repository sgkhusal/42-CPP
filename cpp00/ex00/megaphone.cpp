/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:25:49 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/28 21:30:40 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static void	amplifyMessage(std::string *message)
{
	for (size_t i = 0; i < message->length(); i++)
		(*message)[i] = toupper((*message)[i]);
}

static void	megaphone(std::string message)
{
	if (message.length() == 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		amplifyMessage(&message);
		std::cout << message << std::endl;
	}
}

int	main(int argc, char *argv[])
{
	std::string	message;

	for (int i = 1; i < argc; i++)
		message.append(argv[i]);
	megaphone(message);
	return (0);
}

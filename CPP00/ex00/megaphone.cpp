/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:25:49 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/13 18:46:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* static void	amplifyMessage(std::string *message)
{
	char	*c;

	c = message;
	while (*c)
	{
		*c = toupper(*c);
		c++;
	}
} */

static void	megaphone(std::string message)
{
	if (message.length() == 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		//amplifyMessage(&message);
		std::cout << message << std::endl;
	}
}

static std::string	appendMessage(char **words)
{
	std::string	str;

	while (*words)
	{
		str.append(*words);
		words++;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	std::string	message;

	if (argc > 1)
		message = appendMessage(&argv[1]);
	megaphone(message);
	return (0);
}

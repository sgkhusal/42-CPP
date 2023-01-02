/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference2.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:50:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 14:00:36 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	byPtr(std::string* str) {
	*str += " and ponies";
}

void	byConstPtr(std::string const * str) {
	std::cout << *str << std::endl;
}

void	byRef(std::string& str) {
	str += " and ponies";
}

void	byConstRef(std::string const & str) {
	std::cout << str << std::endl;
}

int	main(void) {
	std::string str = "i like buttlerflies";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";

	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return (0);
}

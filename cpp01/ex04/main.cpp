/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:39:08 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/03 18:31:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char *argv[]) {
	std::string		infile;
	std::string		s1;
	std::string		s2;
	
	if (argc != 4) {
		std::cout << "Wrong number of parameters: [filename] [s1] [s2]" << std::endl;
		return (1);
	}
	infile.append(argv[1]);
	Sed sed = Sed(infile);
	s1.append(argv[2]);
	s2.append(argv[3]);
	sed.replace(s1, s2);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:39:08 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/04 17:22:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char *argv[]) {
	std::string		infile;
	std::string		s1;
	std::string		s2;
	Sed				sed;

	if (argc != 4) {
		std::cout << "Wrong number of parameters: ./sed [filename] [s1] [s2]"
				<< std::endl;
		return (1);
	}
	infile.append(argv[1]);
	s1.append(argv[2]);
	s2.append(argv[3]);
	sed.replace(s1, s2, infile);
	return (0);
}

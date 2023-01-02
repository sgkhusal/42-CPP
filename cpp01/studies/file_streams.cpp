/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_streams.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:37:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 14:42:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main (void) {
	//std::ifstream	ifs("numbers");
	std::ifstream	ifs;
	std::ofstream	ofs("test.out");
	unsigned int	dst;
	unsigned int	dst2;

	ifs.open("numbers");
	ifs >> dst >> dst2;
	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	ofs << "i like ponies a whole damn lot" << std::endl;
	ofs.close();
}

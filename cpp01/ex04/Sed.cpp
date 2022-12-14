/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:15:35 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/04 22:52:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(void) {
	return ;
}

Sed::~Sed(void) {
	return ;
}

std::string const	Sed::_read(std::string const filename) {
	std::string			buffer;
	std::ifstream		ifs;
	std::ostringstream	outputStringStream;

	ifs.open(filename.c_str());
	if (ifs.fail()) {
		std::cerr << "Error reading " << filename << std::endl;
		exit(1);
	}
	outputStringStream << ifs.rdbuf();
	buffer = outputStringStream.str();
	ifs.close();
	return (buffer);
}

std::string const	Sed::_replace(std::string const s1,
								std::string const s2,
								std::string const str) {
	size_t	pos;

	pos = str.find(s1);
	if (pos == std::string::npos)
		return (str);
	return (str.substr(0, pos) + s2 + _replace(s1, s2,
		str.substr(pos + s1.size(), str.size() - pos - s1.size())));
}

void	Sed::_write(std::string const content, std::string const filename) {
	std::ofstream	ofs;

	ofs.open((filename).c_str());
	if (ofs.fail()) {
		std::cerr << "Error creating " << filename << std::endl;
		exit(2);
	}
	ofs << content;
	ofs.close();
}

void	Sed::replace(std::string const s1,
					std::string const s2,
					std::string const filename) {
	std::string	buffer;
	std::string	outfile;

	buffer = _replace(s1, s2, _read(filename));
	outfile = filename + ".replace";
	_write(buffer, outfile);
}

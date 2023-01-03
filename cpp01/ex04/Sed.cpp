/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:15:35 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/03 19:03:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string const inputFileName): _infile(inputFileName),
										_outfile(this->_infile + ".replace") {
	return ;
}

Sed::~Sed() {
	return ;
}

std::string	Sed::_getFileContent(void) {
	std::string			buffer;
	std::ifstream	    infileStream;
	std::ostringstream	stringBufferStream;
	
	infileStream.open(this->_infile.c_str());
	stringBufferStream << infileStream.rdbuf();
	buffer = stringBufferStream.str();
	infileStream.close();
	return (buffer);
}

std::string	Sed::_newContent(std::string str, std::string const s1, std::string const s2) {
	size_t	pos;
	
	pos = str.find(s1);
	if (pos == std::string::npos)
		return (str);
	return (str.substr(0, pos) + s2 + _newContent(
		str.substr(pos + s1.size(), str.size() - pos - s1.size()), s1, s2));
}

void Sed::replace(std::string const s1, std::string const s2) {
	std::string			buffer;
	std::ofstream	    outfileStream;
	std::istringstream	stringBufferStream;

	buffer = _newContent(_getFileContent(), s1, s2);
	outfileStream.open(this->_outfile.c_str());
	stringBufferStream.str(buffer);
	stringBufferStream >> outfileStream.rdbuf();
	outfileStream.close();
}
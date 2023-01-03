/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:15:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/03 19:03:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Sed
{
private:
	std::string const	_infile;
	std::string const	_outfile;
	std::string			_getFileContent(void);
	std::string			_newContent(std::string buffer, std::string s1, std::string s2);
public:
	Sed(std::string const inputFileName);
	~Sed();
	void    replace(std::string s1, std::string s2);
};

#endif
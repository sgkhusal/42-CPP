/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:15:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/04 22:52:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

#include <string>
#include <fstream> // ifstream, ofstream
#include <sstream> // ostringstream
#include <iostream> // cerr
#include <cstdlib> // exit

class Sed
{
	private:
		std::string const	_read(std::string const filename);
		std::string	const	_replace(std::string const s1,
									std::string const s2,
									std::string const str);
		void				_write(std::string const content,
									std::string const filename);
	public:
		Sed(void);
		~Sed(void);
		void	replace(std::string const s1,
						std::string const s2,
						std::string const filename);
};

#endif

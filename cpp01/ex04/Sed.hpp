/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:15:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

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

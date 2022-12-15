/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:32:17 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/14 19:27:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CONTACT_H
# define CONTACT_H

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void		set_name(std::string name);
		std::string	get_name(void);
		void		set_last_name(std::string last_name);
		std::string	get_last_name(void);
		void		set_nickname(std::string nickname);
		std::string	get_nickname(void);
		void		set_phone_number(std::string phone_number);
		std::string	get_phone_number(void); // talvez não precise
		void		set_darkest_secret(std::string darkest_secret);
		std::string	get_darkest_secret(void); // talvez não precise
	private:
		std::string	_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif

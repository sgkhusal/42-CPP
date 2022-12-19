/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:32:17 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/19 15:09:59 by sguilher         ###   ########.fr       */
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
		void		setFirstName(std::string firstName);
		std::string	getFirstName(void);
		void		setLastName(std::string lastName);
		std::string	getLastName(void);
		void		setNickname(std::string nickname);
		std::string	getNickname(void);
		void		setPhoneNumber(std::string phoneNumber);
		std::string	getPhoneNumber(void);
		void		setDarkestSecret(std::string darkestSecret);
		std::string	getDarkestSecret(void);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:32:17 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/28 17:40:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void		getContactInfosFromUser(void);
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickname(std::string nickname);
		void		setPhoneNumber(std::string phoneNumber);
		void		setDarkestSecret(std::string darkestSecret);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		typedef void(Contact::* fptr)(std::string);
		void		_getInfo(const char* info, fptr setter);
		void		_cleanInput(std::string *value);
};

#endif

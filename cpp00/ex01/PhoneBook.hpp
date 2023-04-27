/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:30:10 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iomanip> // std::setw
# include <iostream>
# include "Contact.hpp"
# include "Texts.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void		addContact(void);
		void		searchContactList(void);
		typedef enum e_actions {
			NONE,
			ADD,
			SEARCH,
			EXIT
		}				t_actions;
	private:
		Contact		_contacts[8];
		int			_qty;
		int			_older_contact;
		int			_defineContactIndex(void);
		void		_printContactList(void);
		void		_printListFormat(std::string info);
		void		_printContactInfo(int index);
		void		_printInfo(const char *name, std::string info);
};

#endif

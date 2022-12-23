/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:30:10 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/23 17:58:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void		addContact(void);
		void		searchContactList(void);
	private:
		Contact		_contacts[8];
		int			_qty;
		int			_older_contact;
		int			_defineContactIndex(void);
		void		_printContactList(void);
		void		_printContactInfo(int index);
		void		_printInfo(const char *name, std::string info);
};

#endif

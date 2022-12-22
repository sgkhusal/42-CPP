/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:30:10 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/22 00:22:57 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

// array of contacts of size
// function add contact (accepts only 8)
// dynamic allocation is forbidden

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

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
};

#endif

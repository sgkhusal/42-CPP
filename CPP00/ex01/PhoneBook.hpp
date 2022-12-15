/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:30:10 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/14 19:31:24 by sguilher         ###   ########.fr       */
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
		std::string	searchContact(int index); // checar
		void		exitPhoneBook();
	private:
		int			_qty;
		int			_older_contact;
};

#endif

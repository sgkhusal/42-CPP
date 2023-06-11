/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:29:06 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/11 00:54:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

# define SCF_SIGN 145
# define SCF_EXEC 137

class ShrubberyCreationForm: public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const& form);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& form);

		ShrubberyCreationForm(std::string const& target);

		std::string	getTarget(void) const;

		void		execute(Bureaucrat const& executor) const;

	private:
		std::string	_target;

		class CreateFileException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

#endif

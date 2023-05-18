/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:29:06 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/18 12:26:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

# define SCF_SIGN 145
# define SCF_EXEC 137

class ShrubberyCreationForm: public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const& form);
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& form);

		ShrubberyCreationForm(std::string const& target);

		void	execute(Bureaucrat const & executor);

		std::string	getTarget(void) const;
	
	private:
		std::string	_target;
};

#endif

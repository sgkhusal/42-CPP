/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:50:34 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/18 12:26:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

# define PPF_SIGN 25
# define PPF_EXEC 5

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const& form);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm& operator=(PresidentialPardonForm const& form);

		PresidentialPardonForm(std::string const& target);

		void	execute(Bureaucrat const & executor);

		std::string	getTarget(void) const;
	
	private:
		std::string	_target;
};

#endif

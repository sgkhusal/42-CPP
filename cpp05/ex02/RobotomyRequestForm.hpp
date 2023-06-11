/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:51:33 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/11 00:54:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

# define RRF_SIGN 72
# define RRF_EXEC 45

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const& form);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm& operator=(RobotomyRequestForm const& form);

		RobotomyRequestForm(std::string const& target);

		std::string	getTarget(void) const;

		void		execute(Bureaucrat const& executor) const;

	private:
		std::string	_target;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:13:58 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/11 00:41:21 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(void);
		AForm(AForm const& form);
		virtual ~AForm(void);
		AForm& operator=(AForm const& form);

		AForm(
			std::string const name,
			int const sign_grade,
			int const execute_grade
		);

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;

		void			beSigned(Bureaucrat const& b);
		virtual void	execute(Bureaucrat const& executor) const = 0;

	protected:
		void		_checkPermissionToExecute(Bureaucrat const& executor) const;
		void		_description(
			std::string const description, std::string const class_name
		);

	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_sign_grade;
		int const			_execute_grade;

		int		_checkGrade(int const grade);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoPermissionException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& o, AForm const& form);

#endif

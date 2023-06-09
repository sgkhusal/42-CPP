/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:13:58 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/08 20:03:08 by sguilher         ###   ########.fr       */
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
			const std::string name,
			const int sign_grade,
			const int execute_grade
		);

		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;

		void			beSigned(Bureaucrat const& b);
		void			execute(Bureaucrat const& executor);

	protected:
		virtual void	formAction(void) = 0; // será que eu deixo protected?
		void			_description(
			const std::string description, const std::string class_name
		);

	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_execute_grade;

		int		_checkGrade(const int grade);

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
};

std::ostream& operator<<(std::ostream& o, AForm const& form);

#endif

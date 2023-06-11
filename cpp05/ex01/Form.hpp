/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:13:58 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/10 21:48:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(void);
		Form(Form const& form);
		~Form(void);
		Form& operator=(Form const& form);

		Form(
			std::string const name,
			int const sign_grade,
			int const execute_grade
		);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;

		void		beSigned(Bureaucrat const& b);

	private:
		std::string const	_name;
		bool				_is_signed;
		int const			_sign_grade;
		int const			_execute_grade;

		void	_description(std::string const description);
		int		_checkGrade(int const grade);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& o, Form const& form);

#endif

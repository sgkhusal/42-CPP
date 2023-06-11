/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:20:23 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/11 00:06:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <cstdlib>
# include <iostream>

# include "AForm.hpp"

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

# ifndef DEBUG
    #define DEBUG false
# endif

# define MAX_GRADE 1
# define MIN_GRADE 150

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const& b);
		~Bureaucrat(void);
		Bureaucrat& operator=(Bureaucrat const& b);

		Bureaucrat(std::string const name, int const grade);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		setGrade(int const grade);
		void		incrementGrade(void);
		void		decrementGrade(void);

		void		signForm(AForm &form);
		void		executeForm(AForm const & form);

	private:
		std::string const	_name;
		int					_grade;

		void	_description(std::string const description);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& b);

#endif

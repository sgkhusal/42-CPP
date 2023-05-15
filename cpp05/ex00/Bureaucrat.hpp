/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:20:23 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/15 00:13:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <cstdlib>
# include <iostream>

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

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const& b);
		~Bureaucrat(void);
		Bureaucrat& operator=(Bureaucrat const& b);

		Bureaucrat(std::string name, int grade);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		setGrade(int grade);
		void		incrementGrade(void);
		void		decrementGrade(void);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw(); // precisa do virtual? no vídeo da intra o cara coloca
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw(); //
		};

	private:
		const std::string	_name;
		int					_grade;

		void	_description(std::string description);

};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& b);

#endif

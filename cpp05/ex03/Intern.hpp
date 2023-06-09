/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:08:22 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/08 22:23:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

# define TOTAL_FORMS_TYPES 3

class Intern {

public:
	Intern(void);
	Intern(Intern const& intern);
	~Intern(void);
	Intern& operator=(Intern const& intern);

	AForm* makeForm(std::string const& form_type, std::string const& target);

private:
	typedef	AForm* (Intern::* fptr)(std::string const&) const;
	static	std::string formsList[TOTAL_FORMS_TYPES];
	static fptr	formsReference[TOTAL_FORMS_TYPES];

	AForm* _makeShrubberyCreationForm(std::string const& target) const;
	AForm* _makeRobotomyRequestForm(std::string const& target) const;
	AForm* _makePresidentialPardonForm(std::string const& target) const;

};

#endif

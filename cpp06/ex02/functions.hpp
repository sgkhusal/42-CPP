/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:30:52 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/09 20:22:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include <iostream>
# include <exception>
# include <cmath>

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

# ifndef DEBUG
    #define DEBUG false
# endif

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif

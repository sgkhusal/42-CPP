/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:02:07 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/06 17:09:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_UTILS
# define TESTS_UTILS

# include <string>
# include <iostream>

# ifndef DEBUG
    #define DEBUG false
# endif

# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define ORANGE	"\033[0;38;5;166m"
# define PURPLE	"\033[38;5;200m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

void printTitle(std::string const& title);
void printDescription(std::string const& description);
void printSubDescription(std::string const& description);
void printResult(bool ok);

#endif
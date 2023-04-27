/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:52:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 11:22:31 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

#include <iostream>
#include <string>

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

void	testDescription(std::string description);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:12:57 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/27 16:17:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>

# ifndef DEBUG
    #define DEBUG false
# endif

# define GREY	"\033[38;5;244m"
# define ORANGE	"\033[0;38;5;166m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

void printDetails(int iteration, int size, int element_size, int pair_size);

#endif
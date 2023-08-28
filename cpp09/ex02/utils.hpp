/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:12:57 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/28 00:04:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>

# ifndef DEBUG
    #define DEBUG false
# endif

# define GREY	"\033[38;5;244m"
# define ORANGE	"\033[0;38;5;166m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

namespace utils {

unsigned int getNumber(std::string const str_nb);

template<typename Iter>
void checkIfIsSorted(Iter first, Iter last);

template<typename Iter>
void checkIfIsSorted(Iter first, Iter last, int element_size);

void printDetails(int iteration, int size, int element_size, int pair_size);

template<typename Iter>
void printContainer(Iter first, Iter last);

template<typename Iter>
void printContainer(
	bool print, Iter first, Iter last, std::string const& description
);

template<typename Iter>
void printAfterInsert(
	bool print, Iter p_first, Iter p_last, Iter c_first, Iter c_last, std::string const& description
);

template<typename Iter>
void printAfterRecursion(
	int iteration, Iter first, Iter last, int element_size
);

}

# include "utils.tpp"

#endif
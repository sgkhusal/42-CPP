/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:15 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/19 18:32:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <sstream>
# include <ctime>
# include <exception>
# include <vector>

# ifndef DEBUG
    #define DEBUG false
# endif

# define GREY	"\033[38;5;244m"
# define ORANGE	"\033[0;38;5;166m"
# define RESET	"\033[0m"

class PmergeMe {
public:
	PmergeMe(char *input[]);
	PmergeMe(PmergeMe const& p);
	~PmergeMe(void);
	PmergeMe const& operator=(PmergeMe const& p);

	std::vector<int> getVSequence(void) const;
	void sortV(void);

private:
	PmergeMe(void);

	std::vector<int> _vSequence;

	std::pair<bool, int> _odd;

	void _fillVector(char *input[]);
	void _printVector(void) const;

	void _checkInput(char *input[]);
	unsigned int _getNumber(std::string const str_nb);

	class InvalidInput: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class NumberToHigh: public std::exception {
		public:
			virtual const char* what() const throw();
	};

};

#endif
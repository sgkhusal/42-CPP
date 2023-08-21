/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:15 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/21 12:41:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <sstream>
# include <ctime>
# include <exception>
# include <vector>
# include <cmath>

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
	void run(void);

	typedef std::vector<int>::iterator iterator;

private:
	PmergeMe(void);

	std::vector<int> _vSequence;

	void _mergeInsertion(iterator first, iterator last, int iteration);
	std::vector<int> _jacobsthalSequence(size_t size);
	// 0 1 1 3 5 11 21
	// a partir do terceiro número, é a soma do anterior com 2 * o penúltimo
	std::vector<int> _getInsertionOrder(size_t size);

	void _sortV(void);
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
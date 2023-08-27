/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:15 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/27 13:11:11 by sguilher         ###   ########.fr       */
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
# define GREEN	"\033[1;32m"
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
	typedef std::vector<int>::const_iterator const_iterator;

private:
	PmergeMe(void);

	std::vector<int> _vSequence;

	void _mergeInsertion(iterator first, iterator last, int iteration);
	std::vector<int> _jacobsthalSequence(const int& size);
	std::vector<int> _getInsertionOrder(const int& size);
	iterator _binarySearch(
		iterator first, iterator last, int value, int element_size
	);

	void _sortV(void);
	void _fillVector(char *input[]);
	void _printVector(const_iterator begin, const_iterator end) const;
	bool _isSorted(const_iterator begin, const_iterator end) const;

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
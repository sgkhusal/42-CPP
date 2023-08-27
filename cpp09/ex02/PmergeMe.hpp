/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:15 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/27 18:11:23 by sguilher         ###   ########.fr       */
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

# include "utils.hpp"

class PmergeMe {
public:
	typedef std::vector<int> vector;
	typedef vector::iterator iterator;
	typedef vector::const_iterator const_iterator;
	typedef std::pair<bool, vector > odd_t;

	PmergeMe(char *input[]);
	PmergeMe(PmergeMe const& p);
	~PmergeMe(void);
	PmergeMe const& operator=(PmergeMe const& p);

	vector	getVSequence(void) const;
	void	run(void);

private:
	PmergeMe(void);

	vector	_vSequence;

	void		_sortV(void);
	void		_mergeInsertion(iterator first, iterator last, int iteration);

	void		_sortSize2(iterator first, int element_size);
	odd_t		_removeLastElement(iterator last, int element_size);
	void		_sortPairs(iterator first, iterator last, int e_size, int p_size);
	vector		_createPend(
		iterator first, int pend_size, int half_size, int element_size, odd_t odd
	);
	void		_removePendElements(iterator first, int half_size, int element_size);
	void		_insertFirstElement(iterator first, iterator last);
	vector		_jacobsthalSequence(const int& size);
	vector		_getInsertionOrder(const int& size);
	vector		_createPairsReference(int size);
	iterator	_binarySearch(
		iterator first, iterator last, int value, int element_size
	);

	void	_fillVector(char *input[]);
	void	_printVector(const_iterator begin, const_iterator end) const;
	void	_printAfterRecursion(
		int iteration, iterator first, iterator last, int element_size
	);
	bool	_isSorted(const_iterator begin, const_iterator end) const;
	bool	_isSorted(
		const_iterator begin, const_iterator end, int element_size
	) const;

	void	_checkInput(char *input[]);
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
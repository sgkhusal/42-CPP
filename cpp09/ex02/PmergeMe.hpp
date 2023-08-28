/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:15 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/28 01:44:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
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
	void		_insertElements(
		iterator first, int size, int element_size, vector order, vector pend
	);
	iterator _findPosition(
		iterator first, iterator order_it, int element_size, vector pend, vector& pairs_reference
	);
	iterator	_binarySearch(
		iterator first, iterator last, int value, int element_size
	);

	void	_fillVector(char *input[]);
	void	_checkInput(char *input[]);

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
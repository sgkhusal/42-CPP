/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:15 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/28 23:13:23 by sguilher         ###   ########.fr       */
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

	vector	getSequence(void) const;
	void	sort(void);

private:
	PmergeMe(void);

	vector		_sequence;
	void		_fillSequence(char *input[]);

	void		_mergeInsertion(iterator first, iterator last, int iteration);

	odd_t		_removeLastElement(iterator last, int element_size);
	vector		_createPend(
		iterator first, int pend_size, int half_size, int element_size, odd_t odd
	);
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

	template<typename Iter>
	void		_sortSize2(Iter first, int element_size);

	template<typename Iter>
	void		_sortPairs(Iter first, Iter last, int e_size, int p_size);

	template<typename Iter>
	void		_removePendElements(Iter first, int half_size, int element_size);

	template<typename Iter>
	Iter		_binarySearch(
		Iter first, Iter last, int value, int element_size
	);
};

# include "PmergeMe.tpp"

#endif
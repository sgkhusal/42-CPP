/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:15 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/02 01:30:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <ctime>
# include <exception>
# include <cmath>
# include <vector>
# include <list>
# include <typeinfo>
# include <cstring>

# include "utils.hpp"

class PmergeMe {
public:
	typedef std::vector<int> vector;
	typedef vector::iterator v_iterator;
	typedef vector::const_iterator v_const_iterator;  // não está sendo usado...
	typedef std::pair<bool, vector > v_odd_t;

	typedef std::list<int> list;
	typedef list::iterator l_iterator;
	typedef list::const_iterator l_const_iterator;  // não está sendo usado...
	typedef std::pair<bool, list > l_odd_t;

	PmergeMe(char *input[]);
	PmergeMe(PmergeMe const& p);
	~PmergeMe(void);
	PmergeMe const& operator=(PmergeMe const& p);

	vector	getVector(void) const;
	list	getList(void) const;
	size_t	size(void) const;
	void	sort(void);

private:
	PmergeMe(void);

	size_t	_size;
	vector	_v;
	list	_l;
	clock_t	_vt;
	clock_t	_lt;
	void	_fillVector(char *input[]);
	void	_fillList(char *input[]);

	void	_vMergeInsertion(v_iterator first, v_iterator last, int iteration);
	void	_lMergeInsertion(l_iterator first, l_iterator last, int iteration);

	v_odd_t	_vRemoveLastElement(v_iterator last, int element_size);
	l_odd_t	_lRemoveLastElement(l_iterator last, int element_size);
	void _vSortPairs(v_iterator first, v_iterator last, int e_size, int p_size);
	void _lSortPairs(l_iterator first, int e_size, int p_size, int size);
	vector	_vCreatePend(
		v_iterator first, int pend_size, int half_size, int element_size, v_odd_t odd
	);
	list	_lCreatePend(
		l_iterator first, int pend_size, int half_size, int element_size, l_odd_t odd
	);
	void	_vRemovePendElements(v_iterator first, int half_size, int element_size);
	void	_lRemovePendElements(l_iterator first, int half_size, int element_size);
	void	_vInsertFirstElement(v_iterator first, v_iterator last);
	void	_lInsertFirstElement(l_iterator first, int element_size);
	// vector	_vCreatePairsReference(int size);
	void	_vInsertElements(
		v_iterator first, int size, int element_size, vector order, vector pend
	);
	void	_lInsertElements(
		l_iterator first, int size, int element_size, list order, list pend
	);
	v_iterator _vFindPosition(
		v_iterator first, v_iterator order_it, int element_size, vector pend, vector& pairs_reference
	);
	l_iterator _lFindPosition(
		l_iterator first, l_iterator order_it, int element_size, list pend, list& pairs_reference
	);

	template<typename Iter>
	void	_sortSize2(Iter first, int element_size);

	template<typename Iter>
	void	_swapPair(Iter ita, Iter itb, int element_size);

	template<typename Container>
	Container	_createPairsReference(const int& size);

	template<typename Container, typename Iter>
	Container	_getInsertionOrder(const int& size);

	template<typename Container>
	Container	_jacobsthalSequence(const int& size);

	template<typename Iter>
	Iter	_binarySearch(
		Iter first, Iter last, int value, int element_size
	);
	template<class ForwardIt>
	ForwardIt _lower_bound(ForwardIt first, ForwardIt last, const int& value, const int& element_size);
};

# include "PmergeMe.tpp"

#endif
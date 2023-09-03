/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:15 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/03 00:16:00 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <ctime> // clock
# include <exception>
# include <cmath> // pow
# include <vector>
# include <list>
# include <cstdlib> // rand

# include "utils.hpp"

class PmergeMe {
public:
	/* typedefs */
	typedef std::vector<int> vector;
	typedef vector::iterator v_iterator;
	typedef std::pair<bool, vector > v_odd_t;

	typedef std::list<int> list;
	typedef list::iterator l_iterator;
	typedef std::pair<bool, list > l_odd_t;

	/* Canonical form */
	PmergeMe(void);
	PmergeMe(PmergeMe const& p);
	~PmergeMe(void);
	PmergeMe const& operator=(PmergeMe const& p);

	PmergeMe(int size, char *input[]);
	void	sort(void);

	/* getters */
	vector	getVector(void) const;
	list	getList(void) const;
	size_t	size(void) const;
	clock_t	getVectorProcessTime(void) const;
	clock_t	getListProcessTime(void) const;

private:
	size_t	_size;
	vector	_v;
	list	_l;
	clock_t	_vt;
	clock_t	_lt;
	void	_fillVector(char *input[]);
	void	_fillList(char *input[]);
	void	_printInitial(void) const;
	void	_printResult(void) const;

	void	_vMergeInsertion(v_iterator first, v_iterator last, int iteration);
	void	_lMergeInsertion(l_iterator first, l_iterator last, int iteration);

	v_odd_t	_vRemoveLastElement(v_iterator last, int element_size);
	l_odd_t	_lRemoveLastElement(l_iterator last, int element_size);
	void _vSortPairs(v_iterator first, v_iterator last, int e_size, int p_size);
	void _lSortPairs(l_iterator first, l_iterator last, int e_size, int p_size);
	void _vRemovePendElements(v_iterator first, int half_size, int element_size);
	void _lRemovePendElements(l_iterator first, int half_size, int element_size);
	void _vInsertFirstElement(v_iterator first, v_iterator last);
	void _lInsertFirstElement(l_iterator first, int element_size);
	void _vInsertElements(
		v_iterator first, int size, int element_size, vector order, vector pend
	);
	void _lInsertElements(
		l_iterator first, int element_size, list order, list pend
	);
	vector 					_vCreatePairsReference(const int& size);
	std::list<l_iterator>	_lCreatePairsReference(const int& e_size);
	v_iterator _vFindPosition(
		v_iterator first,
		v_iterator order_it,
		int element_size,
		vector pend,
		vector& pairs_reference
	);
	l_iterator _lFindPosition(
		l_iterator first,
		l_iterator order_it,
		int element_size,
		list pend,
		std::list<l_iterator>& pairs_reference
	);

	/* TEMPLATES */

	template<typename Iter>
	void	_sortSize2(Iter first, int element_size);

	template<typename Iter>
	void	_swapPair(Iter ita, Iter itb, int element_size);

	template<typename Container, typename Iter, typename Odd>
	void	_createPend(
		Container &pend, Iter first, int half_size, int element_size, Odd odd
	);

	template<typename Container>
	void	_createPairsReference(const int& size, Container& pr);

	template<typename Container, typename Iter>
	void	_getInsertionOrder(const int& size, Container& order);

	template<typename Container>
	Container	_jacobsthalSequence(const int& size);

	template<typename Iter>
	Iter	_binarySearch(
		Iter first, Iter last, const int& value, const int& element_size
	);
};

# include "PmergeMe.tpp"

#endif
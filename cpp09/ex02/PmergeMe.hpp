/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:15 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/30 22:02:28 by sguilher         ###   ########.fr       */
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

	size_t		_size;
	vector		_v;
	list		_l;
	clock_t		_vt;
	clock_t		_lt;
	void		_fillVector(char *input[]);
	void		_fillList(char *input[]);

	void		_mergeInsertion(v_iterator first, v_iterator last, int iteration);

	v_odd_t		_removeLastElement(v_iterator last, int element_size);
	vector		_createPend(
		v_iterator first, int pend_size, int half_size, int element_size, v_odd_t odd
	);
	void		_insertFirstElement(v_iterator first, v_iterator last);
	vector		_jacobsthalSequence(const int& size);
	vector		_getInsertionOrder(const int& size);
	vector		_createPairsReference(int size);
	void		_insertElements(
		v_iterator first, int size, int element_size, vector order, vector pend
	);
	v_iterator _findPosition(
		v_iterator first, v_iterator order_it, int element_size, vector pend, vector& pairs_reference
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
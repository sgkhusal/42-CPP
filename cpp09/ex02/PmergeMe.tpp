/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:09:06 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/02 23:30:36 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_TPP
# define PMERGE_ME_TPP

# include "PmergeMe.hpp"

template<typename Iter>
void PmergeMe::_sortSize2(Iter first, int element_size) {
	Iter ita = first, itb = first;

	std::advance(itb, element_size);
	if (*ita > *(itb))
		_swapPair(ita, itb, element_size);
}

template<typename Iter>
void PmergeMe::_swapPair(Iter ita, Iter itb, int element_size) {
	for (int i = 0; i < element_size; i++) {
		std::swap(*ita++, *itb++);
	}
}

template<typename Container, typename Iter, typename Odd>
void PmergeMe::_createPend(
	Container &pend, Iter first, int half_size, int element_size, Odd odd
) {
	Iter it;

	it = first;
	for (int i = 1; i <= half_size; i++) {
		std::advance(it, element_size);
		for (int j = 0; j < element_size; j++) {
			pend.push_back(*it);
			it++;
		}
	}
	if (odd.first && element_size == 1)
		pend.push_back(*(odd.second.begin()));
	else if (odd.first)
		pend.insert(pend.end(), odd.second.begin(), odd.second.end());
}

template<typename Container>
Container PmergeMe::_jacobsthalSequence(const int& size) {
	Container jacob(1, 0);
	int last = 1, last_but_one = 0, tmp = 0;

	jacob.push_back(1);
	while (tmp < size) {
		tmp = last + 2 * last_but_one;
		jacob.push_back(tmp);
		last_but_one = last;
		last = tmp;
	}
	utils::printContainer(
		DEBUG, jacob.begin(), jacob.end(), "Jacobsthal sequence: "
	);
	return jacob;
}

template<typename Container, typename Iter>
void PmergeMe::_getInsertionOrder(const int& size, Container& order) {
	Container jacob;
	int j, last = 1;
	Iter it;

	order.push_back(1);
	if (size < 3) {
		if (size == 2)
			order.push_back(2);
		utils::printContainer(
			DEBUG, order.begin(), order.end(), "Insertion order: "
		);
		return;
	}
	jacob = _jacobsthalSequence<Container>(size);
	it = jacob.begin();
	std::advance(it, 3);
	for (; it != jacob.end(); it++) {
		for (j = *it; j > last; j--) {
			if (j <= size)
				order.push_back(j);
		}
		last = *it;
	}
	utils::printContainer(
		DEBUG, order.begin(), order.end(), "Insertion order: "
	);
}

template<typename Container>
void PmergeMe::_createPairsReference(const int& size, Container& pr) {
	int half_size = size / 2;

	pr.push_back(1);
	for (int i = 1; i <= half_size; i++)
		pr.push_back(i);
	utils::printContainer(
		DEBUG, pr.begin(), pr.end(), "Pairs reference: "
	);
}

template<typename Iter>
Iter PmergeMe::_binarySearch(
	Iter first, Iter last, const int& value, const int& element_size
) {
	size_t	size, middle;
	Iter pos;

	size = std::distance(first, last) / element_size;
	if (size == 1) {
		if (value < *first)
			return first;
		if (value < *last)
			return last;
		pos = last;
		std::advance(pos, element_size);
		return pos;
	}
	middle = size / 2 * element_size;
	pos = first;
	std::advance(pos, middle);
	if (value < *pos)
		return _binarySearch(first, pos, value, element_size);
	else
		return _binarySearch(pos, last, value, element_size);
}

#endif
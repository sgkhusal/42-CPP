/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:09:06 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/02 01:29:05 by sguilher         ###   ########.fr       */
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
		// std::cout << "2. ita e itb: " << *a << " " << *b << std::endl;
		std::swap(*ita++, *itb++);
	}
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
Container PmergeMe::_getInsertionOrder(const int& size) {
	Container jacob, order(1, 1);
	int j, last = 1;
	Iter it;
	vector check;

	if (size < 3) {
		if (size == 2)
			order.push_back(2);
		return order;
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
	return order;
}

template<typename Container>
Container PmergeMe::_createPairsReference(const int& size) {
	Container pairs_reference;
	int half_size = size / 2;

	// pairs_reference.reserve(size);
	pairs_reference.push_back(1);
	for (int i = 1; i <= half_size; i++)
		pairs_reference.push_back(i);
	utils::printContainer(
		DEBUG, pairs_reference.begin(), pairs_reference.end(), "Pairs reference: "
	);
	return pairs_reference;
}

template<typename Iter>
Iter PmergeMe::_binarySearch(
	Iter first, Iter last, int value, int element_size
) {
	size_t	size;
	Iter middle;

	size = std::distance(first, last);
	if (size / element_size == 1) {
		if (value < *first)
			return first;
		if (value < *last)
			return last;
		return last + element_size;
	}
	middle = first + (size / element_size / 2 * element_size);
	if (value < *middle)
		return _binarySearch(first, middle, value, element_size);
	else
		return _binarySearch(middle, last, value, element_size);
}

template<class ForwardIt>
ForwardIt _lower_bound(ForwardIt first, ForwardIt last, const int& value, const int& element_size)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type size, middle;

	size = std::distance(first, last) / element_size;
    while (size > 0)
    {
        it = first;
        middle = size / 2 * element_size;
        std::advance(it, middle);

        if (*it < value)
        {
            first = ++it;
            size -= middle / element_size + 1;
        }
        else
            size = middle / element_size;
    }

    return first;
}

#endif
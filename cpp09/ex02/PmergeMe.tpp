/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:09:06 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/01 23:13:38 by sguilher         ###   ########.fr       */
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

// template<class ForwardIt>
// ForwardIt lower_bound(ForwardIt first, ForwardIt last, const int& value, const int& element_size)
// {
//     ForwardIt it;
//     typename std::iterator_traits<ForwardIt>::difference_type size, middle;

// 	size = std::distance(first, last) / element_size;
//     while (size > 0)
//     {
//         it = first;
//         middle = size / 2 * element_size;
//         std::advance(it, middle);

//         if (*it < value)
//         {
//             first = ++it;
//             size -= middle + 1;
//         }
//         else
//             size = middle;
//     }

//     return first;
// }

#endif
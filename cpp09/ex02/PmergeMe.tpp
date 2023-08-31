/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:09:06 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/30 21:55:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_TPP
# define PMERGE_ME_TPP

# include "PmergeMe.hpp"

// template<typename Container>
// void PmergeMe::sort(Container& c) {
// 	clock_t t;

// 	t = std::clock();
// 	utils::printContainer(
// 		true, c.begin(), c.end(), "Before:	"
// 	);
// 	_mergeInsertion(c.begin(), c.end(), 0);
// 	utils::checkIfIsSorted(c.begin(), c.end());
// 	t = std::clock() - t;
// 	std::cout << GREY << "vector: sorting time: "
// 			<< ((float)t)/CLOCKS_PER_SEC * 1000 << " micro seconds"
// 			<< RESET << std::endl;
// }

template<typename Iter>
void PmergeMe::_sortSize2(Iter first, int element_size) {
	Iter it = first;

	if (*it > *(it + element_size)) {
		for (int i = 0; i < element_size; i++)
			std::swap(*(it + i), *(it + element_size + i));
	}
}

template<typename Iter>
void PmergeMe::_sortPairs(Iter first, Iter last, int e_size, int p_size) {
	for (Iter it = first; it != last; it += p_size) {
		if (*it < *(it + e_size)) {
			for (int i = 0; i < e_size; i++)
				std::swap(*(it + i), *(it + e_size + i));
		}
	}
	if (DEBUG) {
		std::cout << "Pairs ordered: | ";
		for (Iter it = first; it != last; it += p_size) {
			for (int i = 0; i < p_size; i++) {
				std::cout << *(it + i) << " ";
			}
			std::cout << "| ";
		}
		std::cout << RESET << std::endl;
	}
}

template<typename Iter>
void PmergeMe::_removePendElements(
	Iter first, int half_size, int element_size
) {
	Iter it;

	for (int i = half_size; i > 0; i--) {
		it = first + (i * 2 - 1) * element_size;
		_v.erase(it, it + element_size);
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
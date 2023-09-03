/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:57:44 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/02 21:38:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

namespace utils {

template<typename Iter>
bool isSorted(Iter first, Iter last) {
	Iter ita = first, itb;

	for (itb = ++first; itb != last; itb++) {
		if (*ita > *itb) {
			return false;
		}
		++ita;
	}
	return true;
}

template<typename Iter>
void checkIfIsSorted(Iter first, Iter last, std::string type) {
	Iter ita = first, itb;
	bool sorted = true;
	int count = 0;

	for (itb = ++first; itb != last; itb++) {
		if (*ita > *itb) {
			std::cout << ORANGE << *ita << " and " << *itb << std::endl;
			sorted = false;
			++count;
		}
		++ita;
	}
	if (!sorted)
		std::cout << ORANGE << "KO: " << type << " is not sorted: " << count
				<< RESET << std::endl;
	else if (DEBUG)
		std::cout << GREEN << "OK: " << type << " is sorted"
				<< RESET << std::endl;
}

template<typename Iter>
void checkIfIsSorted(Iter first, Iter last, int element_size, std::string type) {
	Iter ita = first, itb = first;
	bool sorted = true;
	int count = 0;

	std::advance(itb, element_size);
	while (itb != last) {
		if (*ita > *itb) {
			std::cout << ORANGE << *ita << " and " << *itb << std::endl;
			sorted = false;
			count++;
		}
		ita = itb;
		std::advance(itb, element_size);
	}
	if (!sorted) {
		std::cout << ORANGE << "KO: " << type << " is not sorted: " << count
				<< RESET << std::endl;
		exit(1);
	}
	else if (DEBUG)
		std::cout << GREEN << "OK: " << type << " is sorted"
				<< RESET << std::endl;
}

template<typename Iter>
void checkUniqueNumbers(Iter first, Iter last) {
	Iter it1, it2;

	for (it1 = first; it1 != last; it1++) {
		it2 = it1;
		it2++;
		for (; it2 != last; it2++) {
			if (*it1 == *it2) {
				throw std::runtime_error(
					"Error: repeated numbers"
				);
			}
		}
	}
}

template<typename Iter>
void printContainer(Iter first, Iter last) {
	std::for_each(first, last, &printElement);
}

template<typename Iter>
void printContainer(
	bool print, Iter first, Iter last, std::string const& description
) {
	if (print) {
		std::cout << GREY << description;
		printContainer(first, last);
		std::cout << RESET << std::endl;
	}
}

template<typename Iter>
void printContainer(Iter first, Iter last, int e_size) {
	int p_size = 2 * e_size, p = 0, e = 0;
	bool first_element = true;

	for (Iter it = first; it != last; it++) {
		printElement(*it);
		e++;
		p++;
		if (e == e_size && first_element) {
			std::cout << ", ";
			first_element = false;
			e = 0;
		}
		if ( p == p_size) {
			std::cout << "| ";
			first_element = true;
			p = 0;
			e = 0;
		}
	}
}

template<typename Iter>
void printAfterRecursion(
	int iteration, Iter first, Iter last, int element_size
) {
	if (DEBUG) {
		std::cout << GREY << "\n------------------------------------------\n"
			<< "iteration " << iteration
			<< ":\nPairs after merge insertion with bigger numbers: | ";
		utils::printContainer(first, last, element_size);
		std::cout << RESET << std::endl;
	}
}

template<typename Iter>
void printAfterInsert(
	Iter p_first, Iter p_last, Iter c_first, Iter c_last, std::string const& container
) {
	if (DEBUG) {
		std::cout << GREY << "Pairs reference: ";
		printContainer(p_first, p_last);
		std::cout << GREY << container;
		printContainer(c_first, c_last);
		std::cout << RESET << std::endl;
	}
}

}
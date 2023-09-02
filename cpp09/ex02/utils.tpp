/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:57:44 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/01 22:57:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

namespace utils {

template<typename Container>
void fillContainer(Container& c, char* input[]) {
	clock_t t;
	int i = 0;

	// testar usar reserve para vector
	t = std::clock();
	while (input[i]) {
		c.push_back(getNumber(input[i]));
		i++;
	}

	t = std::clock() - t;
	if (DEBUG)
		std::cout << GREY << "vector: input insertion time: "
				<< ((float)t)/CLOCKS_PER_SEC << " seconds"
				<< RESET << std::endl;
}

template<typename Iter>
void checkIfIsSorted(Iter first, Iter last) {
	bool sorted = true;
	int count = 0;

	for (Iter it = first + 1; it != last; it++) {
		if (*(it - 1) > *it) {
			std::cout << ORANGE << *(it - 1) << " and " << *it << std::endl;
			sorted = false;
			count++;
		}
	}
	if (!sorted)
		std::cout << "KO: vector is not sorted: " << count << RESET << std::endl;
	else if (DEBUG)
		std::cout << GREEN << "OK: vector is sorted" << RESET << std::endl;
}

template<typename Iter>
void checkIfIsSorted(Iter first, Iter last, int element_size) {
	bool sorted = true;
	int count = 0;

	for (Iter it = first + element_size; it != last; it += element_size) {
		if (*(it - element_size) > *it) {
			std::cout << ORANGE << *(it - element_size) << " and " << *it << std::endl;
			sorted = false;
			count++;
		}
	}
	if (!sorted) {
		std::cout << "KO: vector is not sorted: " << count << RESET << std::endl;
		exit(1);
	}
	else if (DEBUG)
		std::cout << GREEN << "OK: vector is sorted" << RESET << std::endl;
}

template<typename Iter>
void printContainer(Iter first, Iter last) {
	std::for_each(first, last, &printElement);
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
void printAfterInsert(
	bool print, Iter p_first, Iter p_last, Iter c_first, Iter c_last, std::string const& description
) {
	if (print) {
		std::cout << GREY << "Pairs reference: ";
		printContainer(p_first, p_last);
		std::cout << GREY << description;
		printContainer(c_first, c_last);
		std::cout << RESET << std::endl;
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
		for (Iter it = first; it != last; it += element_size) {
			for (int i = 0; i < element_size; i++) {
				std::cout << *(it + i) << " ";
			}
			std::cout << "| ";
		}
		std::cout << RESET << std::endl;
	}
}

}
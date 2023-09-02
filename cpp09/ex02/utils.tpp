/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:57:44 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/02 14:15:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

namespace utils {

template<typename Container> /////////////////////////////
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
		std::cout << "KO: " << type << " is not sorted: " << count
				<< RESET << std::endl;
	else //if (DEBUG)
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
		std::cout << "KO: " << type << " is not sorted: " << count
				<< RESET << std::endl;
		exit(1);
	}
	else //if (DEBUG)
		std::cout << GREEN << "OK: " << type << " is sorted"
				<< RESET << std::endl;
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
		utils::printContainer(first, last, element_size);
		std::cout << RESET << std::endl;
	}
}

}
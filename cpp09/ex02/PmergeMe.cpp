/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/21 12:07:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { }

PmergeMe::PmergeMe(char *input[]) {
	_checkInput(input);
	_fillVector(input);
}

PmergeMe::~PmergeMe(void) { }

PmergeMe::PmergeMe(PmergeMe const& p) {
	*this = p;
}

PmergeMe const& PmergeMe::operator=(PmergeMe const& p) {
	if (this != &p) {
		this->_vSequence = p.getVSequence();
	}
	return *this;
}

void PmergeMe::run(void) {
	std::cout << "Before:	";
	_printVector();
	std::cout << std::endl;
	_sortV();
}

void PmergeMe::_sortV(void) {
	clock_t t;

	t = std::clock();
	_mergeInsertion(_vSequence.begin(), _vSequence.end(), 0);
	t = std::clock() - t;
	if (DEBUG)
		std::cout << GREY << "vector: sorting time: "
				<< ((float)t)/CLOCKS_PER_SEC << " seconds"
				<< RESET << std::endl;
}

void PmergeMe::_mergeInsertion(iterator first, iterator last, int iteration) {
	size_t	size;
	int		pair_size;
	int		element_size;
	std::pair<bool, iterator> odd;

	// ver resultado do algoritmo com números pequenos: 2, 3, 4, 5...
	element_size = std::pow(2, iteration);
	size = std::distance(first, last) / element_size;
	if (DEBUG)
		std::cout << GREY << "\n------------------------------------------\n"
			<< "iteration " << iteration
			<<  ":\n- element size: " << element_size
			<<  "\n- size: " << size << RESET << std::endl;
	if (size <= 1)
		return ;

	// If size is odd, leave one element out
	if (size % 2 == 1) {
		last = last - element_size;
		odd = std::pair<bool, iterator>(true, last);
		if (DEBUG) {
			std::cout << GREY << "odd size - remove element: ";
			for (int i = 0; i < element_size; i++) {
				std::cout << *(odd.second + i) << " ";
			}
			std::cout << "\nnow last references to: " << *last << std::endl;
		}
	}
	else
		odd = std::pair<bool, iterator>(false, last);

	// (i) Make pairwise comparisons of [size/2] disjoint pairs of elements.
	// sort them in descending order
	pair_size = std::pow(2, iteration + 1);
	if (DEBUG)
		std::cout << GREY <<  "- pair size: " << pair_size << std::endl;
	for (iterator it = first; it != last; it += pair_size) {
		if (*it < *(it + element_size)) {
			for (int i = 0; i < element_size; i++)
				std::swap(*(it + i), *(it + element_size + i));
		}
	}
	if (DEBUG) {
		std::cout << "Pairs ordered: | ";
		for (iterator it = first; it != last; it += pair_size) {
			for (int i = 0; i < pair_size; i++) {
				std::cout << *(it + i) << " ";
			}
			std::cout << "| ";
		}
		std::cout << RESET << std::endl;
	}

	// Sort the [size/2] larger numbers, found in step (i), by merge insertion
	// recursion: sort pairs vector in ascending order
	_mergeInsertion(first, last, iteration + 1);

	// separar em dois vetores
	// passar o primeiro para o ordenado
	// inserir os números usando os números de Jacobsthal - entender essa lógica
	// dá pra saber que eles são menores do que os mesmos índices correspondentes...
	// inserir último número (se for ímpar) com binary search
}

void PmergeMe::_printVector(void) const {
	std::vector<int>::const_iterator it, end = _vSequence.end();

	for (it = _vSequence.begin(); it != end; it++)
		std::cout << *it << " ";
}

void PmergeMe::_fillVector(char *input[]) {
	clock_t t;
	int i = 0;

	// testar usar reserve
	t = std::clock();
	while (input[i]) {
		_vSequence.push_back(_getNumber(input[i]));
		i++;
	}

	t = std::clock() - t;
	if (DEBUG)
		std::cout << GREY << "vector: input insertion time: "
				<< ((float)t)/CLOCKS_PER_SEC << " seconds"
				<< RESET << std::endl;
}

unsigned int PmergeMe::_getNumber(std::string const str_nb) {
	std::stringstream	ss;
	unsigned int		nb;

	ss << str_nb;
	ss >> nb;

	return nb;
}

std::vector<int> PmergeMe::getVSequence(void) const {
	return this->_vSequence;
}

void PmergeMe::_checkInput(char *input[]) {
	int i = 0, j = 0;
	unsigned int nb;

	while (input[i]) {
		j = 0;
		while(input[i][j]) {
			if (!std::isdigit(input[i][j])) {
				std::cout << input[i] << std::endl;
				throw InvalidInput();
			}
			j++;
		}
		nb = _getNumber(input[i]);
		if (nb > __INT_MAX__) {
			throw NumberToHigh();
		}
		i++;
	}
	// o algoritmo funcionaria com números negativos?
	// Your program must be able to use a positive integer sequence as argument
}

const char *PmergeMe::InvalidInput::what() const throw() {
	return "Error: invalid input: only accepts positive integers";
}

const char *PmergeMe::NumberToHigh::what() const throw() {
	return "Error: number too high";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/27 01:29:29 by sguilher         ###   ########.fr       */
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
	_printVector(_vSequence.begin(), _vSequence.end());
	std::cout << std::endl;
	_sortV();
	// std::cout << "After:	";
	// _printVector(_vSequence.begin(), _vSequence.end());
	// std::cout << std::endl;
}

void PmergeMe::_sortV(void) {
	clock_t t;

	t = std::clock();
	_mergeInsertion(_vSequence.begin(), _vSequence.end(), 0);
	t = std::clock() - t;
	std::cout << GREY << "vector: sorting time: "
			<< ((float)t)/CLOCKS_PER_SEC * 1000 << " micro seconds"
			<< RESET << std::endl;
}

void PmergeMe::_mergeInsertion(iterator first, iterator last, int iteration) {
	size_t	size, distance;
	int		pair_size, element_size, i;
	std::pair<bool, iterator> odd;

	// ver resultado do algoritmo com números pequenos: 2, 3, 4, 5...
	element_size = std::pow(2, iteration);
	distance = std::distance(first, last);
	size = distance / element_size;
	pair_size = std::pow(2, iteration + 1);
	if (DEBUG)
		std::cout << GREY << "\n------------------------------------------\n"
			<< "iteration " << iteration
			<<  ":\n- element size: " << element_size
			<<  "\n- size: " << size << RESET << std::endl;
	if (size <= 1)
		return ;
	if (DEBUG)
		std::cout << GREY <<  "- pair size: " << pair_size << std::endl;
	if (size == 2) {
		for (iterator it = first; it != last; it += pair_size) {
		if (*it > *(it + element_size)) {
			for (int i = 0; i < element_size; i++)
				std::swap(*(it + i), *(it + element_size + i));
			}
		}
		return ;
	}

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
	if (DEBUG) {
		std::cout << GREY << "\n------------------------------------------\n"
			<< "iteration " << iteration
			<< ":\nPairs after merge insertion with bigger numbers: | ";
		for (iterator it = first; it != last; it += pair_size) {
			for (int i = 0; i < pair_size; i++) {
				std::cout << *(it + i) << " ";
			}
			std::cout << "| ";
		}
		std::cout << RESET << std::endl;
	}

	// separar em dois vetores
	int new_size = size / 2;
	// std::cout << "new_size: " << new_size << std::endl;
	int pend_size = new_size + (odd.first ? 1 : 0);
	// std::cout << "pend_size: " << pend_size << std::endl;

	std::vector<int> pend;
	iterator it;
	// std::cout << "first: " << *(first) << std::endl;
	pend.reserve(pend_size * element_size);
	// std::cout << pend.capacity() << std::endl;
	// std::cout << pend.size() << std::endl;
	for (i = 1; i <= new_size; i++) {
		it = first + (i * 2 - 1) * element_size;
		for (int j = 0; j < element_size; j++) {
			// std::cout << *(it + j) << std::endl;
			pend.push_back(*(it + j));
		}
	}
	if (odd.first) {
		for (int j = 0; j < element_size; j++) {
			// std::cout << *(odd.second + j) << std::endl;
			pend.push_back(*(odd.second + j));
		}
		_vSequence.erase(odd.second, odd.second + element_size);
	}
	if (DEBUG) {
		std::cout << GREY << "Pend: ";
		_printVector(pend.begin(), pend.end());
		std::cout << RESET << std::endl;
	}

	// remove elements from _vSequence
	// it = first + new_size * element_size;
	// _vSequence.erase(it, it + pend_size * element_size);
	for (i = new_size; i > 0; i--) {
		it = first + (i * 2 - 1) * element_size;
		// std::cout << "remove from _vSequence: " << *it << std::endl;
		_vSequence.erase(it, it + element_size);
	}

	// std::cout << pend.size() << std::endl;
	if (DEBUG) {
		std::cout << GREY << "Pend: ";
		_printVector(pend.begin(), pend.end());
		std::cout << GREY << "_vSequence: ";
		_printVector(_vSequence.begin(), _vSequence.end());
		std::cout << RESET << std::endl;
	}

	// obter a ordem de inserção usando os números de Jacobsthal
	std::vector<int> order = _getInsertionOrder(pend_size); ///////
	if (DEBUG) {
		std::cout << GREY << "Insertion sequence: ";
		_printVector(order.begin(), order.end());
		std::cout << RESET << std::endl;
	}

	// vetor que simula o link entre os pares
	std::vector<int> pairs_reference;
	pairs_reference.reserve(size);
	pairs_reference.push_back(1);
	for (i = 1; i <= new_size; i++) {
		pairs_reference.push_back(i);
	}
	if (DEBUG) {
		std::cout << GREY << "Pairs reference: ";
		_printVector(pairs_reference.begin(), pairs_reference.end());
		std::cout << RESET << std::endl;
	}

	// colocar o primeiro na primeira posição
	_vSequence.insert(first, pend.begin(), pend.begin() + element_size);
	if (DEBUG) {
		std::cout << GREY << "_vSequence: ";
		_printVector(_vSequence.begin(), _vSequence.end());
		std::cout << RESET << std::endl;
	}

	int pos;
	iterator pairs_reference_it, p;
	for (iterator order_it = order.begin() + 1; order_it != order.end(); order_it++) {
		pairs_reference_it = pairs_reference.begin();
		pos = 0;
		// std::cout << "*order_it: " << *order_it << std::endl;
		// std::cout << "*pairs_reference_it: " << *pairs_reference_it << std::endl;
		// std::cout << "pos: " << pos << std::endl;

		while (pairs_reference_it != pairs_reference.end() && *pairs_reference_it != *order_it) {
			pairs_reference_it++;
			pos++;
		}
		// std::cout << "*pairs_reference_it: " << *pairs_reference_it << std::endl;
		// std::cout << "pos: " << pos << std::endl;
		// std::cout << "*first: " << *first << std::endl;
		// std::cout << "*(first + (pos - 1) * element_size) " << *(first + (pos - 1) * element_size) << std::endl;
		int value = pend.at((*order_it - 1) * element_size);
		iterator elem_init = pend.begin() + (*order_it - 1) * element_size;
		iterator elem_final = elem_init + element_size;
		// std::cout << "value: " << value << " - " << *elem_init << std::endl;
		if (pairs_reference_it == pairs_reference.end()) {
			// elemento ímpar que sobrou
			p = _binarySearch(
				first,
				first + pairs_reference.size() * element_size,
				value,
				element_size
			);
		}
		else {
			p = _binarySearch(
				first,
				first + (pos - 1) * element_size,
				value,
				element_size
			);
			// std::cout << *(pairs_reference.begin()) << " " << std::distance(first, p) << " " << pairs_reference.size() << std::endl;
			// std::cout << *(pairs_reference.begin() + std::distance(first, p)) << " " << *order_it << std::endl;
			size_t d = std::distance(first, p);
			if (d > pairs_reference.size())
				pairs_reference.insert(pairs_reference.end(), *order_it);
			else
				pairs_reference.insert(pairs_reference.begin() + std::distance(first, p), *order_it);
			// std::cout << *(pairs_reference.begin()) << " " << *order_it << std::endl;
		}
		// std::cout << "*p: " << *p << std::endl;
		_vSequence.insert(p, elem_init, elem_final);
		if (DEBUG) {
			std::cout << GREY << "Pairs reference: ";
			_printVector(pairs_reference.begin(), pairs_reference.end());
			std::cout << GREY << "_vSequence: ";
			_printVector(_vSequence.begin(), _vSequence.end());
			std::cout << RESET << std::endl;
		}
	}
	if (DEBUG) {
		std::cout << GREY << "Pend: ";
		_printVector(pend.begin(), pend.end());
		std::cout << GREY << "_vSequence: ";
		_printVector(_vSequence.begin(), _vSequence.end());
		std::cout << RESET << std::endl;
	}

	// dá pra saber que eles são menores do que os mesmos índices correspondentes...
	// inserir último número (se for ímpar) com binary search
}

PmergeMe::iterator PmergeMe::_binarySearch(
	iterator first, iterator last, int value, int element_size
) {
	size_t	size;
	iterator middle;

	size = std::distance(first, last);
	// std::cout << "Binary Search: " << *first << " and " << *last << " - distance: " << size << std::endl;
	if (size / element_size == 1) {
		if (value < *first)
			return first;
		if (value < *last)
			return last; // cuidado se o last for o final...
		return last + element_size;
	}
	middle = first + (size / element_size / 2 * element_size);
	// std::cout << "middle: " << *middle << std::endl;
	if (value < *middle)
		return _binarySearch(first, middle, value, element_size);
	else
		return _binarySearch(middle, last, value, element_size);
}

std::vector<int> PmergeMe::_getInsertionOrder(const int& size) {
	std::vector<int> jacob, sequence(1, 1);
	int j, last = 1;
	iterator it;

	if (size < 3) {
		if (size == 2)
			sequence.push_back(2);
		return sequence;
	}

	sequence.reserve(size);
	jacob = _jacobsthalSequence(size);
	for (it = jacob.begin() + 3; it != jacob.end(); it++) {
		for (j = *it; j > last; j--) {
			if (j <= size)
				sequence.push_back(j);
		}
		last = *it;
	}

	return sequence;
}

std::vector<int> PmergeMe::_jacobsthalSequence(const int& size) {
	std::vector<int> jacob(1, 0);
	int last = 1, last_but_one = 0, tmp = 0;

	jacob.push_back(1);
	while (tmp < size) {
		tmp = last + 2 * last_but_one;
		jacob.push_back(tmp);
		last_but_one = last;
		last = tmp;
	}

	if (DEBUG) {
		std::cout << GREY << "Jacobsthal sequence: ";
		_printVector(jacob.begin(), jacob.end());
		std::cout << RESET << std::endl;
	}

	return jacob;
}

void PmergeMe::_printVector(const_iterator begin, const_iterator end) const {
	for (const_iterator it = begin; it != end; it++)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/27 19:33:38 by sguilher         ###   ########.fr       */
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
	_printVector(true, _vSequence.begin(), _vSequence.end(), "Before:	");
	_sortV();
	_printVector(true, _vSequence.begin(), _vSequence.end(), "After:	");
	std::cout << std::endl;
}

void PmergeMe::_sortV(void) {
	clock_t t;

	t = std::clock();
	_mergeInsertion(_vSequence.begin(), _vSequence.end(), 0);
	t = std::clock() - t;
	std::cout << GREY << "vector: sorting time: "
			<< ((float)t)/CLOCKS_PER_SEC * 1000 << " micro seconds"
			<< RESET << std::endl;
	_checkIfIsSorted(_vSequence.begin(), _vSequence.end());
}

void PmergeMe::_mergeInsertion(iterator first, iterator last, int iteration) {
	int		size, element_size, pair_size, pend_size;
	vector	pend, order, pairs_reference;
	odd_t	odd;

	element_size = std::pow(2, iteration);
	size = std::distance(first, last) / element_size;
	pair_size = std::pow(2, iteration + 1);
	printDetails(iteration, size, element_size, pair_size);
	if (size <= 1)
		return ;
	if (size == 2)
		return _sortSize2(first, element_size);
	if (size % 2 == 1) {
		last = last - element_size;
		odd = _removeLastElement(last, element_size);
	}
	else
		odd = odd_t(false, vector());

	_sortPairs(first, last, element_size, pair_size);

	_mergeInsertion(first, last, iteration + 1);
	_printAfterRecursion(iteration, first, last, element_size);

	pend_size = size / 2 + (odd.first ? 1 : 0);
	pend = _createPend(first, pend_size, size / 2, element_size, odd);

	_insertFirstElement(pend.begin(), pend.begin() + element_size);
	order = _getInsertionOrder(pend_size); ///////
	_insertElements(first, size, element_size, order, pend);
	// _checkIfIsSorted(first, _vSequence.end(), element_size);
	// dá pra saber que eles são menores do que os mesmos índices correspondentes...
	// inserir último número (se for ímpar) com binary search
}

void PmergeMe::_insertElements(
	iterator first, int size, int element_size, vector order, vector pend
) { // é dispendioso passar o order e o pend dessa forma??
	vector pairs_reference;
	iterator elem_init, elem_final, last, pairs_reference_it, p;
	int pos, value;
	size_t d;

	pairs_reference = _createPairsReference(size);
	for (iterator order_it = order.begin() + 1; order_it != order.end(); order_it++) {
		pairs_reference_it = pairs_reference.begin();
		pos = 0;

		while (pairs_reference_it != pairs_reference.end() && *pairs_reference_it != *order_it) {
			pairs_reference_it++;
			pos++;
		}

		value = pend.at((*order_it - 1) * element_size);
		elem_init = pend.begin() + (*order_it - 1) * element_size;
		elem_final = elem_init + element_size;

		if (pairs_reference_it == pairs_reference.end())
			last = first + pairs_reference.size() * element_size;
		else
			last = first + (pos - 1) * element_size;
		p = _binarySearch(first, last, value, element_size);
		_vSequence.insert(p, elem_init, elem_final);

		d = std::distance(first, p);
		if (d > pairs_reference.size())
			pairs_reference.insert(pairs_reference.end(), *order_it);
		else
			pairs_reference.insert(pairs_reference.begin() + std::distance(first, p), *order_it);

		_printVector(DEBUG, pairs_reference.begin(), pairs_reference.end(), "Pairs reference: ");
		_printVector(DEBUG, _vSequence.begin(), _vSequence.end(), "_vSequence: ");
	}
	_printVector(DEBUG, pend.begin(), pend.end(), "Pend: ");
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

PmergeMe::vector PmergeMe::_createPairsReference(int size) {
	vector pairs_reference;
	int half_size = size / 2;

	pairs_reference.reserve(size);
	pairs_reference.push_back(1);
	for (int i = 1; i <= half_size; i++)
		pairs_reference.push_back(i);
	_printVector(
		DEBUG, pairs_reference.begin(), pairs_reference.end(), "Pairs reference: "
	);
	return pairs_reference;
}

PmergeMe::vector PmergeMe::_getInsertionOrder(const int& size) {
	vector jacob, order(1, 1);
	int j, last = 1;
	iterator it;

	if (size < 3) {
		if (size == 2)
			order.push_back(2);
		return order;
	}
	order.reserve(size);
	jacob = _jacobsthalSequence(size);
	for (it = jacob.begin() + 3; it != jacob.end(); it++) {
		for (j = *it; j > last; j--) {
			if (j <= size)
				order.push_back(j);
		}
		last = *it;
	}
	_printVector(DEBUG, order.begin(), order.end(), "Insertion order: ");
	return order;
}

PmergeMe::vector PmergeMe::_jacobsthalSequence(const int& size) {
	vector jacob(1, 0);
	int last = 1, last_but_one = 0, tmp = 0;

	jacob.push_back(1);
	while (tmp < size) {
		tmp = last + 2 * last_but_one;
		jacob.push_back(tmp);
		last_but_one = last;
		last = tmp;
	}
	_printVector(DEBUG, jacob.begin(), jacob.end(), "Jacobsthal sequence: ");
	return jacob;
}

void PmergeMe::_insertFirstElement(iterator first, iterator last) {
	_vSequence.insert(_vSequence.begin(), first, last);
	_printVector(DEBUG, _vSequence.begin(), _vSequence.end(), "_vSequence: ");
}

void PmergeMe::_removePendElements(iterator first, int half_size, int element_size) {
	iterator it;

	for (int i = half_size; i > 0; i--) {
		it = first + (i * 2 - 1) * element_size;
		// std::cout << "remove from _vSequence: " << *it << std::endl;
		_vSequence.erase(it, it + element_size);
	}
}

PmergeMe::vector PmergeMe::_createPend(
	iterator first, int pend_size, int half_size, int element_size, odd_t odd
) {
	vector pend;
	iterator it;

	pend.reserve(pend_size * element_size);
	for (int i = 1; i <= half_size; i++) {
		it = first + (i * 2 - 1) * element_size;
		for (int j = 0; j < element_size; j++) {
			pend.push_back(*(it + j));
		}
	}
	if (odd.first && element_size == 1)
		pend.push_back(odd.second.at(0));
	else if (odd.first)
		pend.insert(pend.end(), odd.second.begin(), odd.second.end());
	_printVector(DEBUG, pend.begin(), pend.end(), "Pend: ");
	_removePendElements(first, half_size, element_size);
	_printVector(DEBUG, pend.begin(), pend.end(), "Pend: ");
	_printVector(DEBUG, _vSequence.begin(), _vSequence.end(), "_vSequence: ");
	return pend;
}

/* Separate elements in pairs and sort each disjoint pair in descending order */
void PmergeMe::_sortPairs(iterator first, iterator last, int e_size, int p_size) {
	for (iterator it = first; it != last; it += p_size) {
		if (*it < *(it + e_size)) {
			for (int i = 0; i < e_size; i++)
				std::swap(*(it + i), *(it + e_size + i));
		}
	}
	if (DEBUG) {
		std::cout << "Pairs ordered: | ";
		for (iterator it = first; it != last; it += p_size) {
			for (int i = 0; i < p_size; i++) {
				std::cout << *(it + i) << " ";
			}
			std::cout << "| ";
		}
		std::cout << RESET << std::endl;
	}
}

PmergeMe::odd_t PmergeMe::_removeLastElement(iterator last, int element_size) {
	std::pair<bool, vector > odd;
	vector odd_vector;

	for (int i = 0; i < element_size; i++) {
		odd_vector.push_back(*(last + i));
	}
	odd = std::pair<bool, vector >(true, odd_vector);
	_vSequence.erase(last, last + element_size);
	_printVector(DEBUG, odd.second.begin(), odd.second.end(), "odd size - removed element: ");
	_printVector(DEBUG, _vSequence.begin(), _vSequence.end(), "_vSequence: ");
	return odd;
}

void PmergeMe::_sortSize2(iterator first, int element_size) {
	iterator it = first;

	if (*it > *(it + element_size)) {
		for (int i = 0; i < element_size; i++)
			std::swap(*(it + i), *(it + element_size + i));
	}
}

void PmergeMe::_printVector(
	bool print, const_iterator begin, const_iterator end, std::string const& description
) const {
	if (print) {
		std::cout << GREY << description;
		for (const_iterator it = begin; it != end; it++)
			std::cout << *it << " ";
		std::cout << RESET << std::endl;
	}
}

void PmergeMe::_printAfterRecursion(
	int iteration, iterator first, iterator last, int element_size
) {
	if (DEBUG) {
		std::cout << GREY << "\n------------------------------------------\n"
			<< "iteration " << iteration
			<< ":\nPairs after merge insertion with bigger numbers: | ";
		for (iterator it = first; it != last; it += element_size) {
			for (int i = 0; i < element_size; i++) {
				std::cout << *(it + i) << " ";
			}
			std::cout << "| ";
		}
		std::cout << RESET << std::endl;
	}
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

void PmergeMe::_checkIfIsSorted(const_iterator begin, const_iterator end) const {
	bool sorted = true;
	int count = 0;

	for (const_iterator it = begin + 1; it != end; it++) {
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

void PmergeMe::_checkIfIsSorted(
	const_iterator begin, const_iterator end, int element_size
) const {
	bool sorted = true;
	int count = 0;

	for (const_iterator it = begin + element_size; it != end; it++) {
		if (*(it - element_size) > *it) {
			std::cout << ORANGE << *(it - element_size) << " and " << *it << std::endl;
			sorted = false;
			count++;
		}
	}
	if (!sorted)
		std::cout << "KO: vector is not sorted: " << count << RESET << std::endl;
	else if (DEBUG)
		std::cout << GREEN << "OK: vector is sorted" << RESET << std::endl;
}

unsigned int PmergeMe::_getNumber(std::string const str_nb) {
	std::stringstream	ss;
	unsigned int		nb;

	ss << str_nb;
	ss >> nb;

	return nb;
}

PmergeMe::vector PmergeMe::getVSequence(void) const {
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
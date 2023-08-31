/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/31 00:38:41 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { }

PmergeMe::PmergeMe(char *input[]): _size(0), _vt(0), _lt(0) {
	while(input[_size])
		_size++;
	_fillVector(input);
	_fillList(input);
}

PmergeMe::~PmergeMe(void) { }

PmergeMe::PmergeMe(PmergeMe const& p) {
	*this = p;
}

PmergeMe const& PmergeMe::operator=(PmergeMe const& p) {//////////
	if (this != &p) {
		this->_v = p.getVector();
		this->_l = p.getList();
	}
	return *this;
}

void PmergeMe::sort(void) {
	clock_t t;

	utils::printContainer(true, _l.begin(), _l.end(), "Before:	");

	t = std::clock();
	_vMergeInsertion(_v.begin(), _v.end(), 0);
	utils::checkIfIsSorted(_v.begin(), _v.end());
	t = std::clock() - t;
	_vt += t;

	t = std::clock();
	_lMergeInsertion(_l.begin(), _l.end(), 0);
	// utils::checkIfIsSorted(_l.begin(), _l.end());
	t = std::clock() - t;
	_lt += t;

	utils::printContainer(true, _v.begin(), _v.end(), "After:	");
	utils::printContainer(true, _l.begin(), _l.end(), "After:	");
	std::cout << GREY << "Time to process a range of " << _size
			<< " elements with std::<vector>: "
			<< ((float)_vt)/CLOCKS_PER_SEC * 1000 << " micro seconds"
			<< RESET << std::endl;
	std::cout << GREY << "Time to process a range of " << _size
			<< " elements with std::<list>:   "
			<< ((float)_lt)/CLOCKS_PER_SEC * 1000 << " micro seconds"
			<< RESET << std::endl;
}

void PmergeMe::_vMergeInsertion(v_iterator first, v_iterator last, int iteration) {
	int		size, element_size, pair_size, pend_size;
	vector	pend, order, pairs_reference;
	v_odd_t	odd;

	element_size = std::pow(2, iteration);
	size = std::distance(first, last) / element_size;
	pair_size = std::pow(2, iteration + 1);
	utils::printDetails(iteration, size, element_size, pair_size);
	if (size <= 1)
		return ;
	if (size == 2)
		return _sortSize2(first, element_size);
	if (size % 2 == 1) {
		last = last - element_size;
		odd = _removeLastElementV(last, element_size);
	}
	else
		odd = v_odd_t(false, vector());

	_sortVPairs(first, last, element_size, pair_size);

	_vMergeInsertion(first, last, iteration + 1);
	utils::printAfterRecursion(iteration, first, last, element_size);

	pend_size = size / 2 + (odd.first ? 1 : 0);
	pend = _createPend(first, pend_size, size / 2, element_size, odd);

	_insertFirstElement(pend.begin(), pend.begin() + element_size);
	order = _getInsertionOrder(pend_size);
	_insertElements(first, size, element_size, order, pend);
	if (element_size != 1)
		utils::checkIfIsSorted(
			_v.begin(), _v.end(), element_size);
}

void PmergeMe::_lMergeInsertion(l_iterator first, l_iterator last, int iteration) {
	int		size, element_size, pair_size; //, pend_size;
	list	pend, order, pairs_reference;
	l_odd_t	odd;

	element_size = std::pow(2, iteration);
	size = std::distance(first, last) / element_size;
	pair_size = std::pow(2, iteration + 1);
	utils::printDetails(iteration, size, element_size, pair_size);
	if (size <= 1)
		return ;
	if (size == 2)
		return _sortSize2(first, element_size);
	if (size % 2 == 1) {
		for (int i = 0; i < element_size; i++)
			last--;
		odd = _removeLastElementL(last, element_size);
	}
	else
		odd = l_odd_t(false, list());

	_sortLPairs(first, element_size, pair_size, size / pair_size);

	// _lMergeInsertion(first, last, iteration + 1);
	// utils::printAfterRecursion(iteration, first, last, element_size);

	// pend_size = size / 2 + (odd.first ? 1 : 0);
	// pend = _createPend(first, pend_size, size / 2, element_size, odd);

	// _insertFirstElement(pend.begin(), pend.begin() + element_size);
	// order = _getInsertionOrder(pend_size);
	// _insertElements(first, size, element_size, order, pend);
	// if (element_size != 1)
	// 	utils::checkIfIsSorted(
	// 		_v.begin(), _v.end(), element_size);
}

void PmergeMe::_insertElements(
	v_iterator first, int size, int element_size, vector order, vector pend
) { // é dispendioso passar o order e o pend dessa forma??
	vector pairs_reference;
	v_iterator order_it, p, elem_init, elem_final;
	size_t d;

	pairs_reference = _createPairsReference(size);
	for (order_it = order.begin() + 1; order_it != order.end(); order_it++) {
		p = _findPosition(first, order_it, element_size, pend, pairs_reference);
		elem_init = pend.begin() + (*order_it - 1) * element_size;
		elem_final = elem_init + element_size;
		_v.insert(p, elem_init, elem_final);

		d = std::distance(first, p) / element_size;
		if (d > pairs_reference.size())
			pairs_reference.insert(pairs_reference.end(), *order_it);
		else
			pairs_reference.insert(pairs_reference.begin() + d, *order_it);

		utils::printAfterInsert(
			DEBUG,
			pairs_reference.begin(), pairs_reference.end(),
			_v.begin(), _v.end(),
			"_vSequence: "
		);
	}
	utils::printContainer(DEBUG, pend.begin(), pend.end(), "Pend: ");
}

PmergeMe::v_iterator PmergeMe::_findPosition(
	v_iterator first, v_iterator order_it, int element_size, vector pend, vector& pairs_reference
) {
	v_iterator last, pairs_reference_it;
	int idx = 0, value;

	pairs_reference_it = pairs_reference.begin();
	while (
		pairs_reference_it != pairs_reference.end()
		&& *pairs_reference_it != *order_it
	) {
		pairs_reference_it++;
		idx++;
	}

	if (pairs_reference_it == pairs_reference.end()) {
		last = first + (pairs_reference.size() - 1) * element_size;
	}
	else // não manda o par, porque já sabe que é menor; manda o elemento anterior
		last = first + (idx - 1) * element_size;
	value = pend.at((*order_it - 1) * element_size);
	return _binarySearch(first, last, value, element_size);
}

PmergeMe::vector PmergeMe::_createPairsReference(int size) {
	vector pairs_reference;
	int half_size = size / 2;

	pairs_reference.reserve(size);
	pairs_reference.push_back(1);
	for (int i = 1; i <= half_size; i++)
		pairs_reference.push_back(i);
	utils::printContainer(
		DEBUG, pairs_reference.begin(), pairs_reference.end(), "Pairs reference: "
	);
	return pairs_reference;
}

PmergeMe::vector PmergeMe::_getInsertionOrder(const int& size) {
	vector jacob, order(1, 1);
	int j, last = 1;
	v_iterator it;

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
	utils::printContainer(
		DEBUG, order.begin(), order.end(), "Insertion order: "
	);
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
	utils::printContainer(
		DEBUG, jacob.begin(), jacob.end(), "Jacobsthal sequence: "
	);
	return jacob;
}

void PmergeMe::_insertFirstElement(v_iterator first, v_iterator last) {
	_v.insert(_v.begin(), first, last);
	utils::printContainer(
		DEBUG, _v.begin(), _v.end(), "_v: "
	);
}

PmergeMe::vector PmergeMe::_createPend(
	v_iterator first, int pend_size, int half_size, int element_size, v_odd_t odd
) {
	vector pend;
	v_iterator it;

	pend.reserve(pend_size * element_size);
	for (int i = 1; i <= half_size; i++) {
		it = first + (i * 2 - 1) * element_size;
		for (int j = 0; j < element_size; j++)
			pend.push_back(*(it + j));
	}
	if (odd.first && element_size == 1)
		pend.push_back(odd.second.at(0));
	else if (odd.first)
		pend.insert(pend.end(), odd.second.begin(), odd.second.end());
	utils::printContainer(DEBUG, pend.begin(), pend.end(), "Pend: ");
	_removePendElements(first, half_size, element_size);
	utils::printContainer(DEBUG, pend.begin(), pend.end(), "Pend: ");
	utils::printContainer(
		DEBUG, _v.begin(), _v.end(), "_vSequence: "
	);
	return pend;
}

void PmergeMe::_sortVPairs(v_iterator first, v_iterator last, int e_size, int p_size) {
	for (v_iterator it = first; it != last; it += p_size) {
		if (*it < *(it + e_size))
			_swapPair(it, it + e_size, e_size);
	}
	if (DEBUG) {
		std::cout << "Pairs ordered: | ";
		for (v_iterator it = first; it != last; it += p_size) {
			for (int i = 0; i < p_size; i++) {
				std::cout << *(it + i) << " ";
			}
			std::cout << "| ";
		}
		std::cout << RESET << std::endl;
	}
}

void PmergeMe::_sortLPairs(l_iterator first, int e_size, int p_size, int size) {
	l_iterator ita = first, itb;

	std::cout << "sortPairs: pair size: " << size << "; element_size: " << e_size << std::endl;
	itb = ita;
	std::advance(itb, e_size);
	for (int i = 0; i < size; i++) {
		std::cout << *ita << " and " << *itb << std::endl;
		if (*ita < *itb)
			_swapPair(ita, itb, e_size);
		std::advance(ita, p_size);
		std::advance(itb, p_size);
	}
	// if (DEBUG) {
	// 	std::cout << "Pairs ordered: | ";
	// 	for (l_iterator it = first; it != last; it += p_size) {
	// 		for (int i = 0; i < p_size; i++) {
	// 			std::cout << *(it + i) << " ";
	// 		}
	// 		std::cout << "| ";
	// 	}
	// 	std::cout << RESET << std::endl;
	// }
}

PmergeMe::v_odd_t PmergeMe::_removeLastElementV(
	v_iterator last, int element_size
) {
	v_odd_t odd;
	vector odd_vector;

	for (int i = 0; i < element_size; i++) {
		odd_vector.push_back(*(last + i));
	}
	odd = v_odd_t(true, odd_vector);
	_v.erase(last, last + element_size);
	utils::printContainer(
		DEBUG, odd.second.begin(), odd.second.end(), "odd size: removed element: "
	);
	utils::printContainer(DEBUG, _v.begin(), _v.end(), "vector: ");
	return odd;
}

PmergeMe::l_odd_t PmergeMe::_removeLastElementL(
	l_iterator last, int element_size
) {
	l_odd_t odd;
	list odd_list;
	l_iterator it = last;

	for (int i = 0; i < element_size; i++) {
		odd_list.push_back(*it);
		it++;
	}
	odd = l_odd_t(true, odd_list);
	_l.erase(last, it);
	utils::printContainer(
		DEBUG, odd.second.begin(), odd.second.end(), "odd size: removed element: "
	);
	utils::printContainer(DEBUG, _l.begin(), _l.end(), "list: ");
	return odd;
}

void PmergeMe::_fillVector(char *input[]) {
	int i = 0;

	_vt = std::clock();
	_v.reserve(_size);
	while (input[i]) {
		_v.push_back(utils::getNumber(input[i]));
		i++;
	}
	_vt = std::clock() - _vt;
	if (DEBUG)
		std::cout << GREY << "vector: input insertion time: "
				<< ((float)_vt)/CLOCKS_PER_SEC * 1000 << " micro seconds"
				<< RESET << std::endl;
}

void PmergeMe::_fillList(char *input[]) {
	int i = 0;

	_lt = std::clock();
	while (input[i]) {
		_l.push_back(utils::getNumber(input[i]));
		i++;
	}
	_lt = std::clock() - _lt;
	if (DEBUG)
		std::cout << GREY << "list: input insertion time: "
				<< ((float)_lt)/CLOCKS_PER_SEC * 1000 << " micro seconds"
				<< RESET << std::endl;
}

PmergeMe::vector PmergeMe::getVector(void) const {
	return this->_v;
}

PmergeMe::list PmergeMe::getList(void) const {
	return this->_l;
}

size_t PmergeMe::size(void) const {
	return this->_size;
}

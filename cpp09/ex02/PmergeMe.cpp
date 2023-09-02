/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:59:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/09/02 18:28:19 by sguilher         ###   ########.fr       */
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

	// t = std::clock();
	// _vMergeInsertion(_v.begin(), _v.end(), 0);
	// utils::checkIfIsSorted(_v.begin(), _v.end(), "vector");
	// t = std::clock() - t;
	// _vt += t;

	t = std::clock();
	_lMergeInsertion(_l.begin(), _l.end(), 0);
	utils::checkIfIsSorted(_l.begin(), _l.end(), "list");
	t = std::clock() - t;
	_lt += t;

	// utils::printContainer(true, _v.begin(), _v.end(), "After:	");
	// utils::printContainer(true, _l.begin(), _l.end(), "After:	");
	// std::cout << GREY << "Time to process a range of " << _size
	// 		<< " elements with std::<vector>: "
	// 		<< ((float)_vt)/CLOCKS_PER_SEC * 1000 << " micro seconds"
	// 		<< RESET << std::endl;
	std::cout << GREY << "Time to process a range of " << _size
			<< " elements with std::<list>:   "
			<< ((float)_lt)/CLOCKS_PER_SEC * 1000 << " micro seconds"
			<< RESET << std::endl;
}

void PmergeMe::_vMergeInsertion(v_iterator first, v_iterator last, int iteration) {
	int		size, element_size, pair_size, pend_size, half_size;
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
		odd = _vRemoveLastElement(last, element_size);
	}
	else
		odd = v_odd_t(false, vector());

	_vSortPairs(first, last, element_size, pair_size);

	_vMergeInsertion(first, last, iteration + 1);
	utils::printAfterRecursion(iteration, first, last, element_size);

	half_size = size / 2;
	pend_size = half_size + (odd.first ? 1 : 0);
	pend.reserve(pend_size * element_size);
	_createPend(pend, first, size / 2, element_size, odd);
	_vRemovePendElements(first, half_size, element_size);
	utils::printContainer(DEBUG, pend.begin(), pend.end(), "Pend: ");
	utils::printContainer(DEBUG, _v.begin(), _v.end(), "vector: ");

	_vInsertFirstElement(pend.begin(), pend.begin() + element_size);
	order.reserve(size);
	_getInsertionOrder<vector, v_iterator>(pend_size, order);
	_vInsertElements(first, size, element_size, order, pend);
	if (element_size != 1)
		utils::checkIfIsSorted(_v.begin(), _v.end(), element_size, "vector");
}

void PmergeMe::_lMergeInsertion(l_iterator first, l_iterator last, int iteration) {
	int		size, element_size, pair_size, pend_size, half_size;
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
		odd = _lRemoveLastElement(last, element_size);
		last = _l.end();
	}
	else
		odd = l_odd_t(false, list());

	first = _l.begin();
	last = _l.end();
	_lSortPairs(first, last, element_size, pair_size);

	_lMergeInsertion(first, last, iteration + 1);
	first = _l.begin();
	last = _l.end();
	utils::printAfterRecursion(iteration, first, last, element_size);

	half_size = size / 2;
	pend_size = half_size + (odd.first ? 1 : 0);
	_createPend(pend, first, size / 2, element_size, odd);
	_lRemovePendElements(first, half_size, element_size);
	// first = _l.begin();
	last = _l.end();
	utils::printContainer(DEBUG, pend.begin(), pend.end(), "Pend: ");
	utils::printContainer(DEBUG, _l.begin(), _l.end(), "list: ");

	_lInsertFirstElement(pend.begin(), element_size);
	first = _l.begin();
	_getInsertionOrder<list, l_iterator>(pend_size, order);
	_lInsertElements(first, size, element_size, order, pend);
	if (element_size != 1)
		utils::checkIfIsSorted(_l.begin(), _l.end(), element_size, "list");
}

void PmergeMe::_vInsertElements(
	v_iterator first, int size, int element_size, vector order, vector pend
) {
	vector pairs_reference;
	v_iterator order_it, p, elem_init, elem_final;
	size_t d;

	pairs_reference.reserve(size);
	_createPairsReference(size, pairs_reference);
	for (order_it = order.begin() + 1; order_it != order.end(); order_it++) {
		p = _vFindPosition(first, order_it, element_size, pend, pairs_reference);
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
			"- vector: "
		);
	}
	utils::printContainer(DEBUG, pend.begin(), pend.end(), "Pend: ");
}

void PmergeMe::_lInsertElements(
	l_iterator first, int size, int element_size, list order, list pend
) {
	list pairs_reference;
	l_iterator order_it, p, elem_init, elem_final, tmp;
	size_t d;

	_createPairsReference(size, pairs_reference);
	for (order_it = ++order.begin(); order_it != order.end(); order_it++) {
		first = _l.begin();
		p = _lFindPosition(first, order_it, element_size, pend, pairs_reference);
		elem_init = pend.begin();
		std::advance(elem_init, (*order_it - 1) * element_size);
		elem_final = elem_init;
		std::advance(elem_final, element_size);
		_l.insert(p, elem_init, elem_final);
		first = _l.begin();

		d = std::distance(first, p) / element_size;
		if (d > pairs_reference.size())
			pairs_reference.insert(pairs_reference.end(), *order_it);
		else {
			tmp = pairs_reference.begin();
			std::advance(tmp, d);
			pairs_reference.insert(tmp, *order_it);
		}

		utils::printAfterInsert(
			DEBUG,
			pairs_reference.begin(), pairs_reference.end(),
			_l.begin(), _l.end(),
			"- list: "
		);
	}
	utils::printContainer(DEBUG, pend.begin(), pend.end(), "Pend: ");
}

PmergeMe::v_iterator PmergeMe::_vFindPosition(
	v_iterator first, v_iterator order_it, int element_size, vector pend, vector& pairs_reference
) {
	v_iterator last, pairs_reference_it;
	int idx = 0, value;

	pairs_reference_it = pairs_reference.begin();
	last = pairs_reference.end();
	while (pairs_reference_it != last && *pairs_reference_it != *order_it) {
		pairs_reference_it++;
		idx++;
	}

	if (pairs_reference_it == last) {
		last = first + (pairs_reference.size() - 1) * element_size;
	}
	else // não manda o par, porque já sabe que é menor; manda o elemento anterior
		last = first + (idx - 1) * element_size;
	value = pend.at((*order_it - 1) * element_size);
	return _binarySearch(first, last, value, element_size);
}

PmergeMe::l_iterator PmergeMe::_lFindPosition(
	l_iterator first, l_iterator order_it, int element_size, list pend, list& pairs_reference
) {
	l_iterator last, pairs_reference_it, value;
	int idx = 0;

	pairs_reference_it = pairs_reference.begin();
	last = pairs_reference.end();
	while (pairs_reference_it != last && *pairs_reference_it != *order_it) {
		pairs_reference_it++;
		idx++;
	}

	first = _l.begin();
	if (pairs_reference_it == last) {
		last = first;
		std::advance(last, (pairs_reference.size() - 1) * element_size);
	}
	else {
		// não manda o par, porque já sabe que é menor; manda o elemento anterior
		last = first;
		std::advance(last, (idx - 1) * element_size);
	}
	value = pend.begin();
	std::advance(value, (*order_it - 1) * element_size);
	return _binarySearch(first, last, *value, element_size);
}

void PmergeMe::_vInsertFirstElement(v_iterator first, v_iterator last) {
	_v.insert(_v.begin(), first, last);
	utils::printContainer(
		DEBUG, _v.begin(), _v.end(), "vector after insert pend's first element: "
	);
}

void PmergeMe::_lInsertFirstElement(l_iterator first, int element_size) {
	l_iterator last = first;

	std::advance(last, element_size);
	_l.insert(_l.begin(), first, last);
	utils::printContainer(
		DEBUG, _l.begin(), _l.end(), "list after insert pend's first element: "
	);
}

void PmergeMe::_vRemovePendElements(
	v_iterator first, int half_size, int element_size
) {
	v_iterator it;

	for (int i = half_size; i > 0; i--) {
		it = first + (i * 2 - 1) * element_size;
		_v.erase(it, it + element_size);
	}
}

void PmergeMe::_lRemovePendElements(
	l_iterator first, int half_size, int element_size
) {
	l_iterator f, last;

	f = first;
	for (int i = half_size; i > 0; i--) {
		f = first;
		std::advance(f, (i * 2 - 1) * element_size);
		last = f;
		std::advance(last, element_size);
		_l.erase(f, last);
	}
}

void PmergeMe::_vSortPairs(v_iterator first, v_iterator last, int e_size, int p_size) {
	for (v_iterator it = first; it != last; it += p_size) {
		if (*it < *(it + e_size))
			_swapPair(it, it + e_size, e_size);
	}
	if (DEBUG) {
		std::cout << GREY << "Pairs ordered: | ";
		utils::printContainer(_v.begin(), _v.end(), e_size);
		std::cout << RESET << std::endl;
	}
}

// TODO: testar transformar em uma única
void PmergeMe::_lSortPairs(l_iterator first, l_iterator last, int e_size, int p_size) {
	l_iterator ita, itb;
	int i;

	ita = first;
	itb = first;
	std::advance(itb, e_size);
	while (ita != last) {
		// std::cout << *ita << " " << * itb << std::endl;
		if (*ita < *itb) {
			for (i = 0; i < e_size; i++) {
				// std::cout << "2. ita e itb: " << *a << " " << *b << std::endl;
				std::swap(*ita++, *itb++);
			}
			std::advance(ita, e_size);
			std::advance(itb, e_size);
		}
		else {
			std::advance(ita, p_size);
			std::advance(itb, p_size);
		}
		// std::cout << *ita << " " << * itb << std::endl;
	}
	if (DEBUG) {
		std::cout << GREY << "Pairs ordered: | ";
		utils::printContainer(_l.begin(), _l.end(), e_size);
		std::cout << RESET << std::endl;
	}
}

PmergeMe::v_odd_t PmergeMe::_vRemoveLastElement(
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
	utils::printContainer(DEBUG, _v.begin(), _v.end(), "- vector: ");
	return odd;
}

PmergeMe::l_odd_t PmergeMe::_lRemoveLastElement(
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

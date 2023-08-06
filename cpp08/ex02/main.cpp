/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:48:23 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/06 12:48:49 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

void printTitle(std::string const& title) {
	std::cout << std::endl << BLUE << title << RESET << std::endl;
}

int main()
{
	printTitle("PDF tests - results with std::list");
	std::list<int> list;
	if (DEBUG)
		std::cout << GREY << "type" << typeid(list).name()
			<< RESET << std::endl;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;

	list.pop_back();

	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator it_list = list.begin();
	std::list<int>::iterator ite_list = list.end();

	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	std::list<int> l(list);

	printTitle("PDF tests - results with MutantStack - container default = deque");
	MutantStack<int> mstack;
	testPdf(mstack);

	printTitle("PDF tests - results with MutantStack with container base = list");
	MutantStack<int, std::list<int> > mstack_list;
	testPdf(mstack_list);

	printTitle("PDF tests - results with MutantStack with container base = vector");
	MutantStack<int, std::vector<int> > mstack_vector;
	testPdf(mstack_vector);

	printTitle("*************************************************************");

	return 0;
}
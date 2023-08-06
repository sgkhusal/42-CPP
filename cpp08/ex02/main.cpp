/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:48:23 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/06 17:09:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "tests_utils.hpp"
#include <iostream>
#include <list>
#include <vector>

static void testString(void);

int main()
{
	printTitle("PDF tests - results for std::list");
	std::list<int> list;
	if (DEBUG)
		std::cout << GREY << "type: " << typeid(list).name()
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

	printTitle("PDF tests - results for MutantStack with container = deque (default)");
	MutantStack<int> mstack;
	testPdf(mstack);

	printTitle("PDF tests - results for MutantStack with container = list");
	MutantStack<int, std::list<int> > mstack_list;
	testPdf(mstack_list);

	printTitle("PDF tests - results for MutantStack with container = vector");
	MutantStack<int, std::vector<int> > mstack_vector;
	testPdf(mstack_vector);

	printTitle("************************* MY TESTS **************************");
	printTitle("Testing MutantStack<float> (default stack container)");
	MutantStack<float> mstack_float;
	myTests(mstack_float);

	printTitle("Testing MutantStack<double, std::vector<double> >");
	MutantStack<double, std::vector<double> > mstack_double;
	myTests(mstack_double);

	testString();

	return 0;
}

static void testString(void) {
	printTitle("Testing MutantStack<std::string> (default stack container)");
	typedef MutantStack<std::string> mstack_string;
	mstack_string mstack;

	if (DEBUG)
		std::cout << GREY << "_Container type" << typeid(mstack).name()
			<< RESET << std::endl;

	std::cout << GREY << std::endl;
	std::cout << "Is empty? " << (mstack.empty() ? "true" : "false") << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	printSubDescription("Filling MutantStack with push()");
	mstack.push("Harry Potter");
	mstack.push("Hermione Granger");
	mstack.push("Ronald Weasley");
	std::cout << "size: " << mstack.size() << std::endl << std::endl;
	printSubDescription("Testing top()");
	std::cout << mstack.top() << std::endl << std::endl;

	printDescription("Testing iterator");
	mstack_string::iterator it;
	for (it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	it--;
	it--;
	it++;

	printDescription("Changing last element value");
	*it = "Harry Potter 2";
	std::cout << GREY << *it << std::endl << std::endl;

	printSubDescription("Removing last element with pop()");
	mstack.pop();

	printDescription("Testing const_iterator");
	mstack_string::const_iterator const_it;
	for (const_it = mstack.begin(); const_it != mstack.end(); const_it++)
		std::cout << *const_it << " ";
	std::cout << std::endl << std::endl;
	const_it--;
	const_it--;
	const_it++;

	printDescription("Testing reverse_iterator");
	mstack_string::reverse_iterator rit;
	for (rit = mstack.rbegin(); rit != mstack.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl << std::endl;
	rit--;
	rit--;
	rit++;

	printSubDescription("Changing first element value");
	*rit = "Harry";
	std::cout << GREY << *rit << std::endl << std::endl;

	printDescription("Testing const_reverse_iterator");
	mstack_string::const_reverse_iterator const_rit;
	for (const_rit = mstack.rbegin(); const_rit != mstack.rend(); const_rit++)
		std::cout << *const_rit << " ";
	std::cout << std::endl << std::endl;
	const_rit--;
	const_rit--;
	const_rit++;

	{
		printDescription("Construction by copy and assignment operator");
		mstack_string copy1(mstack);
		mstack_string copy2 = mstack;
		mstack_string::iterator it1, it2;

		std::cout << GREY << "original: " << mstack << std::endl;
		std::cout << "copy1:    " << copy1 << std::endl;
		std::cout << "copy2:    " << copy2 << RESET << std::endl;

		bool ok = true;
		for(
			it = mstack.begin(), it1 = copy1.begin(), it2 = copy2.begin();
			it != mstack.end();
			it++, it1++, it2++
		)
			if (*it != *it1 && *it != *it2)
				ok = false;
		printResult(ok);

		printDescription("Deep copy:");
		it = mstack.begin();
		*it = "Hermione";
		it1 = copy1.begin();
		*it1 = "Rony";

		std::cout << GREY << "original: " << mstack << std::endl;
		std::cout << "copy1:    " << copy1 << std::endl;
		std::cout << "copy2:    " << copy2 << RESET << std::endl;

		ok = true;
		if (*it == *it1 || *it == *it2)
			ok = false;
		printResult(ok);
	}
}

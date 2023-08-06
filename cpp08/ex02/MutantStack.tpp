/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:03:23 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/06 15:40:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP

# include "MutantStack.hpp"
# include <typeinfo>
# include <iostream>
# include <cstdlib>

# ifndef DEBUG
    #define DEBUG false
# endif

# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define ORANGE	"\033[0;38;5;166m"
# define PURPLE	"\033[38;5;200m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

template<typename T, typename _Container>
void testPdf(MutantStack<T, _Container> mstack) {
	if (DEBUG)
		std::cout << GREY << "_Container type: " << typeid(mstack).name()
			<< RESET << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	typename MutantStack<T, _Container>::iterator it = mstack.begin();
	typename MutantStack<T, _Container>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<T, _Container> s(mstack);
}

static void printDescription(std::string const& description) {
	std::cout << PURPLE << description << std::endl << GREY;
}

static void printSubDescription(std::string const& description) {
	std::cout << GREY << description << std::endl;
}

template<typename T, typename _Container>
void myTests(MutantStack<T, _Container> mstack) {
	if (DEBUG)
		std::cout << GREY << "_Container type" << typeid(mstack).name()
			<< RESET << std::endl;

	srand(1);
	std::cout << GREY << std::endl;
	std::cout << "Is empty? " << (mstack.empty() ? "true" : "false") << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	printSubDescription("Filling MutantStack with push()");
	for (int i = 0; i < 10; i++)
		mstack.push(T(rand() % 1000) / 100);
	std::cout << "size: " << mstack.size() << std::endl << std::endl;
	printSubDescription("Testing top()");
	std::cout << mstack.top() << std::endl << std::endl;

	printDescription("Testing iterator");
	typename MutantStack<T, _Container>::iterator it;
	for (it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	it--;
	it--;
	it++;

	printDescription("Changing last element value");
	std::cout << GREY << ++(*it) << std::endl << std::endl;

	printSubDescription("Removing last element with pop()");
	mstack.pop();

	printDescription("Testing const_iterator");
	typename MutantStack<T, _Container>::const_iterator const_it;
	for (const_it = mstack.begin(); const_it != mstack.end(); const_it++)
		std::cout << *const_it << " ";
	std::cout << std::endl << std::endl;
	const_it--;
	const_it--;
	const_it++;

	printDescription("Testing reverse_iterator");
	typename MutantStack<T, _Container>::reverse_iterator rit;
	for (rit = mstack.rbegin(); rit != mstack.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl << std::endl;
	rit--;
	rit--;
	rit++;

	printSubDescription("Changing first element value");
	std::cout << GREY << --(*rit) << std::endl << std::endl;

	printDescription("Testing const_reverse_iterator");
	typename MutantStack<T, _Container>::const_reverse_iterator const_rit;
	for (const_rit = mstack.rbegin(); const_rit != mstack.rend(); const_rit++)
		std::cout << *const_rit << " ";
	std::cout << std::endl << std::endl;
	const_rit--;
	const_rit--;
	const_rit++;

	std::stack<T, _Container> s(mstack);

	std::cout << RESET << std::endl;
}

#endif
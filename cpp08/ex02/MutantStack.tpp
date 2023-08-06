/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:03:23 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/06 12:42:21 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP

# include "MutantStack.hpp"
# include <typeinfo>
# include <iostream>

# ifndef DEBUG
    #define DEBUG false
# endif

#define BLUE	"\033[38;5;75m"
#define GREEN	"\033[1;32m"
#define ORANGE	"\033[0;38;5;166m"
#define GREY	"\033[38;5;244m"
#define RESET	"\033[0m"

template<typename T, typename _Container>
void testPdf(MutantStack<T, _Container> mstack) {
	if (DEBUG)
		std::cout << GREY << "_Container type" << typeid(mstack).name()
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

template<typename T, typename _Container>
void myTests(MutantStack<T, _Container> mstack) {
	(void)mstack;
}

#endif
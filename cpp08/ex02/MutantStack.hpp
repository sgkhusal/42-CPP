/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:48:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/06 12:38:31 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <deque>

template <typename T, typename _Container = std::deque<T> >
class MutantStack: public std::stack<T, _Container> {
private:
	typedef typename std::stack<T, _Container>::container_type _container;

public:
	/* iterators types (MutantStack additional member types) */
	typedef typename _container::iterator				iterator;
	typedef typename _container::const_iterator			const_iterator;
	typedef typename _container::reverse_iterator		reverse_iterator;
	typedef typename _container::const_reverse_iterator	const_reverse_iterator;

	/* iterators member functions */
	iterator				begin(void) { return this->c.begin(); };
	const_iterator			begin(void) const { return this->c.begin(); };

	iterator				end(void) { return this->c.end(); };
	const_iterator			end(void) const { return this->c.end(); };

	reverse_iterator		rbegin(void) { return this->c.begin(); };
	const_reverse_iterator	rbegin(void) const { return this->c.begin(); };

	reverse_iterator		rend(void) { return this->c.begin(); };
	const_reverse_iterator	rend(void) const { return this->c.begin(); };

	/* canonical form */
	MutantStack(void): std::stack<T, _Container>() { };
	~MutantStack(void) { };
	MutantStack(
		MutantStack<T, _Container> const& stack
	): std::stack<T, _Container>(stack) { };

	MutantStack<T, _Container> const& operator=(
		MutantStack<T, _Container> const& stack
	) {
		if (*this != &stack)
			*this = stack;  // verify: this->c = stack.c ?
	};
};

template<typename T, typename _Container>
void testPdf(MutantStack<T, _Container> mstack);

template<typename T, typename _Container>
void myTests(MutantStack<T, _Container> mstack);

# include "MutantStack.tpp"

#endif
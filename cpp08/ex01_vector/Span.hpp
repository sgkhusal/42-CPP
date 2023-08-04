/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:17:55 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/05 00:30:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <exception>
# include <algorithm>

# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define ORANGE	"\033[0;38;5;166m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

# ifndef DEBUG
    #define DEBUG false
# endif

typedef std::vector<int>::const_iterator const_vector_itr;
typedef std::vector<int>::iterator vector_itr;

class Span {
public:
	Span(size_t n);
	Span(Span const& span);
	~Span(void);
	Span const& operator=(Span const& span);

	size_t				size(void) const;
	size_t				capacity(void) const;
	const_vector_itr	begin(void) const;
	const_vector_itr	end(void) const;
	vector_itr			begin(void);
	vector_itr			end(void);
	const_vector_itr	backIterator(void) const;

	std::vector<int>	getSpan(void) const;

	void	addNumber(int number);

	template <typename T>
	void	addNumber(T first, T last) {
		for (T it = first; it != last; it++)
			this->addNumber(*it);
	}

	size_t	shortestSpan(void) const;
	size_t	longestSpan(void) const;

private:
	Span(void);

	std::vector<int>	_span;

	class FullSpanException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class NoSpanException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, Span const& s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 09:39:00 by sguilher          #+#    #+#             */
/*   Updated: 2023/08/14 11:45:23 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>

class RPN {
public:
	RPN(std::string const input);
	~RPN(void);
	RPN(RPN const& rpn);
	RPN const& operator=(RPN const& rpn);

	std::string getExpression(void) const;
	int executeRPN(void);

private:
	RPN(void);

	std::string		_input;
	static std::string const	_validOperations;

	void _checkInput(std::string const input);
	int _makeOperation(int a, int b, char op);

	class InvalidInput: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class ImpossibleOperation: public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif
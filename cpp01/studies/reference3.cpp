/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference3.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:02:50 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 14:30:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student {
	private:
		std::string _login;

	public:
		Student(std::string const & login): _login(login) {
			return ;
		}
		std::string&	getLoginRef() {
			return (this->_login);
		}
		std::string const &	getLoginRefConst() const { // não altera valores da instância
			return (this->_login);
		}
		std::string*	getLoginPtr() {
			return &(this->_login);
		}
		std::string const *	getLoginPtrConst() const { // não altera valores da instância
			return &(this->_login);
		}
};

int	main(void) {
	Student			bob = Student("bfubar");
	Student const	jim = Student("jfubar");

	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;
	// using a const function on a not const variable is not a problem

	bob.getLoginRef() = "bobfubar";
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "bobbyfubar";
	std::cout << bob.getLoginRefConst() << std::endl;
}

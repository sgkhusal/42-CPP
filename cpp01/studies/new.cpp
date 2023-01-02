/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:52:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/29 13:20:33 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class	Student {
	private:
		std::string	_login;

	public:
		Student(std::string login) : _login(login) {
			std::cout << "Student " << this->_login << "is born" << std::endl;
		}
		~Student() {
			std::cout << "student " << this->_login << " died" << std::endl;
		}
};

class	Student2 {
	private:
		int			_studentNb;
		static int	_totalStudents;

	public:
		Student2() : _studentNb(Student2::_totalStudents + 1) {
			Student2::_totalStudents += 1;
			std::cout << "Student " << this->_studentNb << " is born" << std::endl;
		}
		~Student2() {
			Student2::_totalStudents -= 1;
			std::cout << "student " << this->_studentNb << " died" << std::endl;
		}
};

int	Student2::_totalStudents = 0;

int	main(void) {
	Student		bob = Student("bfubar");
	Student*	jim = new Student("jfubar");
	Student2*	students = new Student2[42];

	// do some stuff here

	delete jim; // jim is destroyed - if it is not deleted will result in memory leak
	delete [] students;
	// delete students; - only free the first element of the array
	return (0); // bob is destroyed
}

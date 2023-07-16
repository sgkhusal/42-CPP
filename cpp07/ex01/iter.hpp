/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:02:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/16 00:54:40 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# define BLUE	"\033[38;5;75m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

template<typename T>
void iter(T* array, size_t len, void (*fptr)(T& elem)) {
	for (size_t i = 0; i < len; i++)
		fptr(array[i]);
}

template<typename T>
void addOne(T& elem) {
	elem++;
}

template<typename T>
void reduceOne(T& elem) {
	elem--;
}

template<typename T>
void printElem(T& elem) {
	std::cout << elem << " ";
}

template<typename T>
void printElem2(T& elem) {
	std::cout << elem << std::endl;
}

#endif

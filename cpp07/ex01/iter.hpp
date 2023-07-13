/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:02:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/13 12:56:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void iter(T& array, int len, void (*fptr)(T& elem)) {
	// T::iterator it = array.begin(); // podemos usar um iterator? ou temos que usar idx?

	for (int i = 0; i < len; i++)
		fptr(&array[i]);
}

template<typename T>
void add_one(T& elem) {
	elem++;
}

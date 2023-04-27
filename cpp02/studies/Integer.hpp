/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:44:18 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_HPP
# define INTEGER_HPP

#include <iostream>

class Integer {
	public:
		Integer(int const n);
		~Integer(void);

		int	getValue(void) const;

		// operator overloads: operator(operador: =, +, -)
		// assign operador
		// é binário por definição
		// muda o valor de _n, então não é const
		// há um valor passado não explicitamente, que a variável que recebe o valor
		Integer& operator=(Integer const & rhs);
		// apenas a instância atual será retornada
		// c e c++ permitem que façamos algo tipo: a = b = c = d
		// vai da direita para a esquerda, porque precisa fazer isso para retornar
		// o valor de a


		// adittion operator
		// é binário por definição
		// também tem o primeiro parametro passado implicitamente
		// adição não muda os parâmetros, por isso é const
		Integer operator+(Integer const & rhs) const;
		// 1 + 2 + 3 + 4 -> não depende da ordem

	private:
		int	_n;
};

std::ostream& operator<<(std::ostream& o, Integer const& rhs);

#endif

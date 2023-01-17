/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:19 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/17 01:25:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const& src);
		~Fixed(void);
		Fixed& operator=(Fixed const& src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int _nb;
		static const int _fractional_bits;
};

#endif

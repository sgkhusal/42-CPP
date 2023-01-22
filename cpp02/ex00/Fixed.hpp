/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:19 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/20 16:22:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const& fixed);
		~Fixed(void);
		Fixed& operator=(Fixed const& fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int _rawBits;
		static const int _fractional_bits;
};

#endif

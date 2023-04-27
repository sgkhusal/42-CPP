/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:19 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define RED	"\033[38;5;196m"
# define PURPLE	"\033[38;5;200m"
# define YELLOW	"\033[1;33m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const& fixed);
		Fixed(int const integer);
		Fixed(float const f);
		~Fixed(void);
		Fixed& operator=(Fixed const& b);

		bool operator>(Fixed const& b) const;
		bool operator<(Fixed const& b) const;
		bool operator<(float const& b) const;
		bool operator>=(Fixed const& b) const;
		bool operator<=(Fixed const& b) const;
		bool operator==(Fixed const& b) const;
		bool operator!=(Fixed const& b) const;

		Fixed operator+(Fixed const& b) const;
		Fixed operator-(Fixed const& b) const;
		Fixed operator*(Fixed const& b) const;
		Fixed operator/(Fixed const& b) const;
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed const& min(Fixed const& a, Fixed const& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const& max(Fixed const& a, Fixed const& b);

	private:
		int					_rawBits;
		static const int	_fractional_bits;
		static const int	_float_conversion;
};

std::ostream& operator<<(std::ostream& o, Fixed const& fixed);

#endif

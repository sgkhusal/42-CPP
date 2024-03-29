/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:53:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/08 23:07:33 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <limits>
# include <cmath>
# include <iomanip>
# include "utils.hpp"

# define INT_CHARS "0123456789"
# define PRECISION 1
# define FLOAT_PRECISION 7
# define DOUBLE_PRECISION 15

class ScalarConverter {
	public:
		static void convert(char const* value);

	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(ScalarConverter const& scalar);
		ScalarConverter& operator=(ScalarConverter const& scalar);

		static std::string	_str;
		static double		_check;
		typedef enum e_type {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			SPECIAL_CASE,
			INVALID
		}           t_type;

		static t_type _getType(void);
		static int    _getPrecision(t_type const type);

		static void _convertChar(void);
		static void _convertInt(void);
		static void _convertFloat(void);
		static void _convertDouble(void);

		static void _printConversions(char c, int i, float f, double d, int precision);
		static void _printChar(char c);
		static void _printInt(int i);
		static void _printFloat(float f, int precision);
		static void _printDouble(double d, int precision);
		static void _printSpecial(void);
		static void _printType(std::string const& type);

		class NotSupportedTypeException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		static bool   _charOverflow(void);
		static bool   _intOverflow(void);
		static bool   _floatOverflow(void);

		static void _validateInteger(void);
		class IntOverflowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		static void _validateFloat(void);
		class FloatOverflowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif

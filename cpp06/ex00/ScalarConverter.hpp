/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:53:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/05 00:43:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <limits>
# include <iomanip>

# define INT_CHARS "0123456789"
# define PRECISION 1

class ScalarConverter {
    public:
        static void convert(char const* value);

    private:
        ScalarConverter(void);
        ~ScalarConverter(void);
        ScalarConverter(ScalarConverter const& scalar);
        ScalarConverter& operator=(ScalarConverter const& scalar);

        static std::string _str;
        // static std::string _specialDoubles[3];
        // static std::string _specialFloats[3];
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

        static void _printSpecial(void);
        static void _printChar(char c);
        static void _printInt(int i);
        static void _printFloat(float f);
        static void _printDouble(double d);

        class NotSupportedTypeException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif

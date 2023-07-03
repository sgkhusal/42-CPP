/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:53:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/03 09:44:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>

# define INT_CHARS "0123456789"

class ScalarConverter {
    public:
        static void convert(char const* value);

    private:
        ScalarConverter(void);
        ~ScalarConverter(void);
        ScalarConverter(ScalarConverter const& scalar);
        ScalarConverter& operator=(ScalarConverter const& scalar);

        static std::string _specialDoubles[3];
        static std::string _specialFloats[3];
        typedef enum e_type {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            SPECIAL_CASE,
            INVALID
        }           t_type;

        static t_type _getType(char const* value);
        static bool _isChar(std::string const& str);
        static bool _isInt(std::string const& str);
        static bool _isFloat(std::string const& str);
        static bool _isDouble(std::string const& str);
        static bool _isSpecial(std::string const& str);

        static void _convertChar(char const* value);
        static void _convertInt(char const* value);
        static void _convertFloat(char const* value);
        static void _convertDouble(char const* value);

        static void _printConversions(char c, int i, float f, double d);
        static void _printSpecial(char const* value);

        class NotSupportedTypeException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif

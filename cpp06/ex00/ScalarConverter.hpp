/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:53:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/06/28 21:13:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_H
# define SCARLAR_CONVERTER_H

# include <string>

class ScalarConverter {
    public:
        static void convert(char const* type);

    private:
        ScalarConverter(void);
        ~ScalarConverter(void);
        ScalarConverter(ScalarConverter const& scalar);
        ScalarConverter& operator=(ScalarConverter const& scalar);
};

#endif;

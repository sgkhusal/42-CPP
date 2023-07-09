/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 01:05:45 by sguilher          #+#    #+#             */
/*   Updated: 2023/07/09 16:28:03 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:
		Serializer(void);
		~Serializer(void);
		Serializer(Serializer const& serializer);
		Serializer& operator=(Serializer const& serializer);
};

#endif

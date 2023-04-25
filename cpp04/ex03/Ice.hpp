/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:25:07 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/24 23:37:03 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"
# include <iostream>

class Ice: public AMateria {
    public:
        Ice(void);
        Ice(Ice const& ice);
		~Ice(void);
		Ice& operator=(Ice const& ice);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif

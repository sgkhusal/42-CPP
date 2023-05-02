/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:25:07 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/01 20:53:03 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
// # include "ICharacter.hpp"

class Ice: public AMateria {
    public:
        Ice(void);
        Ice(Ice const& ice);
		~Ice(void);
		Ice& operator=(Ice const& ice);

        AMateria* clone(void) const;
        // void use(ICharacter& target);
};

#endif

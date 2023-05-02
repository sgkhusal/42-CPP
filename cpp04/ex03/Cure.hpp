/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:26:10 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/01 21:32:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
// # include "ICharacter.hpp"
# include "tests.hpp"

class Cure: public AMateria {
    public:
        Cure(void);
        Cure(Cure const& cure);
		~Cure(void);
		Cure& operator=(Cure const& cure);

        AMateria* clone(void) const;
        void use(ICharacter& target);

};

#endif

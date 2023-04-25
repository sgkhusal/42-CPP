/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:26:10 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/24 23:34:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"
# include <iostream>

class Cure: public AMateria {
    public:
        Cure(void);
        Cure(Cure const& cure);
		~Cure(void);
		Cure& operator=(Cure const& cure);

        AMateria* clone() const;
        void use(ICharacter& target);

};

#endif

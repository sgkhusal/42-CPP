/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:10:22 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/01 22:18:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string type;

    public:
        AMateria(void);
        AMateria(std::string const & type);
		AMateria(AMateria const& aMateria);
		virtual ~AMateria(void);
		AMateria& operator=(AMateria const& aMateria);

        std::string const & getType(void) const;
        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter& target);
};

#endif

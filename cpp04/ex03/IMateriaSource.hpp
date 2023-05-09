/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:38:40 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/03 20:38:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource {
    public:
        virtual ~IMateriaSource(void) {}
        virtual void learnMateria(AMateria* materia) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif

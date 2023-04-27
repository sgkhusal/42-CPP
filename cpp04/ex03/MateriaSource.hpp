/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:41:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const& materiaSource);
        ~MateriaSource(void);
		MateriaSource& operator=(MateriaSource const& materiaSource);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);

        AMateria* storage[4];
};

#endif
